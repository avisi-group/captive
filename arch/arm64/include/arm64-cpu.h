#pragma once
#include <define.h>
#include <cpu.h>
namespace captive 
{
  namespace arch 
  {
    namespace arm64 
    {
      class arm64_environment;
      enum arm64_features 
      {
        A64_EL = 0,
        A64_SPSEL = 1,
        A64_SS = 2,
        A64_A1 = 3,
        EMULATE_LINUX = 4,
        EMULATE_LINUX_ARCHSIM = 5,
        A64_KERNEL_ICOUNT = 6,
        A64_KERNEL_BRCOUNT = 7,
        A64_USER_ICOUNT = 8,
        A64_USER_BRCOUNT = 9,
      }
      ;
      class arm64_cpu : public CPU 
      {
        public:
        arm64_cpu(arm64_environment& env, PerCPUData *per_cpu_data);
        virtual ~arm64_cpu();
        bool init() override;
        void dump_state(bool show_hidden) const override;
        bool handle_irq(uint32_t isr) override;
        bool handle_mmu_fault(gva_t va, const captive::arch::mmu::AddressTranslationContext& ctx) override;
        bool handle_single_step() override;
        void handle_undefined_instruction() override;
        bool interrupts_enabled(uint8_t irq_line) const override;
        struct reg_state_t 
        {
          uint8_t space_0[248];
          uint8_t space_256[1024];
          uint8_t space_1280[16];
          uint8_t space_1296[10];
          uint8_t space_1312[64];
          uint8_t space_1376[128];
        }
        packed regs;
        struct reg_off_t 
        {
          uint64_t *RBX;
          uint32_t *RBW;
          uint64_t *VBL;
          uint64_t *VBH;
          uint8_t *VB;
          uint16_t *VH;
          uint32_t *VS;
          uint64_t *VD;
          uint128_t *VQ;
          uint32_t *FS;
          uint32_t *FSH;
          uint64_t *FD;
          uint64_t *VF2S;
          uint128_t *VF4S;
          uint128_t *VF2D;
          uint64_t *VB8B;
          uint128_t *VB16B;
          uint64_t *VB4H;
          uint128_t *VB8H;
          uint64_t *VB2S;
          uint128_t *VB4S;
          uint128_t *VB2D;
          uint128_t *VB1Q;
          uint8_t *TBL;
          uint64_t *PC;
          uint8_t *N;
          uint8_t *Z;
          uint8_t *C;
          uint8_t *V;
          uint8_t *D;
          uint8_t *A;
          uint8_t *I;
          uint8_t *F;
          uint8_t *MODE;
          uint64_t *TTBR0;
          uint64_t *TTBR1;
          uint64_t *TCR_EL1;
          uint64_t *VBAR;
          uint64_t *TPIDR_EL0;
          uint64_t *TPIDR_EL1;
          uint64_t *TPIDRRO_EL0;
          uint64_t *ELR_EL1;
          uint32_t *SPSR_EL1;
          uint32_t *ESR_EL1;
          uint64_t *FAR_EL1;
          uint64_t *SP_EL0;
          uint64_t *SP_EL1;
          uint32_t *FPCR;
          uint32_t *MDSCR_EL1;
          uint32_t *CONTEXTIDR_EL1;
          uint64_t *TRACEVAL;
        }
        reg_offsets;
        uint64_t get_page_table_base(int index) const override
        {
          if (index == 0) return (*reg_offsets.TTBR0) & ~0xffff000000000fffull;
          if (index == 1) return (*reg_offsets.TTBR1) & ~0xffff000000000fffull;
          return 0;
        }
        protected:
        void __builtin_set_feature(arm64_features feature, uint32_t value) 
        {
          feature_manager().set_feature(feature, value);
        }
        uint32_t __builtin_get_feature(arm64_features feature) const 
        {
          return feature_manager().get_feature(feature);
        }
        public:
        uint32_t get_psr_from_pstate();
        uint32_t get_exception_class(uint8_t current_el,uint8_t target_el,uint8_t type);
        void update_spsel(uint8_t v);
        void take_arm_exception(uint8_t target_el,uint8_t type,uint32_t syndrome,uint64_t vaddr,uint64_t retaddr,uint64_t voff);
        uint8_t get_el();
        void set_el(uint8_t el);
      }
      ;
    }
  }
}
