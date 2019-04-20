#include "node.hpp"

//
//	Functor to compare two nodes by comparing g value
//
struct Shorter
{
	bool operator() (Node const& lhs, Node const& rhs) const
	{
		return lhs.g() < rhs.g();
	}
};

//
//	Functor comparing two nodes by comparing g value + manhattan distance
//
struct LessByManhattanDistance
{
	bool operator() (Node const& lhs, Node const& rhs) const
	{
		return lhs.g() + lhs.manhattan_distance() < rhs.g() + rhs.manhattan_distance();
	}
};

//
//	Functor comparing two nodes by comparing g value + misplaced tiles
//
struct LessByMisplacedTiles
{
	bool operator() (Node const& lhs, Node const& rhs) const
	{
		return lhs.g() + lhs.misplaced_tiles() < rhs.g() + rhs.misplaced_tiles();
	}
};
