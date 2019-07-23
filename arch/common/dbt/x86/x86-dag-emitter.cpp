/* SPDX-License-Identifier: MIT */

#include <dbt/x86/x86-dag-emitter.h>

using namespace captive::arch::jit;
using namespace captive::arch::jit::x86;
using namespace captive::arch::dbt::el;

class Node : public Value {
public:

	Node(const Block *block, const Type& type, const std::string& name, const std::string& meta = "") : _block(block), _type(type), _name(name), _meta(meta)
	{
	}

	const Type& type() const override
	{
		return _type;
	}

	const Block *block() const
	{
		return _block;
	}

private:
	const Block *_block;
	const Type _type;
	const std::string _name, _meta;
};

Value* X86DAGEmitter::adc(Value* lhs, Value* rhs, Value* carry)
{
	auto node = add_node("adc");

	add_data_edge(node, lhs);
	add_data_edge(node, rhs);
	add_data_edge(node, carry);

	return node;
}

Value* X86DAGEmitter::adcf(Value* lhs, Value* rhs, Value* carry)
{
	auto node = add_node("adcf");

	add_data_edge(node, lhs);
	add_data_edge(node, rhs);
	add_data_edge(node, carry);

	return node;
}

Value* X86DAGEmitter::add(Value* lhs, Value* rhs)
{
	auto node = add_node("add");

	add_data_edge(node, lhs);
	add_data_edge(node, rhs);

	return node;
}

Value* X86DAGEmitter::alloc_local(const Type& type, bool is_global)
{
	auto node = add_node("local");
	return node;
}

Value* X86DAGEmitter::bitwise_and(Value* lhs, Value* rhs)
{
	auto node = add_node("and");

	add_data_edge(node, lhs);
	add_data_edge(node, rhs);

	return node;
}

Value* X86DAGEmitter::bitwise_not(Value* v)
{
	auto node = add_node("not");

	add_data_edge(node, v);
	return node;
}

Value* X86DAGEmitter::bitwise_or(Value* lhs, Value* rhs)
{
	auto node = add_node("or");

	add_data_edge(node, lhs);
	add_data_edge(node, rhs);

	return node;
}

Value* X86DAGEmitter::bitwise_xor(Value* lhs, Value* rhs)
{
	auto node = add_node("xor");

	add_data_edge(node, lhs);
	add_data_edge(node, rhs);

	return node;
}

void X86DAGEmitter::block_end(dbt_u32 feature_set)
{
	//
}

void X86DAGEmitter::block_start(dbt_u64 addr, dbt_u32 feature_set)
{
	//
}

void X86DAGEmitter::branch(Value* predicate, Block* true_target, Block* false_target)
{
	auto node = add_node("and");

	add_data_edge(node, predicate);
	sequence_point(node);
}

Value* X86DAGEmitter::bswap(Value* v)
{
	auto node = add_node("bswap");

	add_data_edge(node, v);

	return node;
}

Value* X86DAGEmitter::call(void* fnp, Value* o0, Value* o1, Value* o2, Value* o3)
{
	auto node = add_node("call");

	add_data_edge(node, o0);
	add_data_edge(node, o1);
	add_data_edge(node, o2);
	add_data_edge(node, o3);

	sequence_point(node);
	return node;
}

void X86DAGEmitter::chain(dbt_u64 target, dbt_u64 fallthrough, void* target_ptr, void* ft_ptr)
{
	auto node = add_node("chain");
	sequence_point(node);
}

Value* X86DAGEmitter::clz(Value* v)
{
	auto node = add_node("clz");

	add_data_edge(node, v);

	return node;
}

Value* X86DAGEmitter::cmp_eq(Value* lhs, Value* rhs)
{
	auto node = add_node("cmp-eq");

	add_data_edge(node, lhs);
	add_data_edge(node, rhs);

	return node;
}

Value* X86DAGEmitter::cmp_ge(Value* lhs, Value* rhs)
{
	auto node = add_node("cmp-ge");

	add_data_edge(node, lhs);
	add_data_edge(node, rhs);

	return node;
}

Value* X86DAGEmitter::cmp_gt(Value* lhs, Value* rhs)
{
	auto node = add_node("cmp-gt");

	add_data_edge(node, lhs);
	add_data_edge(node, rhs);

	return node;
}

Value* X86DAGEmitter::cmp_le(Value* lhs, Value* rhs)
{
	auto node = add_node("cmp-le");

	add_data_edge(node, lhs);
	add_data_edge(node, rhs);

	return node;
}

Value* X86DAGEmitter::cmp_lt(Value* lhs, Value* rhs)
{
	auto node = add_node("cmp-lt");

	add_data_edge(node, lhs);
	add_data_edge(node, rhs);

	return node;
}

Value* X86DAGEmitter::cmp_ne(Value* lhs, Value* rhs)
{
	auto node = add_node("cmp-ne");

	add_data_edge(node, lhs);
	add_data_edge(node, rhs);

	return node;
}

Value* X86DAGEmitter::constant(dbt_u64 value, const Type& type)
{
	return add_node("constant");
}

Value* X86DAGEmitter::constant(dbt_f32 value, const Type& type)
{
	return add_node("constant");
}

Value* X86DAGEmitter::constant(dbt_f64 value, const Type& type)
{
	return add_node("constant");
}

Value* X86DAGEmitter::convert(Value* value, const Type& type)
{
	auto node = add_node("convert");

	add_data_edge(node, value);

	return node;
}

Value* X86DAGEmitter::div(Value* lhs, Value* rhs)
{
	auto node = add_node("div");

	add_data_edge(node, lhs);
	add_data_edge(node, rhs);

	return node;
}

Value* X86DAGEmitter::sqrt(Value* value)
{
	auto node = add_node("sqrt");

	add_data_edge(node, value);
	return node;
}

void X86DAGEmitter::enter_kernel_mode()
{
	//
}

void X86DAGEmitter::enter_user_mode()
{
	//
}

void X86DAGEmitter::inc_pc(Value* amount)
{
	auto node = add_node("inc-pc");

	add_data_edge(node, amount);
	sequence_point(node);
}

void X86DAGEmitter::instruction_end(dbt_u64 addr)
{
	//
}

void X86DAGEmitter::instruction_start(dbt_u64 addr)
{
	//
}

void X86DAGEmitter::jump(Block* target)
{
	auto node = add_node("jump");
	sequence_point(node);
}

void X86DAGEmitter::leave(Value* value)
{
	auto node = add_node("leave");
	add_data_edge(node, value);

	sequence_point(node);
}

Value* X86DAGEmitter::load_device(Value* id, Value* offset, const Type& type)
{
	auto node = add_node("load-device");

	add_data_edge(node, id);
	add_data_edge(node, offset);

	return node;
}

Value* X86DAGEmitter::load_local(Value* ptr, const Type& type)
{
	auto node = add_node("load-local");

	add_data_edge(node, ptr);
	sequence_point(node);

	return node;
}

Value* X86DAGEmitter::load_memory(Value* addr, const Type& type)
{
	auto node = add_node("load-memory");

	add_data_edge(node, addr);
	sequence_point(node);

	return node;
}

Value* X86DAGEmitter::load_pc()
{
	return add_node("load-pc");
}

Value* X86DAGEmitter::load_register(Value* offset, const Type& type)
{
	auto node = add_node("load-register");

	add_data_edge(node, offset);
	return node;
}

Value* X86DAGEmitter::mod(Value* lhs, Value* rhs)
{
	auto node = add_node("mod");

	add_data_edge(node, lhs);
	add_data_edge(node, rhs);

	return node;
}

Value* X86DAGEmitter::mul(Value* lhs, Value* rhs)
{
	auto node = add_node("mul");

	add_data_edge(node, lhs);
	add_data_edge(node, rhs);

	return node;
}

Value* X86DAGEmitter::neg(Value* v)
{
	auto node = add_node("neg");

	add_data_edge(node, v);
	return node;
}

void X86DAGEmitter::raise(Value* value)
{
	auto node = add_node("raise");

	add_data_edge(node, value);
}

Value* X86DAGEmitter::reinterpret(Value* val, const Type& type)
{
	auto node = add_node("reinterpret");

	add_data_edge(node, val);
	return node;
}

Value* X86DAGEmitter::rol(Value* v, Value* amt)
{
	auto node = add_node("rol");

	add_data_edge(node, v);
	add_data_edge(node, amt);

	return node;
}

Value* X86DAGEmitter::ror(Value* v, Value* amt)
{
	auto node = add_node("ror");

	add_data_edge(node, v);
	add_data_edge(node, amt);

	return node;
}

Value* X86DAGEmitter::sar(Value* v, Value* amt)
{
	auto node = add_node("sar");

	add_data_edge(node, v);
	add_data_edge(node, amt);

	return node;

}

Value* X86DAGEmitter::sbc(Value* lhs, Value* rhs, Value* carry)
{
	auto node = add_node("sbc");

	add_data_edge(node, lhs);
	add_data_edge(node, rhs);
	add_data_edge(node, carry);

	return node;
}

Value* X86DAGEmitter::sbcf(Value* lhs, Value* rhs, Value* carry)
{
	auto node = add_node("sbcf");

	add_data_edge(node, lhs);
	add_data_edge(node, rhs);
	add_data_edge(node, carry);

	return node;
}

void X86DAGEmitter::set_feature(dbt_u32 feature, Value* value)
{
	auto node = add_node("set-feature");

	add_data_edge(node, value);
}

void X86DAGEmitter::set_zn(Value* v)
{
	auto node = add_node("set-zn");

	add_data_edge(node, v);
}

Value* X86DAGEmitter::shl(Value* v, Value* amt)
{
	auto node = add_node("shl");

	add_data_edge(node, v);
	add_data_edge(node, amt);
	return node;
}

Value* X86DAGEmitter::shr(Value* v, Value* amt)
{
	auto node = add_node("shr");

	add_data_edge(node, v);
	add_data_edge(node, amt);
	return node;
}

Value* X86DAGEmitter::smulh(Value* lhs, Value* rhs)
{
	auto node = add_node("smulh");

	add_data_edge(node, lhs);
	add_data_edge(node, rhs);
	return node;
}

Value* X86DAGEmitter::smull(Value* lhs, Value* rhs)
{
	auto node = add_node("smull");

	add_data_edge(node, lhs);
	add_data_edge(node, rhs);
	return node;
}

void X86DAGEmitter::store_device(Value* id, Value* offset, Value* value)
{
	auto node = add_node("store-device");

	add_data_edge(node, id);
	add_data_edge(node, offset);
	add_data_edge(node, value);

	sequence_point(node);
}

void X86DAGEmitter::store_local(Value* ptr, Value* value)
{
	auto node = add_node("store-local");

	add_data_edge(node, ptr);
	add_data_edge(node, value);

	sequence_point(node);
}

void X86DAGEmitter::store_memory(Value* addr, Value* value)
{
	auto node = add_node("store-memory");

	add_data_edge(node, addr);
	add_data_edge(node, value);

	sequence_point(node);
}

void X86DAGEmitter::store_pc(Value* value)
{
	auto node = add_node("store-pc");

	add_data_edge(node, value);
	sequence_point(node);
}

void X86DAGEmitter::store_register(Value* offset, Value* value)
{
	auto node = add_node("store-register");

	add_data_edge(node, offset);
	add_data_edge(node, value);

	sequence_point(node);
}

Value* X86DAGEmitter::sub(Value* lhs, Value* rhs)
{
	auto node = add_node("sub");

	add_data_edge(node, lhs);
	add_data_edge(node, rhs);

	return node;
}

Value* X86DAGEmitter::sx(Value* val, const Type& type)
{
	auto node = add_node("sx");

	add_data_edge(node, val);
	return node;
}

void X86DAGEmitter::trace(TraceEvent event, Value* o0, Value* o1, Value* o2, Value* o3)
{
	//
}

Value* X86DAGEmitter::truncate(Value* val, const Type& type)
{
	auto node = add_node("truncate");

	add_data_edge(node, val);
	return node;
}

Value* X86DAGEmitter::umulh(Value* lhs, Value* rhs)
{
	auto node = add_node("umulh");

	add_data_edge(node, lhs);
	add_data_edge(node, rhs);

	return node;
}

Value* X86DAGEmitter::umull(Value* lhs, Value* rhs)
{
	auto node = add_node("umull");

	add_data_edge(node, lhs);
	add_data_edge(node, rhs);

	return node;
}

Value* X86DAGEmitter::vector_extract(Value* vct, Value* idx)
{
	auto node = add_node("vector-extract");

	add_data_edge(node, vct);
	add_data_edge(node, idx);

	return node;
}

Value* X86DAGEmitter::vector_insert(Value* vct, Value* idx, Value* value)
{
	auto node = add_node("vector-insert");

	add_data_edge(node, vct);
	add_data_edge(node, idx);
	add_data_edge(node, value);

	return node;
}

Value* X86DAGEmitter::zx(Value* val, const Type& type)
{
	auto node = add_node("zx");

	add_data_edge(node, val);
	return node;
}

///

Value* X86DAGEmitter::add_node(const std::string& name, const std::string& meta)
{
	auto node = new Node(get_current_block(), context().types().v(), name, meta);
	printf("N%016x [label=\"%s\"];\n", node, name.c_str());
	return node;
}

void X86DAGEmitter::add_data_edge(Value* from, Value* to)
{
	if (from == nullptr || to == nullptr) return;
	// if (from->block() != to->block()) return;

	printf("N%016x -> N%016x [color=\"blue\"];\n", from, to);
}

void X86DAGEmitter::add_flow_edge(Value* from, Value* to)
{
	if (from == nullptr || to == nullptr) return;

	printf("N%016x -> N%016x [color=\"red\"];\n", from, to);
}

void X86DAGEmitter::sequence_point(Value* node)
{
	if (_last_sequence_point) {
		add_flow_edge(node, _last_sequence_point);
	}

	_last_sequence_point = node;
}
