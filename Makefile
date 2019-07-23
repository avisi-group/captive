MAKEFLAGS += -rR --no-print-directory
export q := @

top-dir := $(CURDIR)
src-dir := $(top-dir)/src
inc-dir := $(top-dir)/inc
bin-dir := $(top-dir)/bin
arch-dir := $(top-dir)/arch

export shared-dir := $(top-dir)/shared

out := $(bin-dir)/captive
src := $(patsubst src/%,$(src-dir)/%,$(shell find src/ | grep -e "\.cpp$$"))
obj := $(src:.cpp=.o)
dep := $(src:.cpp=.d)

export ndebug := 
	#-DNDEBUG

common-cflags := -I$(inc-dir) -I$(shared-dir) -g -Wall -O3 -pthread $(ndebug)
cflags   := $(common-cflags)
cxxflags := $(common-cflags) -std=gnu++17
asflags  := -g
ldflags  := -pthread -Wl,--no-as-needed -ldl -lrt

cc  := gcc
cxx := g++
as  := as
ld  := ld
rm  := rm
make := +make

all: $(out) .FORCE
	$(q)$(make) -C $(arch-dir)

clean: .FORCE
	$(q)$(make) -C $(arch-dir) clean
	$(rm) -f $(obj)
	$(rm) -f $(dep)
	$(rm) -f $(out)

$(out): $(dep) $(obj) $(bin-dir)
	@echo "  LD      $(patsubst $(bin-dir)/%,%,$@)"
	$(q)$(cxx) -o $@ $(ldflags) $(obj)

$(bin-dir):
	@mkdir $@

%.o: %.cpp
	@echo "  C++     $(patsubst $(src-dir)/%,%,$@)"
	$(q)$(cxx) -c -o $@ $(cxxflags) $<

%.o: %.S
	@echo "  AS      $(patsubst $(src-dir)/%,%,$@)"
	$(q)$(as) -o $@ $(asflags) $<

%.d: %.cpp
	$(q)$(cxx) -M -MT $(@:.d=.o) -o $@ $(cxxflags) $<

.FORCE:
.PHONY: $(PHONY) .FORCE

-include $(dep)
