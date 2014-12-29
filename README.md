Magic-Square

Testing and Results:
enum return_value{success=0, fail=1, wrongGameName=2, too_many_input=3, not_enough_input=4, unable_to_read_coordinate=5, invalidMove=6, stalemateOccured=7, ninealmond_user_quit=8, magicsqure_user_quit=9, bad_Alloc=10,unkown_exception=11, other_exeception=12};

1. Test of NineAlmondsGame:
 Test 1:
 Input: CSE332_Lab3
 Output: usage: usage:CSE332_Lab3 arg1 arg2 arg3 or type CSE332_Lab3 -h for help
 return value: 4

 Test 2:
 Input: CSE332_Lab3 as
 Output: usage: usage:CSE332_Lab3 arg1 arg2 arg3 or type CSE332_Lab3 -h for help
 return value: 2

 Test 3:
 Input: CSE332_Lab3 as fd er as f
 Output: usage: usage:CSE332_Lab3 arg1 arg2 arg3 or type CSE332_Lab3 -h for help
 return value: 3

 Test 4:
 Input: CSE332_Lab3 NineAlmonds
 we give a coordinate 6,6 that is out of our gameboard, then we give another coordinate 0,0. The program will print out the move
 is invalid, please try another move. Then we can type new coordinate to try again. The program will not terminate unless you type quit. 

 Test 5:
 Input: CSE332_Lab3 NineAlmonds
 we give a coordinate 2,2, then we give another coordinate 0,0. The program will print out the new gamestate, and ask us to continue this turn or not.
 we type n. Then the program ask me for a new coordinate or to quit. we type quit. The program terminates, and it tells us how many moves we have used so far.
 Rerturn value: 8

 Test 6:
 Input: CSE332_Lab3 NineAlmonds
 I give coordinate 2,2 and 2,0, then program prints out the new game state. Then I type y to continue the turn. Then the program ask me for a new coordinate
 to continue this turn. I type 4,2, the program prints out the new game state. Then we keep playing, here is the moves that leads me to win.
 Turn 1: 2,2 to 2,0 to 4,2 to 2,4 to 0,2
 Turn 2: 3,2 to 1,4
 Turn 3: 1,1 to 1,3
 Turn 4: 1,4 to 1,2
 Turn 5: 0,2 to 2,2
 At the last turn, We type n to not continue the turn, the program indicates we win and we used 5 turns.
 Return value: 0
 
 Test 7:
 Input: CSE332_Lab3 NineAlmonds
 Here is a move we make the game to a stalemate. 
 Turn 1: 2,2 to 0,0
 Turn 2: 2,1 to 4,1
 Turn 3: 2,3 to 4,3 to 2,1 to 0,3 to 2,3
 At last turn, We type n to not continue and the program says a stalemate occurs and we used 3 turns.
 Return value: 7


2. Test of MagicSquare:
 Test 1:
 Input:CSE332_Lab3 -h
 Output:
  usage: CSE332_Lab3 arg1 arg2 arg3

  arg1  - Name of the games: NineAlmonds or MagicSquare   
          e.g CSE332_Lab3 NineAlmonds

  arg2  - (Optional) You can choose the size of the game board in MagicSquare   
          e.g CSE332_Lab3 MagicSquare 6

  arg3  - (Optional) You can choose the size of the game board and the starting number in MagicSquare 
          e.g CSE332_Lab3 MagicSquare 6 -2

 return Value:0

 Test 2:
 Input: CSE332_Lab3 MagicSquare
 The Game enters sucessfully, and it prints out a 3X3 gameboard and correct available game pieces numbers which are 1 to 9. We randomly give a sequence of inputs which will lead the game to stalemate.
 Return Value:7

 Test 3:
 Input: CSE332_Lab3 MagicSquare a
 Output:usage: usage:CSE332_Lab3 arg1 arg2 arg3 or type CSE332_Lab3 -h for help
 Return Value: 1

 Test 4:
 Input: CSE332_Lab3 MagicSquare 5
 The Game enters sucessfully, and it prints out a 5X5 gameboard and correct available game pieces numbers which are 1 to 25. We randomly give a sequence of inputs which will lead the game to stalemate.
 Return Value: 7

 Test 5:
 Input: CSE332_Lab3 MagicSquare 5 4
 The Game enters sucessfully, and it prints out a 5X5 gameboard and correct available game pieces numbers which are 4 to 29. We randomly give a sequence of inputs which will lead the game to stalemate.
 Return Value: 7

 Test 6:
 Input: CSE332_Lab3 MagicSquare 7 -3
 The Game enters sucessfully, and it prints out a 5X5 gameboard and correct available game pieces numbers which are -3 to 45. We randomly give a sequence of inputs which will lead the game to stalemate.
 Return Value: 7

 Test 7:
 Input: CSE332_Lab3 MagicSquare 3 1
 The Game enters sucessfully, and it prints out a 3X3 gameboard and correct available game pieces numbers which are 1 to 9. We go to wikipedia find a solution for this magic square. The solution gives us a correct result.
 Return Value: 0

 Test 8:
 Input: CSE332_Lab3 MagicSquare 5 1
 The Game enters sucessfully, and it prints out a 5X5 gameboard and correct available game pieces numbers which are 1 to 25. We go to wikipedia find a solution for this magic square. The solution gives us a correct result.
 Return Value: 0

 Test 9:
 Input: CSE332_Lab3 MagicSquare 5 1
 The game enters sucessfully, and it asks us to enter a coordinate or type quit. This time, we just type quit. The game terminate and prints "Successfully quit!".
 Return Value: 9

 
Extra Credit:
Implementation:
The extra credit is very similar to the regular MagicSquare. We add two more constructors in the MagicSquare class. The first constructor only takes one input, which is the size of the gameboard. Once the constructor gets a valid
gameboard size n, it will create a nxn gameboard. This gameboard is a nXn string type vector. Moreover, we have an vector which stores all the available gamepiece. For this constructor, our gamepiece are 1 to nXn. Then all the other things
are the same to the regular 3X3 MagicSquare. When the user fills all the positions of the gameboard, we will add all numbers on vertical and horizonatal and see whether they are all equal. If so, the user wins. Otherwise a stalemate occurs.
The next part of the extra credit is just add a starting number of the gamepieces. We ask one more input in the constructor. Then the gamepiece vector will pushback the starting number that user gives. However, sometimes the user will give a
negative number or a number larger than 1. This is easy to solve. For negative number let's say m, the gamepieces will be m to nXn -|m| -1.(0 is included). For number that larger than 1 let's denote i, the gamepieces are i to nXn-i. All the other
things will be same to the previous condition.  


========================================================================
    CONSOLE APPLICATION : CSE332_Lab3 Project Overview
========================================================================

AppWizard has created this CSE332_Lab3 application for you.

This file contains a summary of what you will find in each of the files that
make up your CSE332_Lab3 application.


CSE332_Lab3.vcxproj
    This is the main project file for VC++ projects generated using an Application Wizard.
    It contains information about the version of Visual C++ that generated the file, and
    information about the platforms, configurations, and project features selected with the
    Application Wizard.

CSE332_Lab3.vcxproj.filters
    This is the filters file for VC++ projects generated using an Application Wizard. 
    It contains information about the association between the files in your project 
    and the filters. This association is used in the IDE to show grouping of files with
    similar extensions under a specific node (for e.g. ".cpp" files are associated with the
    "Source Files" filter).

CSE332_Lab3.cpp
    This is the main application source file.

/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named CSE330_Lab3.pch and a precompiled types file named StdAfx.obj.

/////////////////////////////////////////////////////////////////////////////
Other notes:

AppWizard uses "TODO:" comments to indicate parts of the source code you
should add to or customize.

/////////////////////////////////////////////////////////////////////////////

 



 




 
 

