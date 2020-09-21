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

//Methods
bool checkValidAndPlace(int board[][3], char* position, int turn);
bool checkWin(int board[][3], int turn);
bool checkDraw(int board[][3]);
void drawBoard(int board[][3], int draws, int xWins, int oWins);
void resetBoard(int board[][3]);

//Main Method
int main()
{
  int board[3][3];
  char input[3];
  //Loop that sets everything to open
  for(int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[i][j] = OPEN;
    }
  }
  bool playing = true;
  int turn = X;
  drawBoard(board, 0, 0, 0);
  //Loop for playing the game
  bool gameGoing = true;
  int xWins = 0;
  int oWins = 0;
  int draws = 0;
  //Loop for the whole set of tictactoe game
  while (gameGoing){
    playing = true;
    turn = X;
    //Loop for individual tictactoe games
    while(playing) {
      //Prints out whose turn it is and what needs to happen
      if (turn == X) {
	cout << "It is X's turn. Enter a letter followed by a number for the row and column you want to put your piece in" << endl;
      }
      else {
	cout << "It is O's turn. Enter a letter followed by a number for the row and column you want to put your piece in" << endl;
      }
      cin >> input;
      //Checks if the input is valid
      if(checkValidAndPlace(board, input, turn)) {
	board[input[0] - 'a'][input[1] - '1'] = turn;
	//If X's turn, checks if the game is won and switches turns
	if(turn == X) {
	  if(checkWin(board, turn)) {
	    cout << "X won the game. The final board is as follows" << endl;
	    xWins++;
	    playing = false;
	  }
	  turn = O;
	}
	//If O's turn, check if the game is won and switch to X's turn
	else {
	  if(checkWin(board, turn)) {
	    cout << "O won the game. The final board is as follows" << endl;
	    oWins++;
	    playing = false;
	  }
	  turn = X;
	}
      }
      //Check if the game is a draw and if it a draw then end the game
      else if(checkDraw(board)) {
	cout << "The game is a draw" << endl;
	draws++;
	playing = false;
      }
      //Draw Board
      drawBoard(board, draws, xWins, oWins);
    }
    resetBoard(board);
  }
}

//Method for reseting board
void resetBoard(int board[][3]) {
  for(int i = 0; i < 9; i++) {
    board[i/3][i%3] = OPEN;
  }
}


//Method for drawing board
void drawBoard(int board[][3],int draws,int xWins,int oWins) {
  //Goes through each row
  cout << "Draws: " << draws << "\tX Wins: " << xWins << "\tO Wins: " << oWins << endl;
  cout << "\t   1\t    2\t    3" << endl;
  for(int i = 0; i < 3; i++) {
    //Goes through each column
    cout << "\t\t|\t|" << endl;
    char ch = i + 97;
    cout << "   " << ch << "\t";
    for (int j = 0; j < 3; j++) {
      if(board[i][j] == OPEN) {
	cout << "    ";
      }
      else if(board[i][j] == X) {
	cout << "   X";
      }
      else if(board[i][j] == O) {
	cout << "   O";
      }
      else {
	cout << endl << "error something went wrong" << endl;
	break;
      }
      if (j !=2) {
	cout << "\t|";
      }
      
    }
    cout << endl;
    if(i !=2) {
      cout << "\t________|_______|________" << endl;
    }
    else {
      cout << "\t\t|\t|" << endl;
    }
  }
  cout << endl;
}

//Boolean for checking if the input is valid
bool checkValidAndPlace(int board[][3], char position[3], int turn) {
  //Check if the input is on the board
  if(!((position[0] == 'a' || position[0] == 'b' || position[0] == 'c') && (position[1] == '1' || position[1] == '2' || position[1] == '3'))) {
    return false;
  }
  
  //Check if the input is not taken by another piece
  int row = position[0] - 'a';
  int column = position[1] - '1';
  if(board[row][column] == OPEN) {
    return true;
  }
  cout << "This spot is taken. Pick another spot." << endl;
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
