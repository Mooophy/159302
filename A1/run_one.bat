cls
@echo off
@echo ==============================================================================================================
@echo                                               SEARCH ALGORITHMS 
@echo ==============================================================================================================

@echo (1) Breadth_First_Search
@echo (2) Breadth_First_Search_VList
@echo (3) PDS_No_VList
@echo (4) uniformcost_expandedlist
@echo (5) aStar_ExpList_MisplacedTiles
@echo (6) aStar_ExpList_Manhattan

echo.
set /p selection="Select Algorithm: "
@echo You picked Algorithm # %selection%

echo.
@echo ==============================================================================================================
@echo INIT_STATE (1): 042158367, GOAL_STATE: 123804765 
@echo INIT_STATE (2): 364058271, GOAL_STATE: 123804765
@echo INIT_STATE (3): 281463075, GOAL_STATE: 123804765
@echo INIT_STATE (4): 567408321, GOAL_STATE: 123804765
@echo INIT_STATE (5): 463508721, GOAL_STATE: 123804765
@echo INIT_STATE (6): 471506238, GOAL_STATE: 123804765
echo.
set /p testcase="Select Test Case: "
@echo You picked Test case # %testcase%


if %selection% == 1 (
    set param1= single_run Breadth_First_Search
) else if %selection% == 2 (
    set param1= single_run Breadth_First_Search_VList
) else if %selection% == 3 (
    set param1= single_run PDS_No_VList
) else if %selection% == 4 (
    set param1= single_run uniformcost_expandedlist
) else if %selection% == 5 (
    set param1= single_run aStar_ExpList_MisplacedTiles
) else if %selection% == 6 (
    set param1= single_run aStar_ExpList_Manhattan
)



if %testcase% == 1 (    
    set param2= 042158367 123804765
        
) else if %testcase% == 2 (
    set param2= 364058271 123804765
    
) else if %testcase% == 3 (
    set param2= 281463075 123804765
    
) else if %testcase% == 4 (
   set param2= 567408321 123804765
    
) else if %testcase% == 5 (
    set param2= 463508721 123804765

) else if %testcase% == 6 (
    set param2= 471506238 123804765

) 

set param=%param1% %param2%
echo %param%
main.exe %param%

@echo ==============================================================================================================
@echo nothing follows.

