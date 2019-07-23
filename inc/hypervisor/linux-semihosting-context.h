/* SPDX-License-Identifier: MIT */
#pragma once

#include <hypervisor/semihosting-context.h>
#include <map>

struct stat;

namespace captive {
	namespace util {
		namespace config {
			class Configuration;
		}
	}

	namespace loader {
		class KernelLoader;
	}

	namespace hypervisor {

		class LinuxSemihostingContext : public SemihostingContext {
		public:
			LinuxSemihostingContext(Guest& guest, const util::config::Configuration& cfg, const loader::KernelLoader *kernel);

			bool init() override;
			bool handle_semihosting_call(SemihostingCallData& data) override;

		private:
			const util::config::Configuration& _cfg;
			const loader::KernelLoader *_kernel;

			class FileDescriptor {
			public:

				FileDescriptor()
				{
				}

				virtual ~FileDescriptor()
				{
				}

				virtual int lseek(unsigned long int offset, int whence);
				virtual int write(const void *buffer, size_t size);
				virtual int read(void *buffer, size_t size);

				virtual int close();

				virtual int stat(struct stat *st, size_t size);
				virtual int statat(const std::string& path, struct stat *st, int flag);
				virtual int ioctl(uintptr_t gpm, int request, unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3);
				virtual int fcntl(unsigned long int a0, unsigned long int a1, unsigned long int a2, unsigned long int a3);
			};

			class MappedFileDescriptor : public FileDescriptor {
			public:

				MappedFileDescriptor(int host_fd, bool auto_flush, bool really_close) : _host_fd(host_fd), _auto_flush(auto_flush), _really_close(really_close)
				{
				}

				int write(const void *buffer, size_t size) override;
				int read(void *buffer, size_t size) override;
				int close() override;
				int ioctl(uintptr_t gpm, int request, unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3) override;
				int stat(struct stat *st, size_t size) override;
				int statat(const std::string& path, struct stat *st, int flag) override;
				int lseek(unsigned long int offset, int whence) override;
				int fcntl(unsigned long int a0, unsigned long int a1, unsigned long int a2, unsigned long int a3) override;

				int host_fd() const
				{
					return _host_fd;
				}

			private:
				int _host_fd;
				bool _auto_flush, _really_close;
			};

			class ScalarDataFileDescriptor : public FileDescriptor {
			public:

				ScalarDataFileDescriptor(const std::string& data) : _data(data), _ptr(0)
				{
				}

				int read(void* buffer, size_t size) override;
				int close() override;

			private:
				const std::string _data;
				int _ptr;
			};

			/*class Pipe {
			public:
				Pipe(FileDescriptor *read, FileDescriptor *write)
			};*/

			class VMA {
			public:
				uint64_t size;
				uint32_t prot, flags;
			};

			uint64_t _initial_brk, _brk;
			std::map<int, FileDescriptor *> fdmap;
			std::map<uint64_t, VMA *> mmaps;

			uint64_t handle_uname(uintptr_t gpm, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5);
			uint64_t handle_openat(uintptr_t gpm, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5);
			uint64_t handle_close(uintptr_t gpm, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5);
			uint64_t handle_dup(uintptr_t gpm, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5);
			uint64_t handle_lseek(uintptr_t gpm, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5);
			uint64_t handle_read(uintptr_t gpm, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5);
			uint64_t handle_writev(uintptr_t gpm, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5);
			uint64_t handle_brk(uintptr_t gpm, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5);
			uint64_t handle_geteuid(uintptr_t gpm, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5);
			uint64_t handle_readlinkat(uintptr_t gpm, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5);
			uint64_t handle_fstatat(uintptr_t gpm, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5);
			uint64_t handle_mmap(uintptr_t gpm, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5);
			uint64_t handle_munmap(uintptr_t gpm, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5);
			uint64_t handle_mremap(uintptr_t gpm, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5);
			uint64_t handle_fstat(uintptr_t gpm, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5);
			uint64_t handle_ioctl(uintptr_t gpm, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5);
			uint64_t handle_write(uintptr_t gpm, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5);
			uint64_t handle_getpid(uintptr_t gpm, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5);
			uint64_t handle_gettid(uintptr_t gpm, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5);
			uint64_t handle_tgkill(uintptr_t gpm, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5);
			uint64_t handle_fcntl(uintptr_t gpm, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5);
			uint64_t handle_rt_sigaction(uintptr_t gpm, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5);
			uint64_t handle_chdir(uintptr_t gpm, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5);
			uint64_t handle_pipe2(uintptr_t gpm, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5);
			uint64_t handle_getcwd(uintptr_t gpm, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5);

			int register_filedescriptor_at(int fdnum, FileDescriptor *fd);
			int register_filedescriptor(FileDescriptor *fd);
			FileDescriptor *lookup_filedescriptor(int fdnum);
			const std::string read_user_string(uintptr_t gpm, uint64_t addr);
			int write_user_string(uintptr_t gpm, uint64_t addr, uint64_t limit, const std::string& str);
			void zero_guest_pages(uintptr_t gpm, uint64_t pfn, uint64_t count);
		};
	}
}
