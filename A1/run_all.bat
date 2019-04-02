cls
@echo off
@echo ====================================================================================================================================================
@echo                                               SEARCH ALGORITHMS  
@echo                                                  2019 version
@echo ====================================================================================================================================================
@echo EXPERIMENT (1)
@echo ====================================================================================================================================================
@echo INIT_STATE_#1:  042158367     GOAL STATE: 123804765
@echo ====================================================================================================================================================
@echo  ALGORITHM		         PATH_LENGTH	STATE_EXPANSIONS    MAX_QLENGTH	 RUNNING_TIME  DELETIONS_MIDDLE_HEAP ATTEMPTED_REEXPANSIONS
@echo ====================================================================================================================================================
set INIT_STATE = 042158367
set GOAL_STATE = 123804765

main.exe "batch_run" "Breadth_First_Search"      "042158367" "123804765"
main.exe "batch_run" "Breadth_First_Search_VList"      "042158367" "123804765"

main.exe "batch_run" "PDS_No_VList" 		"042158367" "123804765"
main.exe "batch_run" "uniformcost_expandedlist" 		"042158367" "123804765"
  
main.exe "batch_run" "aStar_ExpList_MisplacedTiles"      "042158367" "123804765"
main.exe "batch_run" "aStar_ExpList_Manhattan" "042158367" "123804765"

@echo ====================================================================================================================================================
@echo EXPERIMENT (2)
@echo ====================================================================================================================================================
@echo INIT_STATE_#2: 364058271     GOAL STATE: 123804765
@echo ====================================================================================================================================================
@echo  ALGORITHM		         PATH_LENGTH	STATE_EXPANSIONS    MAX_QLENGTH	 RUNNING_TIME  DELETIONS_MIDDLE_HEAP ATTEMPTED_REEXPANSIONS
@echo ====================================================================================================================================================
set INIT_STATE = "364058271"
set GOAL_STATE = "123804765"


main.exe "batch_run" "Breadth_First_Search"  "364058271" "123804765"
main.exe "batch_run" "Breadth_First_Search_VList"  "364058271" "123804765"

main.exe "batch_run" "PDS_No_VList" 		"364058271" "123804765"
main.exe "batch_run" "uniformcost_expandedlist" 	"364058271" "123804765"
  
main.exe "batch_run" "aStar_ExpList_MisplacedTiles"     "364058271" "123804765"
main.exe "batch_run" "aStar_ExpList_Manhattan" 			"364058271" "123804765"





@echo ====================================================================================================================================================
@echo EXPERIMENT (3)
@echo ====================================================================================================================================================
@echo INIT_STATE_#3: 281463075     GOAL STATE: 123804765
@echo ====================================================================================================================================================
@echo  ALGORITHM		         PATH_LENGTH	STATE_EXPANSIONS    MAX_QLENGTH	 RUNNING_TIME  DELETIONS_MIDDLE_HEAP ATTEMPTED_REEXPANSIONS
@echo ====================================================================================================================================================
set INIT_STATE = "281463075"
set GOAL_STATE = "123804765"

main.exe "batch_run" "Breadth_First_Search"  "281463075" "123804765"
main.exe "batch_run" "Breadth_First_Search_VList"  "281463075" "123804765"

main.exe "batch_run" "PDS_No_VList" 		"281463075" "123804765"
main.exe "batch_run" "uniformcost_expandedlist" 	"281463075" "123804765"

main.exe "batch_run" "aStar_ExpList_MisplacedTiles"     "281463075" "123804765"
main.exe "batch_run" "aStar_ExpList_Manhattan" 			"281463075" "123804765"



@echo ====================================================================================================================================================
@echo EXPERIMENT (4)
@echo ====================================================================================================================================================
@echo INIT_STATE_#4: 567408321     GOAL STATE: 123804765
@echo ====================================================================================================================================================
@echo  ALGORITHM		         PATH_LENGTH	STATE_EXPANSIONS    MAX_QLENGTH	 RUNNING_TIME  DELETIONS_MIDDLE_HEAP ATTEMPTED_REEXPANSIONS
@echo ====================================================================================================================================================
set INIT_STATE = "567408321"
set GOAL_STATE = "123804765"

main.exe "batch_run" "Breadth_First_Search"  "567408321" "123804765"
main.exe "batch_run" "Breadth_First_Search_VList"  "567408321" "123804765"

main.exe "batch_run" "PDS_No_VList" 		"567408321" "123804765"
main.exe "batch_run" "uniformcost_expandedlist" 	"567408321" "123804765"
 
main.exe "batch_run" "aStar_ExpList_MisplacedTiles"     "567408321" "123804765"
main.exe "batch_run" "aStar_ExpList_Manhattan" 			"567408321" "123804765"



@echo ====================================================================================================================================================
@echo EXPERIMENT (5)
@echo ====================================================================================================================================================
@echo INIT_STATE_#5: 463508721     GOAL STATE: 123804765
@echo ====================================================================================================================================================
@echo  ALGORITHM		         PATH_LENGTH	STATE_EXPANSIONS    MAX_QLENGTH	 RUNNING_TIME  DELETIONS_MIDDLE_HEAP ATTEMPTED_REEXPANSIONS
@echo ====================================================================================================================================================
set INIT_STATE = "463508721"
set GOAL_STATE = "123804765"

main.exe "batch_run" "Breadth_First_Search"  "463508721" "123804765"
main.exe "batch_run" "Breadth_First_Search_VList"  "463508721" "123804765"

main.exe "batch_run" "PDS_No_VList" 		"463508721" "123804765"
main.exe "batch_run" "uniformcost_expandedlist" 	"463508721" "123804765"

main.exe "batch_run" "aStar_ExpList_MisplacedTiles"     "463508721" "123804765"
main.exe "batch_run" "aStar_ExpList_Manhattan" 			"463508721" "123804765"

@echo ====================================================================================================================================================
@echo EXPERIMENT (6)
@echo ====================================================================================================================================================
@echo INIT_STATE_#5: 471506238     GOAL STATE: 123804765
@echo ====================================================================================================================================================
@echo  ALGORITHM		         PATH_LENGTH	STATE_EXPANSIONS    MAX_QLENGTH	 RUNNING_TIME  DELETIONS_MIDDLE_HEAP ATTEMPTED_REEXPANSIONS
@echo ====================================================================================================================================================
set INIT_STATE = "471506238"
set GOAL_STATE = "123804765"

main.exe "batch_run" "Breadth_First_Search"  "471506238" "123804765"
main.exe "batch_run" "Breadth_First_Search_VList"  "471506238" "123804765"

main.exe "batch_run" "PDS_No_VList" 		"471506238" "123804765"
main.exe "batch_run" "uniformcost_expandedlist" 	"471506238" "123804765"

main.exe "batch_run" "aStar_ExpList_MisplacedTiles"     "471506238" "123804765"
main.exe "batch_run" "aStar_ExpList_Manhattan" 			"471506238" "123804765"

@echo nothing follows.

