#pragma once
#include <string>
#include <vector>
#include <algorithm>

namespace Case {
	static std::string goal = "";
}

//
//  struct Node 
//  used in all search algorithms
//
struct Node
{
	Node() = default;

	Node(std::string const& s, std::string const& p) 
		: state(s), path(p), pos(state.find('0'))
	{
	}
	
	std::string state, path;

	std::size_t g() const
	{
		return path.size();
	}

	std::size_t manhattan_distance() const
	{
		auto sum = 0;
		for (auto c : "012345678") 
		{
			auto g_index = Case::goal.find(c);
			auto c_index = state.find(c);
			sum += abs(static_cast<int>(g_index / 3 - c_index / 3)) + abs(static_cast<int>(g_index % 3 - c_index % 3));
		}
		return sum;
	}

	std::size_t misplaced_tiles() const
	{
		auto count = 0;
		for (auto i = 0; i != Case::goal.size(); ++i)
		{
			count += Case::goal[i] != state[i] ? 1 : 0;
		}
		return count;
	}

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
	std::size_t pos;

	bool can_up() const
	{
		auto v = std::vector<int>
		{ 
			3, 4, 5, 
			6, 7, 8 
		};
		return (path.size() == 0 || path.back() != 'D') && contains(v, pos);
	}

	Node move_up() const
	{
		auto s = std::string(state);
		std::swap(s[pos - 3], s[pos]);
		return Node{ s, path + "U" };
	}

	bool can_right() const
	{
		auto v = std::vector<int>
		{ 
			0, 1,
			3, 4,
			6, 7
		};
		return (path.size() == 0 || path.back() != 'L') && contains(v, pos);
	}

	Node move_right() const
	{
		auto s = std::string(state);
		std::swap(s[pos + 1], s[pos]);
		return Node{ s, path + "R" };
	}

	bool can_down() const
	{
		auto v = std::vector<int>
		{
			0, 1, 2,
			3, 4, 5
		};
		return (path.size() == 0 || path.back() != 'U') && contains(v, pos);
	}

	Node move_down() const
	{
		auto s = std::string(state);
		std::swap(s[pos + 3], s[pos]);
		return Node{ s, path + "D" };
	}

	bool can_left() const
	{
		auto v = std::vector<int>
		{
			1, 2,
			4, 5,
			7, 8
		};
		return (path.size() == 0 || path.back() != 'R') && contains(v, pos);
	}

	Node move_left() const
	{
		auto s = std::string(state);
		std::swap(s[pos - 1], s[pos]);
		return Node{ s, path + "L" };
	}

	bool contains(std::vector<int> const& v, int n) const
	{
		return std::find(v.begin(), v.end(), n) != v.end();
	}
};