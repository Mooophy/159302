#include <deque>
#include <unordered_set>
#include "node.hpp"
#include "algorithm.h"

using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////
//
// Search Algorithm:  Breadth-First Search 
//
// Move Generator:  
//
////////////////////////////////////////////////////////////////////////////////////////////
string breadthFirstSearch(string const initial, string const goal, int &numOfStateExpansions, int& maxQLength, float &actualRunningTime) {

	actualRunningTime = 55555;
	return "";
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

	auto q = std::deque<Node>{ Node{ initial, "" } };
	auto v = std::unordered_set<string>{ initial };
	auto final_path = string("");

	while (!q.empty())
	{
		Node current = q.front();

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
	string path;
	clock_t startTime;
	//add necessary variables here


	//algorithm implementation
	// cout << "------------------------------" << endl;
 //    cout << "<<progressiveDeepeningSearch_No_VisitedList>>" << endl;
 //    cout << "------------------------------" << endl;

	startTime = clock();
	srand(time(NULL)); //RANDOM NUMBER GENERATOR - ONLY FOR THIS DEMO.  YOU REALLY DON'T NEED THIS! DISABLE THIS STATEMENT.
	maxQLength = rand() % 500; //AT THE MOMENT, THIS IS JUST GENERATING SOME DUMMY VALUE.  YOUR ALGORITHM IMPLEMENTATION SHOULD COMPUTE THIS PROPERLY.
	numOfStateExpansions = rand() % 600; //AT THE MOMENT, THIS IS JUST GENERATING SOME DUMMY VALUE.  YOUR ALGORITHM IMPLEMENTATION SHOULD COMPUTE THIS PROPERLY



//***********************************************************************************************************
	actualRunningTime = ((float)(clock() - startTime) / CLOCKS_PER_SEC);
	path = "DDRRLLLUUURDLUDURDLUUDDRRLLLUUURDLUDURDLUUDDRRLLLUUURDLUDURDLUUDDRRLLLUUURDLUDURDLUUDDRRLLLUUURDLUDURDLUUDDRRLLLUUURDLUDURDLUUDDRRLLLUUURDLUDURDLUUDDRRLLLUUURDLUDURDLUU";  //this is just a dummy path for testing the function           
	return path;

}




///////////////////////////////////////////////////////////////////////////////////////////
//
// Search Algorithm:  
//
// Move Generator:  
//
////////////////////////////////////////////////////////////////////////////////////////////
string uniformCost_ExpandedList(string const initialState, string const goalState, int &numOfStateExpansions, int& maxQLength,
	float &actualRunningTime, int &numOfDeletionsFromMiddleOfHeap, int &numOfLocalLoopsAvoided, int &numOfAttemptedNodeReExpansions) {

	string path;
	clock_t startTime;

	numOfDeletionsFromMiddleOfHeap = 0;
	numOfLocalLoopsAvoided = 0;
	numOfAttemptedNodeReExpansions = 0;


	// cout << "------------------------------" << endl;
	// cout << "<<uniformCost_ExpandedList>>" << endl;
	// cout << "------------------------------" << endl;
	actualRunningTime = 0.0;
	startTime = clock();
	srand(time(NULL)); //RANDOM NUMBER GENERATOR - ONLY FOR THIS DEMO.  YOU REALLY DON'T NEED THIS! DISABLE THIS STATEMENT.
	maxQLength = rand() % 200; //AT THE MOMENT, THIS IS JUST GENERATING SOME DUMMY VALUE.  YOUR ALGORITHM IMPLEMENTATION SHOULD COMPUTE THIS PROPERLY.
	numOfStateExpansions = rand() % 200; //AT THE MOMENT, THIS IS JUST GENERATING SOME DUMMY VALUE.  YOUR ALGORITHM IMPLEMENTATION SHOULD COMPUTE THIS PROPERLY




//***********************************************************************************************************
	actualRunningTime = 66666666666;
	path = "DDRRLLLUUURDLUDURDLUU"; //this is just a dummy path for testing the function

	return path;

}


///////////////////////////////////////////////////////////////////////////////////////////
//
// Search Algorithm:  
//
// Move Generator:  
//
////////////////////////////////////////////////////////////////////////////////////////////
string aStar_ExpandedList(string const initialState, string const goalState, int &numOfStateExpansions, int& maxQLength,
	float &actualRunningTime, int &numOfDeletionsFromMiddleOfHeap, int &numOfLocalLoopsAvoided, int &numOfAttemptedNodeReExpansions, heuristicFunction heuristic) {

	string path;
	clock_t startTime;

	numOfDeletionsFromMiddleOfHeap = 0;
	numOfLocalLoopsAvoided = 0;
	numOfAttemptedNodeReExpansions = 0;


	// cout << "------------------------------" << endl;
	// cout << "<<aStar_ExpandedList>>" << endl;
	// cout << "------------------------------" << endl;
	actualRunningTime = 0.0;
	startTime = clock();
	srand(time(NULL)); //RANDOM NUMBER GENERATOR - ONLY FOR THIS DEMO.  YOU REALLY DON'T NEED THIS! DISABLE THIS STATEMENT.
	maxQLength = rand() % 200; //AT THE MOMENT, THIS IS JUST GENERATING SOME DUMMY VALUE.  YOUR ALGORITHM IMPLEMENTATION SHOULD COMPUTE THIS PROPERLY.
	numOfStateExpansions = rand() % 200; //AT THE MOMENT, THIS IS JUST GENERATING SOME DUMMY VALUE.  YOUR ALGORITHM IMPLEMENTATION SHOULD COMPUTE THIS PROPERLY




//***********************************************************************************************************
	actualRunningTime =77777777;
	path = "DDRRLLLUUURDLUDURDLUU"; //this is just a dummy path for testing the function

	return path;

}




