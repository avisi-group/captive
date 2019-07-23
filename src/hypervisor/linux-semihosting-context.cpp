/* SPDX-License-Identifier: MIT */

#include <hypervisor/linux-semihosting-context.h>
#include <loader/loader.h>
#include <loader/elf-loader.h>
#include <util/config/config.h>

#include <cstring>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/termios.h>

using namespace captive::hypervisor;

//#define PRDEBUG

#ifdef PRDEBUG
#define DPRINTF(a, b...) fprintf(stderr, "%s: " a, __func__, b)
#else
#define DPRINTF(a...)
#endif

LinuxSemihostingContext::LinuxSemihostingContext(Guest& guest, const util::config::Configuration& cfg, const loader::KernelLoader *kernel) : SemihostingContext(guest), _cfg(cfg), _kernel(kernel), _initial_brk(0), _brk(0)
{
	register_filedescriptor_at(0, new MappedFileDescriptor(0, true, false));
	register_filedescriptor_at(1, new MappedFileDescriptor(1, true, false));
	register_filedescriptor_at(2, new MappedFileDescriptor(2, false, false));
}

bool LinuxSemihostingContext::init()
{
	if (auto elf_loader = dynamic_cast<const captive::loader::ELFLoader *>(_kernel)) {
		_initial_brk = (elf_loader->end_of_loaded_data() + 4096) & ~0xfff;
		_brk = _initial_brk;
		
		fprintf(stderr, "initial brk: %lx\n", _initial_brk);
	}
	
	return true;
}


int LinuxSemihostingContext::FileDescriptor::close()
{
	return -1;
}

int LinuxSemihostingContext::FileDescriptor::stat(struct stat *st, size_t size)
{
	return -1;
}

int LinuxSemihostingContext::FileDescriptor::statat(const std::string& path, struct stat* st, int flag)
{
	return -1;
}

int LinuxSemihostingContext::FileDescriptor::ioctl(uintptr_t gpm, int request, unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3)
{
	return -1;
}

int LinuxSemihostingContext::FileDescriptor::read(void *buffer, size_t size)
{
	return -1;
}

int LinuxSemihostingContext::FileDescriptor::write(const void *buffer, size_t size)
{
	return -1;
}

int LinuxSemihostingContext::FileDescriptor::lseek(unsigned long int offset, int whence)
{
	return -1;
}

int LinuxSemihostingContext::FileDescriptor::fcntl(unsigned long int a0, unsigned long int a1, unsigned long int a2, unsigned long int a3)
{
	return -1;
}

int LinuxSemihostingContext::MappedFileDescriptor::write(const void *buffer, size_t size)
{
	int rc = ::write(_host_fd, buffer, size);
	
	if (rc < 0) {
		return -errno;
	}
	
	if (_auto_flush) {
		::fsync(_host_fd);
	}
	
	return rc;
}

int LinuxSemihostingContext::MappedFileDescriptor::read(void *buffer, size_t size)
{
	int rc = ::read(_host_fd, buffer, size);
	
	if (rc < 0) {
		return -errno;
	}
	
	return rc;
}

int LinuxSemihostingContext::MappedFileDescriptor::lseek(unsigned long int offset, int whence)
{
	if (::lseek(_host_fd, offset, whence) < 0) {
		return -errno;
	}
	
	return 0;
}


int LinuxSemihostingContext::MappedFileDescriptor::close()
{
	if (_really_close) {
		if (::close(_host_fd) < 0) {
			return -errno;
		}
	}
	
	return 0;
}

int LinuxSemihostingContext::MappedFileDescriptor::ioctl(uintptr_t gpm, int request, unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3)
{
	switch (request) {
	case 0x5401: {
		struct termios host;
		if (::ioctl(_host_fd, 0x5401, &host) < 0) return -errno;
		
		//::memcpy((void *)(gpm + arg0), &host, sizeof(host));
		
		/*struct aarch64_termios {
			
		} *termios = (struct aarch64_termios *)arg0;*/
		
		return 0;
	}
	default:
		return -1;
	}
}

int LinuxSemihostingContext::MappedFileDescriptor::fcntl(unsigned long int a0, unsigned long int a1, unsigned long int a2, unsigned long int a3)
{
	if (::fcntl(_host_fd, a0, a1, a2, a3) < 0) {
		return -errno;
	}
	
	return 0;
}

int LinuxSemihostingContext::MappedFileDescriptor::stat(struct stat *st, size_t size)
{
	if (::fstat(_host_fd, st) < 0) {
		return -errno;
	}
	
	return 0;
}

int LinuxSemihostingContext::MappedFileDescriptor::statat(const std::string& path, struct stat *st, int flag)
{
	if (::fstatat(_host_fd, path.c_str(), st, flag) < 0) {
		return -errno;
	}
	
	return 0;
}

int LinuxSemihostingContext::ScalarDataFileDescriptor::read(void *buffer, size_t size)
{
	unsigned int end_ptr = _ptr + size;
	if (end_ptr > _data.size()) {
		end_ptr = _data.size();
	}
	
	void *data_ptr = (void *)((uintptr_t)_data.c_str() + _ptr);
	
	size_t amount = end_ptr - _ptr;
	::memcpy(buffer, data_ptr, amount);
	_ptr += amount;
	return amount;
}

int LinuxSemihostingContext::ScalarDataFileDescriptor::close()
{
	return 0;
}

uint64_t LinuxSemihostingContext::handle_uname(uintptr_t gpm, uint64_t buf, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5)
{
	DPRINTF("buf=%p\n", buf);
	
	struct aarch64_utsname {
		char sysname[64];
		char nodename[64];
		char release[64];
		char version[64];
		char machine[64];
		char domainname[64];
	} *utsname = (aarch64_utsname *)(gpm + buf);
	
	strcpy(utsname->sysname, "Linux");
	strcpy(utsname->nodename, "captive");
	strcpy(utsname->release, "4.8.0");
	strcpy(utsname->version, "#1");
	strcpy(utsname->machine, "arm64");
	
	return 0;
}

uint64_t LinuxSemihostingContext::handle_openat(uintptr_t gpm, uint64_t dirfd, uint64_t pathname, uint64_t flags, uint64_t mode, uint64_t a4, uint64_t a5)
{
	const std::string requested_path = read_user_string(gpm, pathname);
	DPRINTF("path=%s\n", requested_path.c_str());
	
	if ((int)dirfd != -100) return -1;
	
	if (requested_path == "/proc/sys/kernel/osrelease") {
		return register_filedescriptor(new ScalarDataFileDescriptor("4.8.0"));
	} else {
		int fd = ::open(requested_path.c_str(), flags, mode);
		if (fd < 0) return -errno;
		
		return register_filedescriptor(new MappedFileDescriptor(fd, false, true));
	}
}

uint64_t LinuxSemihostingContext::handle_close(uintptr_t gpm, uint64_t fdnum, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5)
{
	DPRINTF("fd=%d\n", fdnum);
	
	if (fdmap.count(fdnum) == 0) return -1;
	
	FileDescriptor *fd = fdmap[fdnum];
	fdmap.erase(fdnum);
	
	int rc = fd->close();
	if (rc == 0) {
		delete fd;
	}
	
	return rc;
}

uint64_t LinuxSemihostingContext::handle_dup(uintptr_t gpm, uint64_t fdnum, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5)
{
	DPRINTF("dup=%d\n", fdnum);
	
	if (fdmap.count(fdnum) == 0) return -1;
	
	MappedFileDescriptor *fd_to_dup = dynamic_cast<MappedFileDescriptor *>(fdmap[fdnum]);
	if (fd_to_dup == nullptr) return -1;
	
	int new_fd = ::dup(fd_to_dup->host_fd());
	return register_filedescriptor(new MappedFileDescriptor(new_fd, false, true));
}

uint64_t LinuxSemihostingContext::handle_lseek(uintptr_t gpm, uint64_t fdnum, uint64_t offset, uint64_t whence, uint64_t a3, uint64_t a4, uint64_t a5)
{
	DPRINTF("fd=%d, offset=%lu, whence=%u\n", fdnum, offset, whence);
	
	FileDescriptor *fd = lookup_filedescriptor(fdnum);
	if (fd == nullptr) return -1;
	
	return fd->lseek(offset, whence);
}

uint64_t LinuxSemihostingContext::handle_read(uintptr_t gpm, uint64_t fdnum, uint64_t buffer, uint64_t size, uint64_t a3, uint64_t a4, uint64_t a5)
{
	DPRINTF("fd=%d, buffer=%p, size=%u\n", fdnum, buffer, size);
	
	FileDescriptor *fd = lookup_filedescriptor(fdnum);
	if (fd == nullptr) return -1;	
	
	return fd->read((void *)(gpm + buffer), size);
}

uint64_t LinuxSemihostingContext::handle_write(uintptr_t gpm, uint64_t fdnum, uint64_t buffer, uint64_t size, uint64_t a3, uint64_t a4, uint64_t a5)
{
	DPRINTF("fd=%d, buffer=%p, size=%u\n", fdnum, buffer, size);
	
	FileDescriptor *fd = lookup_filedescriptor(fdnum);
	if (fd == nullptr) return -1;	

	return fd->write((const void *)(gpm + buffer), size);
}

uint64_t LinuxSemihostingContext::handle_writev(uintptr_t gpm, uint64_t fdnum, uint64_t iovptr, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5)
{
	DPRINTF("fd=%d, iov=%p\n", fdnum, iovptr);
	
	FileDescriptor *fd = fdmap.at(fdnum);
	
	struct aarch64_iovec {
		uint64_t iov_base;
		uint64_t iov_len;
	} *iov = (aarch64_iovec *)(gpm + iovptr);
	
	DPRINTF("iov->iov_base = %lx, iov->iov_len = %lx\n", iov->iov_base, iov->iov_len);
	return fd->write((const void *)(gpm + iov->iov_base), iov->iov_len);
}

uint64_t LinuxSemihostingContext::handle_brk(uintptr_t gpm, uint64_t new_brk, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5)
{
	DPRINTF("old-brk=%lx, new-brk=%lx\n", _brk, new_brk);
	
	if (new_brk >= _initial_brk) _brk = new_brk;
	return _brk;
}

uint64_t LinuxSemihostingContext::handle_geteuid(uintptr_t gpm, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5)
{
	return 0;
}

uint64_t LinuxSemihostingContext::handle_getpid(uintptr_t gpm, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5)
{
	return 1000;
}

uint64_t LinuxSemihostingContext::handle_gettid(uintptr_t gpm, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5)
{
	return 1;
}

uint64_t LinuxSemihostingContext::handle_readlinkat(uintptr_t gpm, uint64_t dirfd, uint64_t pathname, uint64_t buf, uint64_t bufsiz, uint64_t a4, uint64_t a5)
{
	const std::string requested_path = read_user_string(gpm, pathname);
	
	DPRINTF("fd=%d, path=%s (%p), buf=%p, bufsiz=%x\n", dirfd, requested_path.c_str(), pathname, buf, bufsiz);
	
	if (requested_path == "/proc/self/exe") {
		// TODO return write_user_string(gpm, buf, bufsiz, "/home/a.out");
		
		if (auto fbl = dynamic_cast<const loader::FileBasedLoader *>(_kernel)) {
			return write_user_string(gpm, buf, bufsiz, fbl->filename());
		} else {
			return write_user_string(gpm, buf, bufsiz, "/bin/true");
		}
	}
	
	return -1;
}

uint64_t LinuxSemihostingContext::handle_fstatat(uintptr_t gpm, uint64_t fdnum, uint64_t pathname, uint64_t buf, uint64_t flag, uint64_t a4, uint64_t a5)
{
	const std::string requested_path = read_user_string(gpm, pathname);
	
	DPRINTF("fstatat=%d, path=%s (%p), buf=%p, flag=%x\n", fdnum, requested_path.c_str(), pathname, buf, flag);
	
	struct stat st;
	if ((int)fdnum < 0) {
		if (::fstatat(fdnum, requested_path.c_str(), &st, flag) < 0) {
			return -errno;
		}
	} else {
		auto fd = lookup_filedescriptor(fdnum);
		if (fd == nullptr) return -1;
	
		int rc = fd->statat(requested_path, &st, flag);
		if (rc < 0) {
			return rc;
		}
	}
	
	struct aarch64_stat {
		uint64_t z_st_dev;
		uint64_t z_st_ino;
		uint32_t z_st_mode;
		uint32_t z_st_nlink;
		uint32_t z_st_uid;
		uint32_t z_st_gid;
		uint64_t z_st_rdev;
		uint64_t __pad1;
		int64_t z_stz_size;
		int32_t z_stz_blksize;
		int32_t __pad2;
		int64_t z_st_blocks;
		int64_t z_st_atime;
		uint64_t z_st_atime_nsec;
		int64_t z_st_mtime;
		uint64_t z_st_mtime_nsec;
		int64_t z_st_ctime;
		uint64_t z_st_ctime_nsec;
		uint32_t __unused4;
		uint32_t __unused5;
	} *stat = (aarch64_stat *)(gpm + buf);
	
	::bzero(stat, sizeof(*stat));
	stat->z_st_dev = st.st_dev;
	stat->z_st_ino = st.st_ino;
	stat->z_st_mode = st.st_mode;
	stat->z_st_nlink = st.st_nlink;
	stat->z_st_uid = st.st_uid;
	stat->z_st_gid = st.st_gid;
	stat->z_st_rdev = st.st_rdev;
	stat->z_stz_size = st.st_size;
	stat->z_stz_blksize = st.st_blksize;
	stat->z_st_blocks = st.st_blocks;
	stat->z_st_atime = st.st_atim.tv_sec;
	stat->z_st_atime_nsec = st.st_atim.tv_nsec;
	stat->z_st_mtime = st.st_mtim.tv_sec;
	stat->z_st_mtime_nsec = st.st_mtim.tv_nsec;
	stat->z_st_ctime = st.st_ctim.tv_sec;
	stat->z_st_ctime_nsec = st.st_ctim.tv_nsec;

	return 0;
}

uint64_t LinuxSemihostingContext::handle_mmap(uintptr_t gpm, uint64_t addr, uint64_t length, uint64_t prot, uint64_t flags, uint64_t fd, uint64_t off)
{
	DPRINTF("addr=%lx, length=%lx, prot=%u, flags=%u, fd=%d, offset=%lx\n", addr, length, prot, flags, fd, off);
	
	if (flags & MAP_ANON) {
		if (length == 0) return -1;
		if ((length & 0xfff) != 0) return -1;
		
		auto vma = new VMA();
		vma->size = length;
		vma->prot = prot;
		vma->flags = flags;
		
		uint64_t pfn = 0xc0000000 >> 12;
		auto last = mmaps.rbegin();
		if (last != mmaps.rend()) {
			pfn = last->first + (last->second->size >> 12);
		}
		
		DPRINTF("anonymous mapping length=%lx, pfn=%lx\n", length, pfn);
		
		void *gpm_base = (void *)(gpm + (pfn << 12));
		::mmap(gpm_base, length, prot, MAP_ANON | MAP_FIXED | MAP_PRIVATE, -1, 0);
		
		//zero_guest_pages(gpm, pfn, (length / 4096));
		
		mmaps[pfn] = vma;
		return pfn << 12;
	} else {
		return -1;
	}
}

uint64_t LinuxSemihostingContext::handle_munmap(uintptr_t gpm, uint64_t addr, uint64_t length, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5)
{
	auto vmai = mmaps.find(addr >> 12);
	if (vmai == mmaps.end()) return -1;
	
	VMA *vma = vmai->second;
	
	if (length != vma->size) return -1;
	
	mmaps.erase(vmai);
	delete vma;
	
	return 0;
}

uint64_t LinuxSemihostingContext::handle_mremap(uintptr_t gpm, uint64_t old_address, uint64_t old_size, uint64_t new_size, uint64_t flags, uint64_t new_address, uint64_t a5)
{
	auto vmai = mmaps.find(old_address >> 12);
	if (vmai == mmaps.end()) return -1;
	
	VMA *vma = vmai->second;
	
	if (old_size != vma->size) return -1;
	
	if (new_size < old_size) {
		vma->size = new_size;
		return old_address;
	} else if (new_size > old_size) {
		return -1;
	}
		
	return -1;
}

uint64_t LinuxSemihostingContext::handle_fstat(uintptr_t gpm, uint64_t fdnum, uint64_t buf, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5)
{
	DPRINTF("fd=%d, buf=%lx\n", fdnum, buf);
	
	auto fd = lookup_filedescriptor(fdnum);
	if (fd == nullptr) return -1;
	
	struct stat st;
	int rc = fd->stat(&st, sizeof(st));
	if (rc < 0) {
		return rc;
	}
	
	struct aarch64_stat {
		uint64_t z_st_dev;
		uint64_t z_st_ino;
		uint32_t z_st_mode;
		uint32_t z_st_nlink;
		uint32_t z_st_uid;
		uint32_t z_st_gid;
		uint64_t z_st_rdev;
		uint64_t __pad1;
		int64_t z_stz_size;
		int32_t z_stz_blksize;
		int32_t __pad2;
		int64_t z_st_blocks;
		int64_t z_st_atime;
		uint64_t z_st_atime_nsec;
		int64_t z_st_mtime;
		uint64_t z_st_mtime_nsec;
		int64_t z_st_ctime;
		uint64_t z_st_ctime_nsec;
		uint32_t __unused4;
		uint32_t __unused5;
	} *stat = (aarch64_stat *)(gpm + buf);
	
	::bzero(stat, sizeof(*stat));
	stat->z_st_dev = st.st_dev;
	stat->z_st_ino = st.st_ino;
	stat->z_st_mode = st.st_mode;
	stat->z_st_nlink = st.st_nlink;
	stat->z_st_uid = st.st_uid;
	stat->z_st_gid = st.st_gid;
	stat->z_st_rdev = st.st_rdev;
	stat->z_stz_size = st.st_size;
	stat->z_stz_blksize = st.st_blksize;
	stat->z_st_blocks = st.st_blocks;
	stat->z_st_atime = st.st_atim.tv_sec;
	stat->z_st_atime_nsec = st.st_atim.tv_nsec;
	stat->z_st_mtime = st.st_mtim.tv_sec;
	stat->z_st_mtime_nsec = st.st_mtim.tv_nsec;
	stat->z_st_ctime = st.st_ctim.tv_sec;
	stat->z_st_ctime_nsec = st.st_ctim.tv_nsec;
	
	return 0;
}

uint64_t LinuxSemihostingContext::handle_tgkill(uintptr_t gpm, uint64_t tgid, uint64_t tid, uint64_t sig, uint64_t arg1, uint64_t arg2, uint64_t arg3)
{
	DPRINTF("tgid=%lu tid=%lu sig=%lu\n", tgid, tid, sig);
	
	return 0;
}

uint64_t LinuxSemihostingContext::handle_ioctl(uintptr_t gpm, uint64_t fdnum, uint64_t req, uint64_t arg0, uint64_t arg1, uint64_t arg2, uint64_t arg3)
{
	DPRINTF("fd=%d, req=%lx, arg0=%lx\n", fdnum, req, arg0);
	
	auto fd = lookup_filedescriptor(fdnum);
	if (fd == nullptr) return -1;

	return fd->ioctl(gpm, req, arg0, arg1, arg2, arg3);
}

uint64_t LinuxSemihostingContext::handle_fcntl(uintptr_t gpm, uint64_t fdnum, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5)
{
	DPRINTF("fd=%d, arg0=%lx\n", fdnum, a1);
	
	auto fd = lookup_filedescriptor(fdnum);
	if (fd == nullptr) return -1;

	return fd->fcntl(a1, a2, a3, a4);
}

uint64_t LinuxSemihostingContext::handle_rt_sigaction(uintptr_t gpm, uint64_t fdnum, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5)
{
	return 0;
}

uint64_t LinuxSemihostingContext::handle_chdir(uintptr_t gpm, uint64_t pathname, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5)
{
	const std::string requested_path = read_user_string(gpm, pathname);
	
	if (::chdir(requested_path.c_str())) {
		return 0;
	}
	
	return -errno;
}

uint64_t LinuxSemihostingContext::handle_pipe2(uintptr_t gpm, uint64_t fds, uint64_t flags, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5)
{
	int native_pipe[2];
	
	if (::pipe2(native_pipe, flags)) {
		return -errno;
	}
	
	int *pipe_fds = (int *)(gpm + fds);
	pipe_fds[0] = register_filedescriptor(new MappedFileDescriptor(native_pipe[0], false, true));
	pipe_fds[1] = register_filedescriptor(new MappedFileDescriptor(native_pipe[1], false, true));

	return 0;	
}

uint64_t LinuxSemihostingContext::handle_getcwd(uintptr_t gpm, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5)
{
	write_user_string(gpm, a0, a1, ::getcwd(nullptr, 0));
	return 0;
}


////

#ifdef PRDEBUG
#define SYSCALL(__nr, __name) case __nr: \
fprintf(stderr, "* " #__name "(%lx, %lx, %lx, %lx, %lx, %lx)\n", data.arguments[8], data.arguments[9], data.arguments[10], data.arguments[11], data.arguments[12], data.arguments[13]); \
data.result = handle_##__name((uintptr_t)gpm, data.arguments[8], data.arguments[9], data.arguments[10], data.arguments[11], data.arguments[12], data.arguments[13]); \
break;
#else
#define SYSCALL(__nr, __name) case __nr: \
data.result = handle_##__name((uintptr_t)gpm, data.arguments[8], data.arguments[9], data.arguments[10], data.arguments[11], data.arguments[12], data.arguments[13]); \
break;
#endif

bool LinuxSemihostingContext::handle_semihosting_call(SemihostingCallData& data)
{
	if (data.call_nr == 1) return false;
	
	void *gpm;
	if (!guest().resolve_gpa(0, gpm)) {
		return false;
	}
	
	switch (data.arguments[14]) {
	SYSCALL(17, getcwd)
	SYSCALL(23, dup)
	SYSCALL(25, fcntl)
	SYSCALL(29, ioctl)
	SYSCALL(49, chdir)
	SYSCALL(56, openat)
	SYSCALL(57, close)
	SYSCALL(59, pipe2)
	SYSCALL(62, lseek)
	SYSCALL(63, read)
	SYSCALL(64, write)
	SYSCALL(66, writev)
	SYSCALL(78, readlinkat)
	SYSCALL(79, fstatat)
	SYSCALL(80, fstat)
	SYSCALL(131, tgkill)	
	SYSCALL(134, rt_sigaction)	
	SYSCALL(160, uname)	
	SYSCALL(172, getpid)		// getpid
	SYSCALL(174, geteuid)		// getuid
	SYSCALL(175, geteuid)		// geteuid
	SYSCALL(176, geteuid)		// getgid
	SYSCALL(177, geteuid)		// getegid
	SYSCALL(178, gettid)		// gettid
	SYSCALL(214, brk)
	SYSCALL(215, munmap)
	SYSCALL(216, mremap)
	SYSCALL(222, mmap)
	default: printf("*** UNHANDLED LINUX SEMIHOSTING %lu, x8=%lu\n", data.call_nr, data.arguments[14]); data.result = -1; break;
	}

#ifdef PRDEBUG
	fprintf(stderr, "* result=%lx -- pc=%p\n", data.result, data.arguments[15]);
#endif
	
	return true;
}

const std::string LinuxSemihostingContext::read_user_string(uintptr_t gpm, uint64_t addr)
{
	void *ptr = (void *)(gpm + addr);
	return std::string((const char *)ptr);
}

int LinuxSemihostingContext::write_user_string(uintptr_t gpm, uint64_t addr, uint64_t limit, const std::string& str)
{
	void *ptr = (void *)(gpm + addr);
	strncpy((char *)ptr, str.c_str(), limit);
	
	//fprintf(stderr, "writing '%s' %d\n", str.c_str(), str.size());
	
	return str.size() >= limit ? limit : str.size() + 1;
}

int LinuxSemihostingContext::register_filedescriptor_at(int fdnum, FileDescriptor* fd)
{
	assert(!fdmap.count(fdnum));
	
#ifdef PRDEBUG
	fprintf(stderr, "* REGISTERING FD %d\n", fdnum);
#endif
	
	fdmap[fdnum] = fd;
	return fdnum;
}

int LinuxSemihostingContext::register_filedescriptor(FileDescriptor* fd)
{
	const auto& e = fdmap.rbegin();
	return register_filedescriptor_at(e->first + 1, fd);
}

LinuxSemihostingContext::FileDescriptor* LinuxSemihostingContext::lookup_filedescriptor(int fdnum)
{
	auto f = fdmap.find(fdnum);
	if (f == fdmap.end()) return nullptr;
	return f->second;
}

void LinuxSemihostingContext::zero_guest_pages(uintptr_t gpm, uint64_t pfn, uint64_t count)
{
	uint8_t *base = ((uint8_t *)gpm) + (pfn * 4096llu);
	
	//fprintf(stderr, "*** ABOUT TO ZERO GUEST MEMORY @ %p pfn=%lu count=%lu\n", base, pfn, count);
	bzero(base, count * 4096llu);
	//fprintf(stderr, "ZEROED GUEST MEMORY\n");
}
