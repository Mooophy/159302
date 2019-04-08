#include <deque>
#include <unordered_set>
#include <cstdlib>
#include "node.hpp"
#include "algorithm.h"
#include "priority_queue.hpp"
#include "shorter.hpp"

struct Hash {
	size_t operator()(std::string const& state) const {
		auto h = std::atoi(state.c_str());
		return std::hash<int>()(h);
	}
};

using HashSet = std::unordered_set<string, Hash>;

string breadthFirstSearch(string const initial, string const goal, int &numOfStateExpansions, int& maxQLength, float &actualRunningTime) {

	maxQLength = numOfStateExpansions = 0;
	auto startTime = clock();

	auto q = std::deque<Node>{ Node{ initial, "", goal } };

	while (!q.empty())
	{
		auto current = q.front();
		++numOfStateExpansions;

		if (current.state == goal)
		{
			actualRunningTime = ((float)(clock() - startTime) / CLOCKS_PER_SEC);
			return current.path;
		}

		q.pop_front();

		auto children = current.spawn();
		for (Node child : children)
		{
			q.push_back(child);
		}

		maxQLength = q.size() > maxQLength ? q.size() : maxQLength;
	}

	actualRunningTime = ((float)(clock() - startTime) / CLOCKS_PER_SEC);
	return "";
}

string breadthFirstSearch_with_VisitedList(string const initial, string const goal, int &numOfStateExpansions, int& maxQLength, float &actualRunningTime) {
	
	maxQLength = numOfStateExpansions = 0;
	auto startTime = clock();

	auto q = std::deque<Node>{ Node{ initial, "", goal } };
	auto v = HashSet{ initial };

	while (!q.empty())
	{
		auto current = q.front();

		++numOfStateExpansions;

		if (current.state == goal)
		{
			actualRunningTime = ((float)(clock() - startTime) / CLOCKS_PER_SEC);
			return current.path;
		}

		q.pop_front();

		auto children = current.spawn();
		for (Node child : children)
		{
			if (v.end() == v.find(child.state))
			{
				v.insert(child.state);
				q.push_back(child);
			}
		}

		maxQLength = q.size() > maxQLength ? q.size() : maxQLength;
	}

	actualRunningTime = ((float)(clock() - startTime) / CLOCKS_PER_SEC);	
	return "";
}

string progressiveDeepeningSearch_No_VisitedList(string const initial, string const goal, int &numOfStateExpansions, int& maxQLength, float &actualRunningTime, int ultimateMaxDepth) {

	auto startTime = clock();
	
	maxQLength = numOfStateExpansions = 0;
	for(ultimateMaxDepth = 0; /*true*/; ++ultimateMaxDepth)
	{
		auto q = std::deque<Node>{ Node{ initial, "", goal } };

		while (!q.empty())
		{
			auto n = q.front();

			++numOfStateExpansions;

			if (n.state == goal)
			{
				actualRunningTime = ((float)(clock() - startTime) / CLOCKS_PER_SEC);
				return n.path;
			}

			q.pop_front();

			if (n.g() > ultimateMaxDepth)
			{
				continue;
			}

			auto children = n.spawn();
			for (Node child : children)
			{
				q.push_front(child);
			}

			maxQLength = q.size() > maxQLength ? q.size() : maxQLength;
		}
	}

	actualRunningTime = ((float)(clock() - startTime) / CLOCKS_PER_SEC);
	return "";
}

string uniformCost_ExpandedList(string const initial, string const goal, int &numOfStateExpansions, int& maxQLength, float &actualRunningTime, int &numOfDeletionsFromMiddleOfHeap, int &numOfLocalLoopsAvoided, int &numOfAttemptedNodeReExpansions) {

	auto startTime = clock();
	numOfStateExpansions = maxQLength = numOfDeletionsFromMiddleOfHeap = numOfLocalLoopsAvoided = numOfAttemptedNodeReExpansions = 0;

	auto expanded = HashSet{ };
	auto q = PriorityQueue<Node>{ Shorter{} };
	q.push(Node{ initial, "", goal });

	while (!q.empty())
	{
		auto n = q.top();
		++numOfStateExpansions;

		if (n.state == goal)
		{
			actualRunningTime = ((float)(clock() - startTime) / CLOCKS_PER_SEC);
			return n.path;
		}

		q.pop();

		auto is_expanded = expanded.find(n.state) != expanded.end();
		if (is_expanded)
		{
			++numOfAttemptedNodeReExpansions;
			continue;
		}

		expanded.insert(n.state);

		auto children = n.spawn();

		for (auto child : children)
		{
			if (expanded.end() == expanded.find(child.state))
			{
				auto predicate = [child](Node const& c) { return c.state == child.state; };
				auto iterator = std::find_if(q.data().begin(), q.data().end(), predicate);
				auto found = iterator != q.data().end();

				if (!found) 
				{
					q.push(child);
				}
				else if (iterator->g() > child.g()) 
				{
					++numOfDeletionsFromMiddleOfHeap;
					q.remove(iterator);
					q.push(child);
				}
			}
			else 
			{
				++numOfLocalLoopsAvoided;
			}
		}

		maxQLength = q.size() > maxQLength ? q.size() : maxQLength;
	}

	actualRunningTime = ((float)(clock() - startTime) / CLOCKS_PER_SEC);
	return "";
}


string aStar_ExpandedList(string const initial, string const goal, int &numOfExpansions, int& maxQ, float &actualRunningTime, int &numOfDeletionsFromMiddleOfHeap, int &numOfLocalLoopsAvoided, int &numOfAttemptedNodeReExpansions, heuristicFunction heuristic) {
	auto startTime = clock();
	numOfExpansions = maxQ = numOfDeletionsFromMiddleOfHeap = numOfLocalLoopsAvoided = numOfAttemptedNodeReExpansions = 0;

	auto expanded = HashSet{ };
	auto less_by_manhattan_distance = LessByManhattanDistance{};
	auto less_by_misplaced_tiles = LessByMisplacedTiles{};

	auto use_manhattan = heuristic == manhattanDistance;

	auto q = use_manhattan ? PriorityQueue<Node>{ less_by_manhattan_distance } : PriorityQueue<Node>{ less_by_misplaced_tiles };

	q.push(Node{ initial, "", goal });

	while (!q.empty())
	{
		auto n = q.top();
		++numOfExpansions;

		if (n.state == goal)
		{
			actualRunningTime = ((float)(clock() - startTime) / CLOCKS_PER_SEC);
			return n.path;
		}

		q.pop();

		auto is_expanded = expanded.find(n.state) != expanded.end();
		if (is_expanded)
		{
			++numOfAttemptedNodeReExpansions;
			continue;
		}

		expanded.insert(n.state);

		auto children = n.spawn();

		for (auto child : children)
		{
			if (expanded.end() == expanded.find(child.state))
			{
				auto predicate = [child](Node const& c) { return c.state == child.state; };
				auto iterator = std::find_if(q.data().begin(), q.data().end(), predicate);
				auto found = iterator != q.data().end();

				if (!found)
				{
					q.push(child);
				}
				else 
				{
					auto update_required = use_manhattan ? less_by_manhattan_distance(child, *iterator) : less_by_misplaced_tiles(child, *iterator);

					if (update_required)
					{
						++numOfDeletionsFromMiddleOfHeap;
						q.remove(iterator);
						q.push(child);
					}
				}
			}
			else
			{
				++numOfLocalLoopsAvoided;
			}
		}

		maxQ = q.size() > maxQ ? q.size() : maxQ;
	}

	actualRunningTime = ((float)(clock() - startTime) / CLOCKS_PER_SEC);
	return "";
}