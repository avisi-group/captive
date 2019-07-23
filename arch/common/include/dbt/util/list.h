/* SPDX-License-Identifier: MIT */

#pragma once

#include <dbt/support.h>

namespace captive {
	namespace arch {

		namespace dbt {
			namespace util {

				template<typename TElement>
				class ListNode {
				public:
					typedef TElement ElementType;
					typedef ListNode<TElement> Self;

					ListNode(const TElement& data) : Data(data), Next(nullptr)
					{
					}

					TElement Data;
					Self *Next;
				};

				template<typename TNode>
				class ListIterator {
				public:
					typedef ListIterator<TNode> Self;
					typedef typename TNode::ElementType ElementType;

					ListIterator(TNode *node) : _current(node)
					{
					}

					const ElementType& operator*() const
					{
						return _current->Data;
					}

					bool operator!=(const Self& other) const
					{
						return _current != other._current;
					}

					Self& operator++()
					{
						if (_current) {
							_current = _current->Next;
						}

						return *this;
					}

				private:
					TNode *_current;
				};

				template<typename TElement>
				class List {
				public:
					typedef ListNode<TElement> NodeType;
					typedef ListIterator<NodeType> IteratorType;

					List(Support& support) : _support(support), _head(nullptr), _size(0)
					{
					}

					~List()
					{
						NodeType *node = _head;
						while (node) {
							NodeType *next = node->Next;

							_support.free_obj<NodeType>(node);
							node = next;
						}
					}

					void append(const TElement& elem)
					{
						NodeType **slot = &_head;

						while (*slot) {
							slot = &((*slot)->Next);
						}

						*slot = alloc_node(elem);
						_size++;
					}

					void push(const TElement& elem)
					{
						auto node = alloc_node(elem);

						if (_head) {
							node->Next = _head;
						}

						_head = node;
						_size++;
					}

					TElement pop()
					{
						if (_head == nullptr) return TElement();

						TElement data = _head->Data;
						NodeType *next = _head->Next;

						_support.free_obj<NodeType>(_head);
						_head = next;

						_size--;

						return data;
					}

					void enqueue(const TElement& elem)
					{
						append(elem);
					}

					TElement dequeue()
					{
						return pop();
					}

					dbt_size_t size() const
					{
						return _size;
					}

					bool empty() const
					{
						return size() == 0;
					}

					IteratorType begin() const
					{
						return IteratorType(_head);
					}

					IteratorType end() const
					{
						return IteratorType(nullptr);
					}

				private:
					Support& _support;
					NodeType *_head;
					dbt_size_t _size;

					NodeType *alloc_node(const TElement& data)
					{
						return _support.alloc_obj<NodeType>(data);
					}
				};
			}
		}
	}
}
