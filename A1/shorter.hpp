#include "node.hpp"

struct Shorter
{
	bool operator() (Node const& lhs, Node const& rhs) const
	{
		return lhs.path.size() < rhs.path.size();
	}
};