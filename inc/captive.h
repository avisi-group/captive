/* SPDX-License-Identifier: MIT */
#pragma once

#include <define.h>
#include <iostream>
#include <sstream>
#include <errno.h>
#include <string.h>

namespace captive {
	namespace logging {
		class LogContext;

		extern void configure_logging_contexts();
		extern void register_logging_context(LogContext& ctx);

		class LogContext {
			friend void configure_logging_contexts();

		public:

			explicit LogContext(std::string name) : _parent_name(""), _name(name), _enabled(false), _parent(NULL)
			{
				register_logging_context(*this);
			}

			explicit LogContext(std::string name, std::string parent_name) : _parent_name(parent_name), _name(name), _enabled(false), _parent(NULL)
			{
				register_logging_context(*this);
			}

			inline std::string name() const
			{
				return _name;
			}

			inline std::string parent_name() const
			{
				return _parent_name;
			}

			inline LogContext *parent() const
			{
				return _parent;
			}

			inline bool enabled() const
			{
				return _enabled;
			}

			inline void enable()
			{
				_enabled = true;
			}

			inline void disable()
			{
				_enabled = false;
			}
		private:
			std::string _parent_name;
			std::string _name;
			bool _enabled;

			LogContext *_parent;
		};
	}

	class LogStream : public std::stringstream {
	public:

		explicit LogStream() : _ctx(NULL), _level(LL_DEBUG), _force_enabled(false)
		{
		}

		~LogStream()
		{
			if (_force_enabled || _level >= LL_ERROR || !_ctx || _ctx->enabled()) {
				std::cerr << level_text(_level) << ": " << (_ctx != NULL ? _ctx->name() : "?") << ": " << this->str() << std::endl;
			}
		}

		enum log_level {
			LL_DEBUG,
			LL_INFO,
			LL_WARNING,
			LL_ERROR,
		};

		inline void context(const logging::LogContext& ctx)
		{
			_ctx = &ctx;
		}

		inline void level(log_level new_level)
		{
			_level = new_level;
		}

		inline std::string level_text(log_level lvl) const
		{
			switch (lvl) {
			case LL_DEBUG:
				return "debug";
			case LL_INFO:
				return "info";
			case LL_WARNING:
				return "warning";
			case LL_ERROR:
				return "error";
			default:
				return "?";
			}
		}

		inline void force_enabled(bool enabled)
		{
			_force_enabled = enabled;
		}

	private:
		const logging::LogContext *_ctx;
		log_level _level;
		bool _force_enabled;
	};

	struct __set_level {
		LogStream::log_level level;
	};

	inline __set_level set_level(LogStream::log_level level)
	{
		return { level};
	}

	template<typename _CharT, typename _Traits>
	inline std::basic_ostream<_CharT, _Traits>&
	operator<<(std::basic_ostream<_CharT, _Traits>& __os, __set_level __f)
	{
		((LogStream&) __os).level(__f.level);
		return __os;
	}

	struct __set_context {
		const logging::LogContext& ctx;
	};

	inline __set_context set_context(const logging::LogContext& ctx)
	{
		return { ctx};
	}

	template<typename _CharT, typename _Traits>
	inline std::basic_ostream<_CharT, _Traits>&
	operator<<(std::basic_ostream<_CharT, _Traits>& __os, __set_context __f)
	{
		((LogStream&) __os).context(__f.ctx);
		return __os;
	}

	struct __set_enabled {
		bool enabled;
	};

	inline __set_enabled set_enabled(bool enabled)
	{
		return { enabled};
	}

	template<typename _CharT, typename _Traits>
	inline std::basic_ostream<_CharT, _Traits>&
	operator<<(std::basic_ostream<_CharT, _Traits>& __os, __set_enabled __f)
	{
		((LogStream&) __os).force_enabled(__f.enabled);
		return __os;
	}
}

/*#ifdef NDEBUG
#define LOG() while (0) captive::LogStream()
#else*/
#define LOG() captive::LogStream()
//#endif

#define DEBUG LOG() << captive::set_level(captive::LogStream::LL_DEBUG)
#define INFO LOG() << captive::set_level(captive::LogStream::LL_INFO)
#define ERROR LOG() << captive::set_level(captive::LogStream::LL_ERROR)
#define WARNING LOG() << captive::set_level(captive::LogStream::LL_WARNING)

#define CONTEXT(_ctx) captive::set_context(captive::logging::LogContext##_ctx)
#define ENABLE captive::set_enabled(true)
#define DISABLE captive::set_enabled(false)

#define ___STR(a) #a
#define __STR(a) ___STR(a)
#define DECLARE_CONTEXT(_ctx) namespace captive { namespace logging { __attribute__((init_priority(210))) LogContext LogContext##_ctx(#_ctx); } }
#define DECLARE_CHILD_CONTEXT(_child, _parent) namespace captive { namespace logging { __attribute__((init_priority(210))) LogContext LogContext##_child(#_child, #_parent); } }
#define USE_CONTEXT(_ctx) namespace captive { namespace logging { extern LogContext LogContext##_ctx; } }

#define LAST_ERROR_TEXT strerror(errno)
