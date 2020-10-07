#include <iostream>
#include <vector>
#include <iomanip>
#include <cstring>
#include "Videogames.h"

using namespace std;

int main ()
{
  cout << "START\n";
  vector<VideoGames*> VideoGameList;
  char input[100];
  bool programGoing = true;
  while (programGoing) {
    cin >> input;
    if (strcmp(input, "ADD") == 0) {
      cout << "What is the type of media you want to add? ";
      cin >> input;
      if((strcmp(input, "VIDEOGAMES") == 0) || (strcmp(input, "Videogame") == 0)) {
	VideoGames newVideoGame;
	cout << "What is the title? ";
	cin >> input;
	newVideoGame.setTitle(input);
      }
    }
    else if (strcmp(input, "SEARCH") == 0) {
      
    }
    else if (strcmp(input, "DELETE") == 0) {
      
    }
    else if (strcmp(input, "QUIT") == 0) {
      
    }
    else {
      cout << "Not a valid command. Valid Commands are:\nADD\tSEARCH\tDELETE\tQUIT\n";
    }
  }
}
