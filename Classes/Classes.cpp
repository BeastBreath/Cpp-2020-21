#include <iostream>
#include <vector>
#include <iomanip>
#include <cstring>
#include <iterator>

#ifndef VIDEOGAMES_H
#define VIDEOGAMES_H
#include "Videogames.h"
#endif

void ADD (vector <VideoGames*> VideoGameList);

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
      ADD(VideoGameList);
    }
    else if (strcmp(input, "PRINT") == 0) {
      /*vector<VideoGames>::interator vglPtr;
      for(vglPtr = VideoGameList.begin(); vglPtr < VideoGameList.end(); vglPtr++){
	std::cout << std::fixed;
	std::cout << std::setprecision(2);
        cout << *vglPtr->getTitle() << endl;
      }*/
    }
    else if (strcmp(input, "SEARCH") == 0) {
      cout << "Type the title of what you want to search: ";
      cin >> input;
      //for(int i = 0; i < VideoGameList.size
    }
    else if (strcmp(input, "DELETE") == 0) {
      
    }
    else if (strcmp(input, "QUIT") == 0) {
      programGoing = false;
    }
    else {
      cout << "Not a valid command. Valid Commands are:\nADD\tSEARCH\tDELETE\tQUIT\n";
    }
  }
}

void ADD (vector <VideoGames*> VideoGameList)
{
  char input[100];
  cout << "What is the type of media you want to add? ";
  cin >> input;
  if((strcmp(input, "VIDEOGAME") == 0) || (strcmp(input, "Videogame") == 0)) {
    VideoGames newVideoGame;
    cout << "What is the title? ";
    cin >> input;
    newVideoGame.setTitle(input);
    cout << "What is the publishing year? ";
    int inputYear;
    cin >> inputYear;
    newVideoGame.setYear(inputYear);
    cout << "What is the publisher? ";
    cin >> input;
    newVideoGame.setPublisher(input);
    VideoGameList.push_back(&newVideoGame);
  }
  
}
