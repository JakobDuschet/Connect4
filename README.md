This is a simple connect 4 game, done mostly as a coding exercise
There are some noteworthy unelegancies in the code, of which the most obvious is the way the winning condition is checked:

The winning condition is checked first for every row, then every column
After that, the program checks for every "up-left -> down right" diagonal on the board.
After that, it checks for every "up-right -> down left" diagonal

The flaw in how this is done is that the game also checks "virtual" diagonals which are out of bounds for the game board



This was done because for such a small game board, readability and intuitive understanding of the code is easier. 
We check a lot of unnecessary diagonals, but performance doesn't really suffer here since we are dealing with a small game.


Another noteworthy flaw is that the dimensions of the game board are hardcoded. This has no special reason as to why it was done and could be implemented more elegantly.

Finally, Players can insert Tokens into rows that are already full and effectively skip their turn that way.


