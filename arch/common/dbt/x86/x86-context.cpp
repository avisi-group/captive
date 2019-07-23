/* SPDX-License-Identifier: MIT */

#include <dbt/x86/x86-context.h>
#include <dbt/x86/x86-block.h>
#include <dbt/x86/x86-value.h>
#include <dbt/mc/x86/instruction.h>
#include <list>
#include <printf.h>

using namespace captive::arch::jit;
using namespace captive::arch::jit::x86;
using namespace captive::arch::dbt;
using namespace captive::arch::dbt::el;
using namespace captive::arch::dbt::mc::x86;

X86Context::X86Context(Support& support) : Context(support), _entry_block(create_block())
{
}

X86Context::~X86Context()
{
}

Block* X86Context::create_block()
{
	return support().alloc_obj<X86Block>(*this);
}

Instruction* X86Context::start_instruction() const
{
	return((X86Block *) entry_block())->head();
}

X86Block::X86Block(Context& ctx) : Block(ctx), next0(nullptr), next1(nullptr), linked(false), mark_type(NO_MARK), _head(ctx.support().alloc_obj<Instruction>(InstructionKind::LABEL))
{
}

bool X86Context::link_visit(X86Block* block, std::list<X86Block *>& sorted_list)
{
	if (block->mark_type == X86Block::PERMANENT_MARK) return true;
	if (block->mark_type == X86Block::TEMPORARY_MARK) return false;

	block->mark_type = X86Block::TEMPORARY_MARK;

	if (block->next0 != nullptr) {
		if (!link_visit(block->next0, sorted_list)) return false;
	}

	if (block->next1 != nullptr) {
		if (!link_visit(block->next1, sorted_list)) return false;
	}

	block->mark_type = X86Block::PERMANENT_MARK;
	sorted_list.push_front(block);

	return true;
}

bool X86Context::link()
{
	std::list<X86Block *> all_nodes;

	// Build a list of all reachable nodes.
	std::list<X86Block *> work_queue;
	work_queue.push_back((X86Block *) entry_block());
	while (work_queue.size() > 0) {
		X86Block *current = work_queue.front();
		work_queue.pop_front();

		if (current->linked) continue;
		current->linked = true;

		all_nodes.push_back(current);

		if (current->next0) work_queue.push_back(current->next0);
		if (current->next1) work_queue.push_back(current->next1);
	}

	// Perform topological sorting.
	std::list<X86Block *> sorted_list;
	while (all_nodes.size() > 0) {
		X86Block *current = all_nodes.front();
		all_nodes.pop_front();

		if (!link_visit(current, sorted_list)) return false;
	}

	// Actually link the blocks together.
	X86Block *e = ((X86Block *) entry_block());
	for (auto current : sorted_list) {
		if (current != e) {
			e->head()->prev()->insert_after(current->head());
		}
	}

	return true;
}

bool X86Context::optimise_control_flow()
{
	Instruction *start = ((X86Block *) entry_block())->head();
	Instruction *current = start;

	do {
		if (current->kind() == InstructionKind::JMP) {
			if (current->get_operand(0).label.target == current->next()) {
				current->change_kind(InstructionKind::DEAD);
			}
		}

		current = current->next();
	} while (current != start);

	return true;
}
