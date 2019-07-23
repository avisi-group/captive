out := common.a

top-dir := $(CURDIR)
inc-dir := $(top-dir)/include
cpp-inc-dir := $(top-dir)/c++

c-src	:= $(patsubst %,$(top-dir)/%,$(shell find | grep -E "\.c$$"))
cpp-src := $(patsubst %,$(top-dir)/%,$(shell find | grep -E "\.cpp$$"))
as-src	:= $(patsubst %,$(top-dir)/%,$(shell find | grep -E "\.S$$"))
obj := $(c-src:.c=.o) $(cpp-src:.cpp=.o) $(as-src:.S=.o) 
dep := $(c-src:.c=.d) $(cpp-src:.cpp=.d)

export cflags := -I$(inc-dir) $(common-cflags)
export cxxflags := -I$(inc-dir) -I$(cpp-inc-dir) $(common-cflags)
export asflags := -nostdlib -g -mcmodel=large -include $(inc-dir)/config.h

all: $(out)

clean: .FORCE
	$(rm) -f $(out)
	$(rm) -f $(obj)
	$(rm) -f $(dep)

$(out): $(obj)
	@echo "  AR      $(notdir $@)"
	$(q)$(ar) r $@ $(obj)

%.o: %.c
	@echo "  CC      $(notdir $@)"
	$(q)$(cc) -c -o $@ $(cflags) $<

%.o: %.cpp
	@echo "  C++     $(notdir $@)"
	$(q)$(cxx) -c -o $@ $(cxxflags) $<

%.o: %.S
	@echo "  AS      $(notdir $@)"
	$(q)$(cxx) -c -o $@ $(asflags) $<

%.d: %.cpp
	$(q)$(cxx) -M -MT $(@:.d=.o) -o $@ $(cxxflags) $<

%.d: %.c
	$(q)$(cc) -M -MT $(@:.d=.o) -o $@ $(cflags) $<

.FORCE:
.PHONY: $(PHONY) .FORCE

-include $(dep)
