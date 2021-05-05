#include <iostream>
using namespace std;


class Board {
private:
	char Content[6][7];  // Represents the physical board of the game, with 6 rows and 7 columns
public:
	char turn = 'X';
	void nextturn();
	void insert(int column); //Insert piece into the game board
	void print();
	char get(int i, int j);
	Board(char c) {
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 7; j++) {
				Content[i][j] = c;

			}

		}

	}
};


char Board::get(int i, int j) {

	if (i < 6 && j < 7) return Content[i][j];
	else return 'F';
}


void Board::print() {
	for (int i = 0; i < 6; i++) {
		cout << endl;
		for (int j = 0; j < 7; j++) {

			cout << "|" << Content[i][j] << "|";

		}


	}

	cout << "\n\n\n";

}


void Board::insert(int column) {

	//INSERT TO THE FIRST EMPTY ELEMENT FROM THE BOTTOM;	

	for (int i = 0; i < 6; i++) {
		if (Content[5 - i][column] != 'X' && Content[5 - i][column] != 'O') {
			Content[5 - i][column] = turn;
			break;
		}
	}

}

 void Board::nextturn() {
	if (turn == 'X') turn = 'O';
	else turn = 'X';
}
