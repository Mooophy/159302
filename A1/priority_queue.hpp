//
//  This file implemented a custom priority queue data structure. Compared with std::priority_queue, 
//  this one allows to access and change any item held in it by openning public interface to its 
//  underlying data structure. This feature is essential for "uniform cost search" and "A* with strict
//  expanded list".
//
//  Reference : Chapter 6, "Introduction to Algorithms 3rd ed", aka CLRS.
//

#pragma once
#include <vector>
#include <functional>
#include <stdexcept>
#include <algorithm>


template<typename Iterator>
auto inline parent(Iterator first, Iterator it) -> Iterator
{
	return first + (it - first - 1) / 2;
}

//
//  left_child
//  O(1)
//
template<typename Iterator>
auto inline left_child(Iterator first, Iterator last, Iterator it) -> Iterator
{
	auto size = last - first;
	auto offset = 2 * (it - first) + 1;
	return offset > size ? last : first + offset;
}

//
//  right_child
//  O(1)
//
template<typename Iterator>
auto inline right_child(Iterator first, Iterator last, Iterator it) -> Iterator
{
	auto left = left_child(first, last, it);
	return left != last ? left + 1 : last;
}

//
//  heapify
//  O(lg n)
//  maintain heap's peroperty with a bottom up way
//
template<typename Iterator, typename CompareFunc>
auto heapify(Iterator first, Iterator last, Iterator curr, CompareFunc && compare) -> void
{
	while (true)
	{
		auto left = left_child(first, last, curr);
		auto right = right_child(first, last, curr);

		//! find max or min amoung curr, left and right children, depending on the CommpareFunc passed in.
		auto max_min = (left != last && compare(*left, *curr)) ? left : curr;
		if (right != last && compare(*right, *max_min))	max_min = right;

		//!	exchange.
		if (max_min != curr)
		{
			std::swap(*max_min, *curr);
			curr = max_min;
		}
		else
		{
			return;
		}
	}
}

//
//  build_heap
//  O(n)
//
template<typename Iterator, typename CompareFunc >
auto inline build_heap(Iterator first, Iterator last, CompareFunc && compare) -> void
{
	auto size = last - first;
	for (auto curr = first + size / 2 - 1; /* */; --curr)
	{
		heapify(first, last, curr, compare);
		if (curr == first) return;
	}
}

//
//  PriorityQueue
//
template<typename T>
class PriorityQueue
{
public:
	using ValueType = T;
	using Vector = std::vector < T >;
	using SizeType = typename Vector::size_type;
	using Iterator = typename Vector::iterator;
	using CompareFunc = std::function < bool(ValueType const&, ValueType const&) >;

	explicit PriorityQueue(CompareFunc && c)
		: v{}, compare{ std::move(c) }
	{}

	explicit PriorityQueue(std::initializer_list<ValueType>&& list, CompareFunc&& c)
		: v(std::move(list)), compare{ std::move(c) }
	{
		build_heap(v.begin(), v.end(), compare);
	}

	template<typename Iterator>
	PriorityQueue(Iterator first, Iterator last, CompareFunc&& c)
		: v(first, last), compare{ std::move(c) }
	{
		build_heap(v.begin(), v.end(), compare);
	}

	auto data() -> Vector& 
	{ 
		return v; 
	}
	
	auto top() const -> ValueType const& 
	{
		return v.front(); 
	}

	auto size() const -> SizeType 
	{
		return v.size(); 
	}

	auto empty() const -> bool 
	{
		return v.empty(); 
	}

	auto push(ValueType const& newval) -> void
	{
		//! find the right place for added
		v.resize(size() + 1);
		auto curr = v.end() - 1;
		for (; curr > v.begin() && compare(newval, *parent(v.begin(), curr)); curr = parent(v.begin(), curr))
			*curr = *parent(v.begin(), curr);

		//! insert
		*curr = newval;
	}

	auto pop() -> void
	{
		if (empty())
			throw std::underflow_error{ "underflow." };

		v.front() = v.back();
		v.resize(v.size() - 1);
		heapify(v.begin(), v.end(), v.begin(), compare);
	}

	auto remove(Iterator it) -> void
	{
		std::swap(*it, *(v.end() - 1));
		v.resize(v.size() - 1);
		heapify(v.begin(), v.end(), it, compare);
	}

private:
	Vector v;
	CompareFunc compare;
};
