#include <iostream>
#include "Board.h"
using namespace std;



void playermove(Board &B);
bool checkcontinue(Board B);



int main() {
	bool gamerunning = true;


	Board B(' ');

	cout << "Welcome to connect four \n\n Make moves by selecting column\nConsider that columns start counting at 0\n\n";

	while(gamerunning) {
	
	playermove(B);
	B.print();
	gamerunning = checkcontinue(B);
	B.nextturn();
	}

	B.nextturn();	
	cout << "\nGAME OVER!\n\n" << B.turn << " Wins!\n Congratulations";
	cout << "\n " << B.turn << B.turn << B.turn << B.turn << B.turn << B.turn << B.turn << B.turn << B.turn<<endl<<endl;


	
}

bool checkcontinue(Board B) {

	//We check for the symbol that is currently stored in the turn variable
    //since we change turn at the end of the game loop, this should check for the correct symbol that was just inserted.
	//Checkall rows
	int connecteddots = 0;
	//check all rows
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 7; j++) {
			if (B.get(i,j) == B.turn) connecteddots++;
			else connecteddots = 0;
			
			if(connecteddots == 4) return false;
		}
	}

	//check all columns
	//notice that j and i are switched here
	for (int j = 0; j < 7; j++) {
		for (int i = 0; i < 6; i++) {
			if (B.get(i, j) == B.turn) connecteddots++;
			else connecteddots = 0;
		
			if(connecteddots == 4) return false;
		}
	}


	//check diagonals from upper left to lower right

	int diagh = 0;  //Two supporting variables for moving along the diagonals. Check bottom of this file for details
	int diagv = 0;  

	for (int i = 0; i < 6; i++) {
		for(int j = 0; j < 7; j++) {
			if (B.get(j, j + i) == B.turn) diagh++; //note that get() returns 'F' when out of bounds
			else diagh = 0;
		
			if (B.get(j + i,i) == B.turn) diagv++; //note that get() returns 'F' when out of bounds
			else diagv = 0;

			connecteddots = (diagv > diagh) ? diagv : diagh;
			if (connecteddots == 4) return false;
		}
	}

	//check diagonals from upper right to lower left 
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 7; j++) {
			if (B.get(j, 6 -(j + i)) == B.turn) diagh++; //note that get() returns 'F' when out of bounds
			else diagh = 0;

			if (B.get(j, 6-(j-i)) == B.turn) diagv++; //note that get() returns 'F' when out of bounds
			else diagv = 0;

			connecteddots = (diagv > diagh) ? diagv : diagh;
			if (connecteddots == 4) return false;
		}
	}


	return true;
}






void playermove(Board &B) {
	int column = 0;

	do{	
		cout << "Column to play \n";
		cin >> column;
	}while(column<0 || column>6);

	B.insert(column);
}


/*
Regarding the two variables
int diagh = 0;
int diagv = 0;, here is an explanation :
When the game checks the diagonal in the(e.g.top left) corner, it then moves the counter up by oneand checks the two neighboring diagonals.
Basically, after checking the cornering diagonal, it moves one to the sideand one down to check two new diagonals.


After
checking : Now check both     this diagonal          this one
C O O O C O                               O C O O O              O O O O O
O C O O O C------------------------ > O O C O O              C O O O O
O O C O O O                               O O O C O       AND    O C O O O
O O O C O O                               O O O O C              O O C O O

For the way this algorithm is implemented, we invent two different counters, one for moving along horizontallyand one for moving downward.
After checking both new diagonals, the one with the higher number of connected dots is allowed to assign its value to the connecteddots variable.*/
