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
		return lhs.g() + lhs.manhattan_distance() < rhs.g() + rhs.manhattan_distance();
	}
};

struct LessByMisplacedTiles
{
	bool operator() (Node const& lhs, Node const& rhs) const
	{
		return lhs.g() + lhs.misplaced_tiles() < rhs.g() + rhs.misplaced_tiles();
	}
};
