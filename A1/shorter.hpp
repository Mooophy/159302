#include "node.hpp"

struct Shorter
{
	bool operator() (Node const& lhs, Node const& rhs) const
	{
		return lhs.path.size() < rhs.path.size();
	}
};

struct LessByManhattanDistance
{
	bool operator() (Node const& lhs, Node const& rhs) const
	{
		return lhs.f_by_manhattan_distance() < rhs.f_by_manhattan_distance();
	}
};