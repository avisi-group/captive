MAKEFLAGS += -rR --no-print-directory
export q := @

top-dir := $(CURDIR)
export cmn-dir := $(top-dir)/common
export cmn-inc-dir := $(cmn-dir)/include
export cmn-cpp-dir := $(cmn-dir)/c++
export cmn-out := $(cmn-dir)/common.a

export make := make
export rm := rm
export cc := gcc
export cxx := g++
export ar := ar
export as := as
export ld := ld

archs := aarch64

arch-outs := $(patsubst %,$(top-dir)/%.arch,$(archs))
arch-cleans := $(patsubst %,$(top-dir)/%.arch.clean,$(archs))

export common-cflags := -I$(shared-dir) -nostdlib -nostdinc -g -fno-builtin -fno-omit-frame-pointer -Wall $(ndebug)
export common-cflags += -include regalloc-pc.h -include config.h
export common-cflags += -mno-mmx -mno-sse -mno-sse2 -mno-sse3 -mno-ssse3 -mno-sse4.1 -mno-sse4.2 -mno-sse4 -mno-avx -mno-aes -mno-sse4a -mno-fma4
export common-cflags += -O3 -mcmodel=kernel -fno-rtti -fno-exceptions -std=gnu++17
export common-cflags += -fno-delete-null-pointer-checks -mno-red-zone -fno-pic -fno-stack-protector -Werror=delete-incomplete
# export common-cflags += -finstrument-functions

all: $(arch-outs)

clean: $(arch-cleans)
	$(q)$(make) -C $(cmn-dir) clean

$(cmn-out): .FORCE
	+$(q)$(make) -C $(cmn-dir)

%.arch: $(cmn-out) .FORCE
	+$(q)$(make) arch-dir=$(basename $@) arch-out=$@ -C $(basename $@)

%.arch.clean: .FORCE
	$(q)$(make) arch-out=$(basename $@) -C $(basename $(basename $@)) clean

.FORCE:
.PHONY: .FORCE
