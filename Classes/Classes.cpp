#include <iostream>
#include <vector>
#include <iomanip>
#include <cstring>
#include <iterator>

#ifndef MEDIA_H
#define MEDIA_H
#include "Media.h"
#endif

#ifndef VIDEOGAMES_H
#define VIDEOGAMES_H
#include "Videogames.h"
#endif

#ifndef MUSIC_H
#define MUSIC_H
#include "Music.h"
#endif

#ifndef MOVIES_H
#define MOVIES_H
#include "MOVIES.h"
#endif

void ADD (vector <Media*> MediaList);
void PRINT(vector <Media*> MediaList);
//void SEARCH(vector <Media*> MediaList);
//void DELETE(vector <Media*> MediaList);

using namespace std;

int main ()
{
  cout << "START\n";
  vector<Media*> MediaList;
  char input[100];
  bool programGoing = true;
  while (programGoing) {
    cin.get(input, 100);
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "INPUT: " << input << endl;
    
    if (strcmp(input, "ADD") == 0) {
      ADD(MediaList);
    }
    else if (strcmp(input, "PRINT") == 0) {
      PRINT(MediaList);
    }
    else if (strcmp(input, "SEARCH") == 0) {
      //cout << "Type the title of what you want to search: ";
      //cin >> input;
    }
    else if (strcmp(input, "DELETE") == 0) {
      
    }
    else if (strcmp(input, "QUIT") == 0) {
      programGoing = false;
    }
    else {
      cout << "Not a valid command. Valid Commands are:\nSEARCH   DELETE   QUIT   ADD\n";
    }
  }
}

void PRINT (vector <Media*> MediaList) {
}



void ADD (vector <Media*> MediaList)
{
  char input[100];
  int inputInteger = -1;
  float inputFloat = -1;
  cout << "What is the type of media you want to add? ";
  cin.get(input, 100);
  cin.clear();
  cin.ignore(1000, '\n');
  if((strcmp(input, "VIDEOGAME") == 0) || (strcmp(input, "Videogame") == 0)) {
    VideoGames newVideoGame;
    cout << "What is the title? ";
    cin.get(input, 100);
    cin.clear();
    cin.ignore(1000, '\n');
    newVideoGame.setTitle(input);
    cout << "What is the publishing year? ";
    cin >> inputInteger;
    newVideoGame.setYear(inputInteger);
    cout << "What is the publisher? ";
    cin.get(input, 100);
    cin.clear();
    cin.ignore(1000, '\n');
    newVideoGame.setPublisher(input);
    cout << "What is the rating? ";
    cin >> inputInteger;
    newVideoGame.setRating(inputInteger);
    MediaList.push_back(&newVideoGame);
    return;
  }
  else if(strcmp(input, "MUSIC") == 0) {
    Music newMusic;
    cout << "What is the title? ";
    cin.get(input, 100);
    cin.clear();
    cin.ignore(1000, '\n');
    newMusic.setTitle(input);
    cout << "Who is the artist? ";
    cin.get(input, 100);
    cin.clear();
    cin.ignore(1000, '\n');
    newMusic.setArtist(input);
    cout << "Who is the publisher? ";
    cin.get(input, 100);
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "What year was it published? ";
    cin >> inputInteger;
    newMusic.setYear(inputInteger);
    cout << "How long (in seconds) is the song? ";
    cin >> inputInteger;
    newMusic.setDuration(inputInteger);
    MediaList.push_back(&newMusic);
    return;
  }
  else if(strcmp(input, "MOVIE") == 0) {
    Movies newMovie;
    cout << "What is the title? ";
    cin.get(input, 100);
    cin.clear();
    cin.ignore(1000, '\n');
    newMovie.setTitle(input);
    cout << "Who is the director? ";
    cin.get(input, 100);
    cin.clear();
    cin.ignore(1000, '\n');
    newMovie.setDirector(input);
    cout << "What year was it released? ";
    cin >> inputInteger;
    newMovie.setYear(inputInteger);
    cout << "How long (in minutes) is the movie? ";
    cin >> inputInteger;
    newMovie.setDuration(inputInteger);
    cout << "What is the rating? ";
    cin >> inputFloat;
    newMovie.setRating(inputFloat);
    MediaList.push_back(&newMovie);
    return;
  }
  else {
    cout << "The valid catagories of media are:\n";
    cout << "VIDEOGAME   MUSIC   MOVIE\n";
      
  }
}
