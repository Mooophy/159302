#pragma once
#include <string>
#include <vector>
#include <algorithm>

//
//  struct Node 
//  used in all search algorithms
//
struct Node
{
	Node() = default;
	Node(std::string const& s, std::string const& p) : state(s), path(p) {}
	std::string state, path;

	std::size_t pos() 
	{
		return state.find('0');
	}

	std::vector<Node> spawn()
	{
		std::vector<Node> children;

		if (can_up())
		{
			children.push_back(move_up());
		}

		if (can_right())
		{
			children.push_back(move_right());
		}

		if (can_down())
		{
			children.push_back(move_down());
		}

		if (can_left())
		{
			children.push_back(move_left());
		}

		return children;
	}

private:

	bool can_up()
	{
		auto v = std::vector<int>
		{ 
			3, 4, 5, 
			6, 7, 8 
		};
		return std::find(v.begin(), v.end(), pos()) != v.end();
	}

	Node move_up()
	{
		auto n = Node{ state, path + "U" };
		std::swap(n.state[n.pos() - 3], n.state[n.pos()]);
		return n;
	}

	bool can_right()
	{
		auto v = std::vector<int>
		{ 
			0, 1,
			3, 4,
			6, 7
		};
		return std::find(v.begin(), v.end(), pos()) != v.end();
	}

	Node move_right()
	{
		auto n = Node{ state, path + "R" };
		std::swap(n.state[n.pos() + 1], n.state[n.pos()]);
		return n;
	}

	bool can_down()
	{
		auto v = std::vector<int>
		{
			0, 1, 2,
			3, 4, 5
		};
		return std::find(v.begin(), v.end(), pos()) != v.end();
	}

	Node move_down()
	{
		auto n = Node{ state, path + "D" };
		std::swap(n.state[n.pos() + 3], n.state[n.pos()]);
		return n;
	}

	bool can_left()
	{
		auto v = std::vector<int>
		{
			1, 2,
			4, 5,
			7, 8
		};
		return std::find(v.begin(), v.end(), pos()) != v.end();
	}

	Node move_left()
	{
		auto n = Node{ state, path + "L" };
		std::swap(n.state[n.pos() - 1], n.state[n.pos()]);
		return n;
	}
};