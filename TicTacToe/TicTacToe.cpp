#include <iostream>
#include <cstring>

using namespace std;
const int OPEN = 0;
const int X = 1;
const int O = 2;

bool checkValidAndPlace(int board[][3], char* position, int turn);
bool checkWin(int board[][3], int turn);
bool checkDraw(int board[][3]);
void drawBoard(int board[][3]);

int main()
{
  int board[3][3];
  char input[2];
  for(int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[i][j] = OPEN;
    }
  }
  bool playing = true;
  int turn = X;
  cout << "Start" << endl;
  while(playing) {
    cin >> input;
    if(checkValidAndPlace(board, input, turn)) {
      cout << "Worked!" << endl;
      if(turn == X) {
	if(checkWin(board, turn)) {
	  cout << "X won the game" << endl;
	  playing = false;
	}
	turn = 0;
      }
      else {
	if(checkWin(board, turn)) {
	  cout << "O won the game" << endl;
	  playing = false;
	}
	turn = X;
      }
    }
    else if(checkDraw(board)) {
      cout << "The game is a draw" << endl;
      playing = false;
    }
    //Draw Board
    drawBoard(board);
  }
}


void drawBoard(int board[][3]) {
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      if(board[i][j] == X){
	cout << "X\t";
      }
      else if(board[i][j] == O) {
	cout << "O\t";
      }
      else{
	cout << "\t";
      }
    }
    cout << endl;
  }
}

bool checkValidAndPlace(int board[][3], char* position, int turn) {
  cout << "This is the board spot: " << *board[1] << endl;
  cout << "OPEN: " << OPEN << endl;
  //Check if the input is on the board
  if(!((position[0] == 'a' || position[0] == 'b' || position[0] == 'c') && (position[1] == '1' || position[1] == '2' || position[1] == '3'))) {
    cout << "first" << endl;
    return false;
  }

  //Check if the input is valid
  cout << "Checkin 1\n";
  int row = position[0] - 'a';
  int column = position[1] - '1';
  cout << row << "    " << column << endl;
  cout << board[0][0] << endl;
  cout << board[row][column] << endl;
  if(board[row][column] == OPEN) {
    cout << "Check in 2\n";
    board[row][column] == turn;
    return true;
  }
  return false;
}

bool checkWin(int board[][3], int turn) {
  //Loop to go through three rows/columns
  for(int i = 0; i < 3; i++){
    //Check if player won by horizontal
    if(board[i][0] == turn && board[i][1] == turn && board[i][2] == turn) {
      return true;
    }

    //Check if player won by verticle
    if(board[0][i] == turn && board[1][i] == turn && board[2][i] == turn) {
      return true;
    }

    
  }
  //Check if player won by making three in a row on the diagonals
  if(board[0][0] == turn && board[1][1] == turn && board[2][2] == turn) {
    return true;
  }
  else if(board[0][2] == turn && board[1][1] == turn && board[2][0] == turn) {
    return true;
  }
  return false;
}

bool checkDraw(int board[][3]) {
  for(int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if(board[i][j] == OPEN) {
	return false;
      }
    }
  }
  return true;
}
