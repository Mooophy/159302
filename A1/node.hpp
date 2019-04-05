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

	Node(std::string const& s, std::string const& p, std::string const& g) 
		: state(s), path(p), goal(g) 
	{
	}
	
	std::string state, path, goal;

	std::size_t pos() const
	{
		return state.find('0');
	}

	std::size_t g() const
	{
		return path.size();
	}

	std::size_t manhattan_distance() const
	{
		auto sum = 0;
		for (auto c : "012345678") 
		{
			auto g_index = goal.find(c);
			auto c_index = state.find(c);
			sum += abs(g_index / 3 - c_index / 3) + abs(g_index % 3 - c_index % 3);
		}
		return sum;
	}

	std::size_t misplaced_tiles() const
	{
		auto count = 0;
		for (auto i = 0; i != goal.size(); ++i)
		{
			count += goal[i] != state[i] ? 1 : 0;
		}
		return count;
	}

	//std::size_t f_by_manhattan_distance() const
	//{
	//	return g() + manhattan_distance();
	//}

	std::vector<Node> spawn() const
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

	bool can_up() const
	{
		auto v = std::vector<int>
		{ 
			3, 4, 5, 
			6, 7, 8 
		};
		return (path.size() == 0 || path.back() != 'D') && contains(v, pos());
	}

	Node move_up() const
	{
		auto n = Node{ state, path + "U", goal };
		std::swap(n.state[n.pos() - 3], n.state[n.pos()]);
		return n;
	}

	bool can_right() const
	{
		auto v = std::vector<int>
		{ 
			0, 1,
			3, 4,
			6, 7
		};
		return (path.size() == 0 || path.back() != 'L') && contains(v, pos());
	}

	Node move_right() const
	{
		auto n = Node{ state, path + "R", goal };
		std::swap(n.state[n.pos() + 1], n.state[n.pos()]);
		return n;
	}

	bool can_down() const
	{
		auto v = std::vector<int>
		{
			0, 1, 2,
			3, 4, 5
		};
		return (path.size() == 0 || path.back() != 'U') && contains(v, pos());
	}

	Node move_down() const
	{
		auto n = Node{ state, path + "D", goal };
		std::swap(n.state[n.pos() + 3], n.state[n.pos()]);
		return n;
	}

	bool can_left() const
	{
		auto v = std::vector<int>
		{
			1, 2,
			4, 5,
			7, 8
		};
		return (path.size() == 0 || path.back() != 'R') && contains(v, pos());
	}

	Node move_left() const
	{
		auto n = Node{ state, path + "L", goal };
		std::swap(n.state[n.pos() - 1], n.state[n.pos()]);
		return n;
	}

	bool contains(std::vector<int> const& v, int n) const
	{
		return std::find(v.begin(), v.end(), n) != v.end();
	}
};