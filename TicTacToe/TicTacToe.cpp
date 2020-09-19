/*
Made by Nividh Singh on 9/19/20
This program is a two player tic tac toe game
*/
#include <iostream>
#include <cstring>

using namespace std;

//Constants used in the program
const int OPEN = 0;
const int X = 1;
const int O = 2;

bool checkValidAndPlace(int board[][3], char* position, int turn);
bool checkWin(int board[][3], int turn);
bool checkDraw(int board[][3]);
void drawBoard(int board[][3]);

//Main Method
int main()
{
  int board[3][3];
  char input[2];
  //Loop that sets everything to open
  for(int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[i][j] = OPEN;
      cout << board[i][j];
    }
    cout << endl;
  }
  bool playing = true;
  int turn = X;
  cout << "Start" << endl;
  while(playing) {
    cout << "1: " << board[0][0] << endl;
    cin >> input;
    cout << "2: " << board[0][0] << endl;
    if(checkValidAndPlace(board, input, turn)) {

      board[input[0] - 'a'][input[1] - '1'] = turn;
      if(turn == X) {
	if(checkWin(board, turn)) {
	  cout << "X won the game" << endl;
	  playing = false;
	}
	turn = O;
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

//Method for drawing board
void drawBoard(int board[][3]) {
  //Goes through each row
  for(int i = 0; i < 3; i++) {
    //Goes through each column
    for (int j = 0; j < 3; j++) {
      cout << board[i][j];
    }
    cout << endl;
  }

}

//Boolean for checking if the input is valid
bool checkValidAndPlace(int board[][3], char position[2], int turn) {
  //Check if the input is on the board
  if(!((position[0] == 'a' || position[0] == 'b' || position[0] == 'c') && (position[1] == '1' || position[1] == '2' || position[1] == '3'))) {
    return false;
  }

  //Check if the input is not taken by another piece
  int row = position[0] - 'a';
  int column = position[1] - '1';
  cout << "turn: " << turn << endl;
  if(board[row][column] == OPEN) {
    return true;
  }
  return false;
}

//Check if a player has won
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

//Check if the game is a draw
bool checkDraw(int board[][3]) {
  //Goes through each row
  for(int i = 0; i < 3; i++) {
    //Goes through each column
    for (int j = 0; j < 3; j++) {
      if(board[i][j] == OPEN) {
	return false;//if anything is open, it returns false
      }
    }
  }
  return true;
}
