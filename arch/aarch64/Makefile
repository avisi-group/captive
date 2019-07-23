top-dir := $(CURDIR)
local-inc-dir := $(top-dir)/include

src := $(patsubst %,$(top-dir)/%,$(shell find | grep -E "\.c(|pp)")) 
asm := $(patsubst %,$(top-dir)/%,$(shell find | grep -E "\.S"))
obj := $(src:.cpp=.o) $(asm:.S=.o)
dep := $(src:.cpp=.d)

cflags := -I$(cmn-inc-dir) -I$(top-dir) -I$(local-inc-dir) $(common-cflags)
cxxflags := -I$(cmn-inc-dir) -I$(cmn-cpp-dir) -I$(shared-dir) -I$(top-dir) -I$(local-inc-dir) -I$(dbt-inc-dir) $(common-cflags)

all: $(arch-out)

clean:
	$(rm) -f $(arch-out)
	$(rm) -f $(obj)
	$(rm) -f $(dep)

$(arch-out): $(obj) $(cmn-out) $(dbt-lib) aarch64.ld
	@echo "  LD      $(notdir $@)"
# $(q)$(ld) -o $@ -static -Ttext-segment 0xFFFFFFFF80000000 -nostdlib -e start --export-dynamic --whole-archive $(obj) $(cmn-out)
	$(q)$(ld) -o $@ -static -Taarch64.ld -nostdlib -e start --export-dynamic --whole-archive $(obj) $(cmn-out) $(dbt-lib)

%.o: %.S
	@echo "  AS      $(patsubst $(src-dir)/%,%,$@)"
	$(q)$(as) -o $@ $(asflags) $<

%.o: %.cpp
	@echo "  C++     $(notdir $@)"
	$(q)$(cxx) -c -o $@ $(cxxflags) $<

%.d: %.cpp
	$(q)$(cxx) -M -MT $(@:.d=.o) -o $@ $(cxxflags) $<

.FORCE:
.PHONY: $(PHONY) .FORCE

-include $(dep)
