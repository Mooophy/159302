//////////////////////////////////////////////////////////////////////////
//  8-PUZZLE PROBLEM
//  
//  Start-up codes by n.h.reyes@massey.ac.nz
//
//  Name(s):
//  Date:
//
//////////////////////////////////////////////////////////////////////////
/*
 * Flicker-free implementation of the 8-puzzle board game using the BGI
 * graphics library for Windows.
 */

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <algorithm> //used by transform - to lower case
#include <exception>

#include "graphics2.h"
#include "algorithm.h"

using namespace std;

#define OUTPUT_LENGTH 2 /* Length of output string. */

const int HEIGHT = 400; /**< Height of board for rendering in pixels. */
const int WIDTH  = 400; /**< Width of board for rendering in pixels. */

/**
 * Update the board and draw it to the screen. This function displays the
 * board updates in a flicker-free way.
 *
 * @param board 3 x 3 array containing the current board state,
 *              0 indicates an empty space.
 */


//////////////////////////////////////////////////////
// Function prototypes
void displayBoard(string const elements); 
void AnimateSolution(string const initialState, string const goalState, string path);

////////////////////////////////////////////////////// 
 
void update(int **board) {
    /* Setting up the graphics. */
    static bool setup = false;

    if(!setup) {
        int graphDriver = 0;
        int graphMode = 0;
        initgraph(&graphDriver, &graphMode, "", WIDTH, HEIGHT);
        setup = true;
    }

    /* Variables for the function. */
    int xIncrement = (WIDTH - 40) / 3;        /* Grid's raster width. */
    int yIncrement = ((HEIGHT - 6) - 40) / 3; /* Grid's raster height. */
    int x = 0;            /* Temporary x positions. */
    int y = 0;            /* Temporary y positions. */
    char outputString[OUTPUT_LENGTH]; /* Holder for output strings in the GUI. */
    static bool visual;   /* Indicator which visual page to draw to
                           * to prevent flickers. */

    /* Initalising the variables. */
    strncpy(outputString, "", OUTPUT_LENGTH);
    /* Even though this is not necessary here the protected version of "strcpy"
       is used in this case. It should ALWAYS be used to prevent boundary
       overwrites! */

    /* Initialising the GUI. */
    setactivepage(visual);
    setbkcolor(BLACK);
    cleardevice();
    setfillstyle(SOLID_FILL, WHITE);
    settextstyle(GOTHIC_FONT, HORIZ_DIR, 6);
    settextjustify(CENTER_TEXT, CENTER_TEXT);

    /* Display different coloured squares for different numbers. */
    y = 10;
    for(int i = 0; i < 3; i++) {
        x = 10;
        for(int j = 0; j < 3; j++) {
            if(board[i][j] != 0) {
                setcolor(board[i][j]);
                bar(x, y, x + xIncrement, y + yIncrement);
            }
            x += 10;
            x += xIncrement;
        }
        y += 10;
        y += yIncrement;
    }

    /* Display the actual numbers. */
    y = 8 * HEIGHT / 40;
    for(int i = 0; i < 3; i++) {
        x = WIDTH / 6;
        for(int j = 0; j < 3; j++) {
            setcolor(WHITE);
            setbkcolor(board[i][j]);
            if(board[i][j] != 0) {
                snprintf(outputString, OUTPUT_LENGTH, "%d", board[i][j]);
                /* Even though this is also not necessary here the protected
                   version of "sprintf" is used in this case. It should ALWAYS
                   be used to prevent boundary overwrites! */
                outtextxy(x, y, outputString);
                moveto(0, 0);
            }
            x += 2 * (WIDTH / 6);
        }
        y += 13 * HEIGHT / 40;
    }

    /* Set the page to display. */
    setvisualpage(visual);
    visual = !visual;

    delay(100);
}


void displayBoard(string const elements) {
    /* Setting up the graphics. */
    
    int board[3][3];
        
    int n=0;
    
    for(int i=0; i < 3;i++){
	    for(int j=0; j < 3;j++){
		    
		    board[i][j] = elements.at(n) - '0';	    
		    n++;		    
		 }   
	 }
    
    


    /* Variables for the function. */
    int xIncrement = (WIDTH - 40) / 3;        /* Grid's raster width. */
    int yIncrement = ((HEIGHT - 6) - 40) / 3; /* Grid's raster height. */
    int x = 0;            /* Temporary x positions. */
    int y = 0;            /* Temporary y positions. */
    char outputString[OUTPUT_LENGTH]; /* Holder for output strings in the GUI. */
    static bool visual;   /* Indicator which visual page to draw to
                           * to prevent flickers. */

    /* Initalising the variables. */
    strncpy(outputString, "", OUTPUT_LENGTH);
    /* Even though this is not necessary here the protected version of "strcpy"
       is used in this case. It should ALWAYS be used to prevent boundary
       overwrites! */

    /* Initialising the GUI. */
    setactivepage(visual);
    setbkcolor(BLACK);
    cleardevice();
    setfillstyle(SOLID_FILL, WHITE);
    settextstyle(GOTHIC_FONT, HORIZ_DIR, 6);
    settextjustify(CENTER_TEXT, CENTER_TEXT);

    /* Display different coloured squares for different numbers. */
    y = 10;
    for(int i = 0; i < 3; i++) {
        x = 10;
        for(int j = 0; j < 3; j++) {
            if(board[i][j] != 0) {
                setcolor(board[i][j]);
                bar(x, y, x + xIncrement, y + yIncrement);
            }
            x += 10;
            x += xIncrement;
        }
        y += 10;
        y += yIncrement;
    }

    /* Display the actual numbers. */
    y = 8 * HEIGHT / 40;
    for(int i = 0; i < 3; i++) {
        x = WIDTH / 6;
        for(int j = 0; j < 3; j++) {
            setcolor(WHITE);
            setbkcolor(board[i][j]);
            if(board[i][j] != 0) {
                snprintf(outputString, OUTPUT_LENGTH, "%d", board[i][j]);
                /* Even though this is also not necessary here the protected
                   version of "sprintf" is used in this case. It should ALWAYS
                   be used to prevent boundary overwrites! */
//                outtextxy(x, y, (char *)elements[i+j*3]);   
                outtextxy(x, y, outputString);
                moveto(0, 0);
            }
            x += 2 * (WIDTH / 6);
        }
        y += 13 * HEIGHT / 40;
    }

    /* Set the page to display. */
    setvisualpage(visual);
    visual = !visual;

    delay(100);
}



void AnimateSolution(string const initialState, string const goalState, string path){

	int step=1;
   
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 3);
    settextjustify(CENTER_TEXT, CENTER_TEXT);
    outtextxy(getmaxx()/2,getmaxy()/2,"press any key to start.");
    cout << endl << endl << "press any key to start." << endl << endl;
    getch();
	
	cout << endl << "--------------------------------------------------------------------" << endl;
	if (path==""){
		 cout << endl << "Nothing to animate." << endl;
	} else {
	    cout << endl << "Animating solution..." << endl;
	    cout << "Plan of action = " << path << endl;
	}
	
	Puzzle *p = new Puzzle(initialState, goalState);
    Puzzle *nextState;
	
	string strState;
		
	strState = p->toString();
    displayBoard(strState);
	
	cout << "--------------------------------------------------------------------" << endl;
	      
	for(int i=0; i < path.length(); i++){
		
	   cout << endl << "Step #" << step << ")  ";
	   switch(path[i]){
			
			case 'U': nextState = p->moveUp(); cout << "[UP]" << endl;
			          break;
			case 'D': nextState = p->moveDown(); cout << "[DOWN]" << endl;
			          break;
			case 'L': nextState = p->moveLeft(); cout << "[LEFT]" << endl;
			          break;
            case 'R': nextState = p->moveRight(); cout << "[RIGHT]" << endl;
			          break;
 	  }
 	  strState = nextState->toString();
		
	  delete p;
	  p = nextState;
		
      displayBoard(strState);
      
      step++;
	}
	
	delete p; //clear memory	
	cout << endl << "Animation done." << endl;
	cout << "--------------------------------------------------------------------" << endl;
	

}



/**
 * Main function to kick off the game.
 */

int main( int argc, char* argv[] ){
   
   string path;

   //~ cout << "=========<< SEARCH ALGORITHMS >>=========" << endl;
	if(argc < 5){
		cout << "SYNTAX: main.exe <TYPE_OF_RUN = \"batch_run\" or \"single_run\"> ALGORITHM_NAME \"INITIAL STATE\" \"GOAL STATE\" " << endl;
		exit(0);
	}
    
   //for testing only 
   //~ cout << "Parameters supplied" << endl;
   //~ for(int i=1; i < argc; i++){
		
		//~ cout << setw(2) << i << ") " << argv[i] << endl;
		
   //~ }
	
	string typeOfRun(argv[1]);
	string algorithmSelected(argv[2]);
	string initialState(argv[3]);
	string goalState(argv[4]);
	
    std::transform(typeOfRun.begin(), typeOfRun.end(), typeOfRun.begin(), ::tolower);
    std::transform(algorithmSelected.begin(), algorithmSelected.end(), algorithmSelected.begin(), ::tolower);
    

	int pathLength=0;
	int depth=0;
    int numOfStateExpansions=0;	
	int maxQLength=0;
    int numOfDeletionsFromMiddleOfHeap=0;
    int numOfLocalLoopsAvoided=0;
    int numOfAttemptedNodeReExpansions=0;

	float actualRunningTime=0.0;	
	//=========================================================================================================
    // init graphics
    int graphDriver = 0;
    int graphMode = 0;
   
  
    
    
    //---    
    

    // cout << "typeOfRun = " << typeOfRun << endl;
    // cout << "algorithmSelected = " << algorithmSelected << endl;
	
try{

	if(typeOfRun == "single_run") cout << endl << "============================================<< EXPERIMENT RESULTS >>============================================" << endl;
	
	//=========================================================================================================
	//Run algorithm

    if(algorithmSelected == "breadth_first_search" ){
        
        path = breadthFirstSearch(initialState, goalState, numOfStateExpansions, maxQLength, actualRunningTime);

    } else if(algorithmSelected == "breadth_first_search_vlist" ){
        
        path = breadthFirstSearch_with_VisitedList(initialState, goalState, numOfStateExpansions, maxQLength, actualRunningTime);    
                          

    } else if(algorithmSelected == "pds_no_vlist" ){			
		
		path = progressiveDeepeningSearch_No_VisitedList(initialState,  goalState, numOfStateExpansions, maxQLength, actualRunningTime, 5000);		

    } else if(algorithmSelected == "uniformcost_expandedlist" ){

        path = uniformCost_ExpandedList(initialState, goalState, numOfStateExpansions, maxQLength, actualRunningTime, numOfDeletionsFromMiddleOfHeap,numOfLocalLoopsAvoided ,numOfAttemptedNodeReExpansions);
    	
	
    }  else if(algorithmSelected == "astar_explist_misplacedtiles" ){       
        
        path = aStar_ExpandedList(initialState, goalState, numOfStateExpansions, maxQLength, actualRunningTime, numOfDeletionsFromMiddleOfHeap,numOfLocalLoopsAvoided ,numOfAttemptedNodeReExpansions, misplacedTiles);     

    }  else if(algorithmSelected == "astar_explist_manhattan" ){       
        
        path = aStar_ExpandedList(initialState, goalState, numOfStateExpansions, maxQLength, actualRunningTime, numOfDeletionsFromMiddleOfHeap,numOfLocalLoopsAvoided ,numOfAttemptedNodeReExpansions, manhattanDistance); 
        
    }
//-----------------------------------------------------------------------------
		
	pathLength = path.size();
		
	//Run algorithm    
    if(algorithmSelected == "breadth_first_search" ){
        cout << setw(31) << std::left << "1) breadth_first_search";                    

    } else if(algorithmSelected == "breadth_first_search_vlist" ){
        cout << setw(31) << std::left << "2) breadth_first_search_vlist";             
    
    } else if(algorithmSelected == "pds_no_vlist" ){
        cout << setw(31) << std::left << "3) pds_no_vlist";                  
     
    } else if(algorithmSelected == "uniformcost_expandedlist" ){
        cout << setw(31) << std::left << "4) uniformCost_ExpandedList";              
    
    }  else if(algorithmSelected == "astar_explist_misplacedtiles" ){
        cout << setw(31) << std::left << "5) astar_explist_misplacedtiles";         
        
    }  else if(algorithmSelected == "astar_explist_manhattan" ){
        cout << setw(31) << std::left << "6) astar_explist_manhattan";  
    }      

}

catch(exception &e){
    cout << "Standard exception: " << e.what() << endl;
}

    if(pathLength == 0) cout << "\n\n*---- NO SOLUTION found. (Q is empty!) ----*" << endl;    

	if(typeOfRun == "batch_run"){	
		
		cout  << setprecision(6) << std::setfill(' ')   << std::fixed << std::right << ' ' << setw(10) << pathLength; 
		cout  << setprecision(6) << std::setfill(' ')   << std::fixed << std::right << ' ' <<  setw(10) << numOfStateExpansions; 
		cout  << setprecision(6) << std::setfill(' ')   << std::fixed << std::right << ' ' <<  setw(19) << maxQLength; 
		cout  << setprecision(6) << std::setfill(' ')   << std::fixed << std::right << ' ' <<  setw(15) << actualRunningTime; 
        cout  << setprecision(6) << std::setfill(' ')   << std::fixed << std::right << ' ' <<  setw(15) << numOfDeletionsFromMiddleOfHeap; 
        cout  << setprecision(6) << std::setfill(' ')   << std::fixed << std::right << ' ' <<  setw(15) << numOfAttemptedNodeReExpansions << endl; 


	} else if(typeOfRun == "single_run"){	
		cout << setprecision(6) << setw(25) << std::setfill(' ') <<  std::right << endl << endl << "Initial State:" << std::fixed << ' ' << setw(12) << initialState << endl;
		cout << setprecision(6) << setw(25) << std::setfill(' ') <<  std::right << "Goal State:" << std::fixed << ' ' << setw(12) << goalState << endl;
		cout << setprecision(6) << setw(25) << std::setfill(' ') <<  std::right << endl <<  "Path Length:" << std::fixed << ' ' << setw(12) << pathLength << endl;
		cout << setprecision(6) << setw(25) << std::setfill(' ') <<  std::right << "Num Of State Expansions:" << std::fixed << ' ' << setw(12) <<  numOfStateExpansions << endl;
		cout << setprecision(6) << setw(25) << std::setfill(' ') <<  std::right << "Max Q Length:" << std::fixed << ' ' << setw(12) << maxQLength << endl;
		cout << setprecision(6) << setw(25) << std::setfill(' ') <<  std::right << "Actual Running Time:" << std::fixed << ' ' << setprecision(6) << setw(12) <<  actualRunningTime << endl;

        cout << setprecision(6) << setw(25) << std::setfill(' ') <<  std::right << "Num of Deletions from MiddleOfHeap:" << std::fixed << ' ' << setprecision(6) << setw(12) <<  numOfDeletionsFromMiddleOfHeap << endl;        
        cout << setprecision(6) << setw(25) << std::setfill(' ') <<  std::right << "Num of Attempted Node ReExpansions:" << std::fixed << ' ' << setprecision(6) << setw(12) <<  numOfAttemptedNodeReExpansions << endl;


		cout << "================================================================================================================" << endl << endl;	
		
		if(path != "") {
             initgraph(&graphDriver, &graphMode, "", WIDTH, HEIGHT);
			 AnimateSolution(initialState, goalState, path);
             closegraph();
		}
	}
    
    
    /* Show that we have exited without an error. */
    return 0;
}

