#include <deque>
#include <unordered_set>
#include "node.hpp"
#include "algorithm.h"
#include "priority_queue.hpp"
#include "shorter.hpp"

using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////
//
// Search Algorithm:  Breadth-First Search 
//
// Move Generator:  
//
////////////////////////////////////////////////////////////////////////////////////////////
string breadthFirstSearch(string const initial, string const goal, int &numOfStateExpansions, int& maxQLength, float &actualRunningTime) {

	maxQLength = numOfStateExpansions = 0;
	auto startTime = clock();

	auto q = std::deque<Node>{ Node{ initial, "", goal } };
	auto final_path = string("");

	while (!q.empty())
	{
		auto current = q.front();

		++numOfStateExpansions;

		if (current.state == goal)
		{
			final_path = current.path;
			break;
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

	return final_path;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
// Search Algorithm:  Breadth-First Search with VisitedList
//
// Move Generator:  
//
////////////////////////////////////////////////////////////////////////////////////////////
string breadthFirstSearch_with_VisitedList(string const initial, string const goal, int &numOfStateExpansions, int& maxQLength, float &actualRunningTime) {
	
	maxQLength = numOfStateExpansions = 0;
	auto startTime = clock();

	auto q = std::deque<Node>{ Node{ initial, "", goal } };
	auto v = std::unordered_set<string>{ initial };
	auto final_path = string("");

	while (!q.empty())
	{
		auto current = q.front();

		++numOfStateExpansions;

		if (current.state == goal)
		{
			final_path = current.path;
			break;
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

	return final_path;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
// Search Algorithm:  
//
// Move Generator:  
//
////////////////////////////////////////////////////////////////////////////////////////////
string progressiveDeepeningSearch_No_VisitedList(string const initialState, string const goalState, int &numOfStateExpansions, int& maxQLength, float &actualRunningTime, int ultimateMaxDepth) {

	return "";
}




///////////////////////////////////////////////////////////////////////////////////////////
//
// Search Algorithm:  
//
// Move Generator:  
//
////////////////////////////////////////////////////////////////////////////////////////////
string uniformCost_ExpandedList(string const initial, string const goal, int &numOfStateExpansions, int& maxQLength, float &actualRunningTime, int &numOfDeletionsFromMiddleOfHeap, int &numOfLocalLoopsAvoided, int &numOfAttemptedNodeReExpansions) {

	auto startTime = clock();
	numOfStateExpansions = maxQLength = numOfDeletionsFromMiddleOfHeap = numOfLocalLoopsAvoided = numOfAttemptedNodeReExpansions = 0;

	auto expanded = std::unordered_set<string>{ };
	auto q = PriorityQueue<Node>{ Shorter{} };
	q.push(Node{ initial, "", goal });
	auto final_path = string("");

	while (!q.empty())
	{
		auto n = q.top();
		++numOfStateExpansions;

		if (n.state == goal)
		{
			final_path = n.path;
			break;
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

	return final_path;
}


///////////////////////////////////////////////////////////////////////////////////////////
//
// Search Algorithm:  
//
// Move Generator:  
//
////////////////////////////////////////////////////////////////////////////////////////////
string aStar_ExpandedList(string const initial, string const goal, int &numOfStateExpansions, int& maxQLength, float &actualRunningTime, int &numOfDeletionsFromMiddleOfHeap, int &numOfLocalLoopsAvoided, int &numOfAttemptedNodeReExpansions, heuristicFunction heuristic) {
	auto startTime = clock();
	numOfStateExpansions = maxQLength = numOfDeletionsFromMiddleOfHeap = numOfLocalLoopsAvoided = numOfAttemptedNodeReExpansions = 0;

	auto expanded = std::unordered_set<string>{ };
	auto q = PriorityQueue<Node>{ LessByManhattanDistance{} };
	q.push(Node{ initial, "", goal });
	auto final_path = string("");

	while (!q.empty())
	{
		auto n = q.top();
		++numOfStateExpansions;

		if (n.state == goal)
		{
			final_path = n.path;
			break;
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
				else if (iterator->f_by_manhattan_distance() > child.f_by_manhattan_distance())
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

	return final_path;
}




