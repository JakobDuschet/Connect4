This is a simple connect 4 game, done mostly as a coding exercise
There are some noteworthy unelegancies in the code, of which the most obvious is the way the winning condition is checked:

The winning condition is checked first for every row, then every column
After that, the program checks for every "up-left -> down right" diagonal on the board.
After that, it checks for every "up-right -> down left" diagonal

The flaw in how this is done is that the game also checks "virtual" diagonals which are out of bounds for the game board

For example, in this simplified game board, the diagonal marked by "C"s would not need to be checked, because there is no way to connect 4 along this diagonal.
O O O O C O       gets checked as         O O O O C O 
O O O O O C ------------------------>     O O O O O C 
O O O O O O                               O O O O O O C 
O O O O O O                               O O O O O O   C

This was done because for such a small game board, readability and intuitive understanding of the code is easier. 
We check a lot of unnecessary diagonals, but performance doesn't really suffer here since we are dealing with a small game.


Another noteworthy flaw is that the dimensions of the game board are hardcoded. This has no special reason as to why it was done and could be implemented more elegantly.






Regarding the two variables 
int diagh = 0;  	
int diagv = 0; , here is an explanation:
When the game checks the diagonal in the (e.g. top left) corner, it then moves the counter up by one and checks the two neighboring diagonals.
Basically, after checking the cornering diagonal, it moves one to the side and one down to check two new diagonals.


After 
checking:              Now check both     this diagonal          this one
C O O O C O                               O C O O O              O O O O O
O C O O O C ------------------------>     O O C O O              C O O O O
O O C O O O                               O O O C O       AND    O C O O O
O O O C O O                               O O O O C              O O C O O

For the way this algorithm is implemented, we invent two different counters, one for moving along horizontally and one for moving downward.
After checking both new diagonals, the one with the higher number of connected dots is allowed to assign its value to the connecteddots variable.
