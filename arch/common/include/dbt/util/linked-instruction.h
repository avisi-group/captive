/* SPDX-License-Identifier: MIT */

#pragma once

namespace captive {
	namespace arch {
		namespace dbt {
			namespace util {

				template<class TSelf, typename TKind, class TOperand, int _NR_OPERANDS>
				class LinkedInstruction {
				public:
					typedef LinkedInstruction<TSelf, TKind, TOperand, _NR_OPERANDS> LinkedInstructionType;

					static const int NR_OPERANDS = _NR_OPERANDS;

					LinkedInstruction(TKind kind) : _kind(kind), _volatile(false), _next((TSelf *)this), _prev((TSelf *)this)
					{
					}

					virtual ~LinkedInstruction()
					{
					}

					void insert_after(TSelf *element)
					{
						//element->_prev->_next = this->_next;
						//this->_next->_prev = element->_prev;

						this->_next->_prev = element->_prev;
						element->_prev->_next = this->_next;

						this->_next = element;
						element->_prev = (TSelf *)this;
					}

					void insert_before(TSelf *o);

					const TKind& kind() const
					{
						return _kind;
					}

					void change_kind(const TKind& kind)
					{
						_kind = kind;
					}

					TSelf *next() const
					{
						return _next;
					}

					TSelf *prev() const
					{
						return _prev;
					}

					const TOperand& get_operand(int index) const
					{
						return _operands[index];
					}

					TOperand& get_operand_nc(int index)
					{
						return _operands[index];
					}

					void set_operand(int index, const TOperand& value)
					{
						_operands[index] = value;
					}

					bool is_volatile() const
					{
						return _volatile;
					}

					void is_volatile(bool value)
					{
						_volatile = value;
					}

					void make_volatile()
					{
						_volatile = true;
					}

				private:
					TKind _kind;
					bool _volatile;

					TSelf *_next, *_prev;
					TOperand _operands[NR_OPERANDS];
				};
			}
		}
	}
}
