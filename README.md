# sudoku_cpp
My program to create a sudoku puzzle using c++.
When executing main file in terminal, you will see a 
full sudoku puzzle printed out. My program will generate 
totally random puzzles (as many and as fast as you want).
The idea behind the project was to attempt making a more 
efficient algorithm than simply using the "brute force" method.  
My method was to find all possible valid locations for each number, 
push those possible valid spaces into a stack of pointers and then 
traverse throught the puzzle pushing and recalculating 
possibilities until the puzzle was filled.

# What I Implemented in this build
- creating classes (Puzzle and Stack)
- using stack datastructure
- backtracking
- understanding of pointers and double pointers in 1d and 2d arrays
