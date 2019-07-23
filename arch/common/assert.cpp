/* SPDX-License-Identifier: MIT */

#pragma GCC diagnostic ignored "-Wtrigraphs"

#include <define.h>
#include <assert.h>
#include <printf.h>
#include <x86/fpu.h>

static const char *resolve_symbol(uint64_t sym)
{
	return "<???>";
}

static inline void print_symbol(uint64_t sym)
{
	asm volatile("out %0, $0xff\n" ::"a"(13), "D"(sym));
}

void dump_code(unsigned long int rip)
{
	rip &= ~0xfULL;

	printf("Code @ %p:\n", rip);

	uint8_t *p = (uint8_t *) rip;
	for (int i = 0; i < 0x100; i++) {
		if (i % 16 == 0) printf("\n%p: ", &p[i]);

		printf("%02x ", p[i]);
	}
	printf("\n");
}

void dump_mcontext(const struct mcontext *mctx)
{
	printf("machine context:\n");
	printf("  rax = %016lx\n", mctx->rax);
	printf("  rbx = %016lx\n", mctx->rbx);
	printf("  rcx = %016lx\n", mctx->rcx);
	printf("  rdx = %016lx\n", mctx->rdx);
	printf("  rsi = %016lx\n", mctx->rsi);
	printf("  rdi = %016lx\n", mctx->rdi);
	printf("  r8  = %016lx\n", mctx->r8);
	printf("  r9  = %016lx\n", mctx->r9);
	printf("  r10 = %016lx\n", mctx->r10);
	printf("  r11 = %016lx\n", mctx->r11);
	printf("  r12 = %016lx\n", mctx->r12);
	printf("  r13 = %016lx\n", mctx->r13);
	printf("  r14 = %016lx\n", mctx->r14);
	printf("  r15 = %016lx\n", mctx->r15);
	printf("  rsp = %016lx\n", 0);
	printf("  rbp = %016lx\n", mctx->rbp);
	printf("  rip = %016lx\n", mctx->rip);
	printf("  rflags = %016lx\n", mctx->flags);

	captive::arch::x86::FPU::dump_state();
}

static char xsave_area[512] __attribute__((aligned(64)));

void dump_sse()
{
	asm volatile("xsave64 %0" ::"m"(xsave_area), "a"(3), "d"(0));

	printf("sse context:\n");
	for (int sseRegisterIndex = 0; sseRegisterIndex < 16; sseRegisterIndex++) {
		void *sseRegisterBase = &xsave_area[160 + (sseRegisterIndex * 16)];
		printf("  xmm%u = %016lx\n", sseRegisterIndex, *(uint64_t *) sseRegisterBase);
	}
}

void dump_stack()
{
	int count = 0;

	printf("Stack Frame:\n");

	uint64_t bp;
	asm volatile("mov %%rbp, %0\n" : "=r"(bp));

	int frame_idx = 0;
	while (bp != 0 && count++ < 100) {
		uint64_t *stack = (uint64_t *) bp;
		printf("  %d: %lx: ", frame_idx++, stack[1]);
		print_symbol(stack[1]);
		bp = stack[0];
	}
}

void __assertion_failure(const char *filename, int lineno, const char *expression)
{
	printf("ABORT: ASSERTION FAILED: <%s> in %s:%d\n", expression, filename, lineno);

	dump_stack();
	asm volatile("out %0, $0xff\n" ::"a"(3));

	__builtin_unreachable();
}
