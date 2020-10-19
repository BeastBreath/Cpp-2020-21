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

void ADD (vector <Media*> *MediaList);
void PRINT(vector <Media*> *MediaList);
void SEARCH(vector <Media*> *MediaList);
void DELETE(vector <Media*> *MediaList);
void printMedia(Media* med);

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
    
    if (strcmp(input, "ADD") == 0) {
      ADD(&MediaList);
    }
    else if (strcmp(input, "PRINT") == 0) {
      PRINT(&MediaList);
    }
    else if (strcmp(input, "SEARCH") == 0) {
      //cout << "Type the title of what you want to search: ";
      //cin >> input;
      SEARCH(&MediaList);
    }
    else if (strcmp(input, "DELETE") == 0) {
      DELETE(&MediaList);
    }
    else if (strcmp(input, "QUIT") == 0) {
      programGoing = false;
    }
    else {
      cout << "Your input: "<< input << " .Not a valid command. Valid Commands are:\nSEARCH   DELETE   QUIT   ADD\n";
    }
  }
}

void printMedia(Media* med) {
  //Maybe do this later if I feel like it probably not going to do it though
}


void DELETE (vector<Media* > *MediaList) {

  char input[100];
  cout << "What do you want to delete using? T for title and Y for year: ";
  cin >> input;
  int counter = 0;
  if(strcmp(input, "Y") == 0) {
    int inputYear = -1;
    cin >> inputYear;
    vector<Media*>:: iterator mlIterator;
    cout << "You are going to be deleting the following: \n";
    for(mlIterator = MediaList->begin(); mlIterator < MediaList->end(); mlIterator++) {
      if (inputYear == (*mlIterator)->getYear()) {
        (*mlIterator)->printTitle();
	cout << endl;
	counter++;
      }
    }
    if(counter == 0) {
      cout << "Nothing was released in that year. Please try again\n";
      DELETE(MediaList);
      return;
    }
    cout << "Are you sure you want to delete these? Y for yes and N for no" << endl;
    char ch;
    cin >> ch;
    if(ch == 'Y' || ch == 'y') {
      //Delete those
      for (int i = 0; i < counter; i++) {
        vector<Media*>::iterator mlIterator;
        int index = 0;
        for(mlIterator = MediaList->begin(); mlIterator < MediaList->end(); mlIterator++) {
          index++;
          if(inputYear == (*mlIterator)->getYear()) {
            MediaList->erase(mlIterator);
          }
        }
      }
    }
  }
  else if(strcmp(input, "T") == 0) {
    cin >> input;
    vector<Media*>:: iterator mlIterator;
    cout << "You are going to be deleting the following:\n";
    for(mlIterator = MediaList->begin(); mlIterator < MediaList->end(); mlIterator++) {
      if (strcmp(input,(*mlIterator)->getTitle()) == 0) {
        (*mlIterator)->printTitle();
	counter++;
      }
    }
    if(counter == 0) {
      cout << "Nothing matching that title was found. Please try again\n";
      DELETE(MediaList);
      return;
    }
    cout << "Are you sure you want to delete these? Y for yes and N for no" << endl;
    char ch;
    cin >> ch;
    if(ch == 'Y' || ch == 'y') {
      //Delete those
      for (int i = 0; i < counter; i++) {
	vector<Media*>::iterator mlIterator;
	int index = 0;
	for(mlIterator = MediaList->begin(); mlIterator < MediaList->end(); mlIterator++) {
	  index++;
	  if(strcmp(input, (*mlIterator)->getTitle()) == 0) {
	    MediaList->erase(mlIterator);
	  }
	}
      }
    }
  }
  else {
    cout << "Not a valid command. Valid commands are T and Y" << endl;
    DELETE(MediaList);
    return;
  }
  cout << "They have been deleted\n";
}

void SEARCH (vector<Media* > *MediaList) {
  char input[100];
  cout << "What do you want to search? T for title and Y for year: ";
  cin >> input;
  if(strcmp(input, "Y") == 0) {
    int inputYear = -1;
    cin >> inputYear;
    vector<Media*>:: iterator mlIterator;
    for(mlIterator = MediaList->begin(); mlIterator < MediaList->end(); mlIterator++) {
      if (inputYear == (*mlIterator)->getYear()) {
	(*mlIterator)->printTitle();
	//cout << *(*mlIterator)->getTitle() << endl << "asdfasdfasdf\n";
      }
    }
  }
  else if(strcmp(input, "T") == 0) {
    cin >> input;
    vector<Media*>:: iterator mlIterator;
    for(mlIterator = MediaList->begin(); mlIterator < MediaList->end(); mlIterator++) {
      if (strcmp(input, (*mlIterator)->getTitle()) == 0) {
	(*mlIterator)->printTitle();
      }
    }
  }
  else {
    cout << "Not a valid command. Valid commands are T and Y" << endl;
    SEARCH(MediaList);
  }
}


      
      
void PRINT (vector<Media*> *MediaList) {
  vector<Media*>:: iterator mlIterator;
  for(mlIterator = MediaList->begin(); mlIterator < MediaList->end(); mlIterator++) {
    //(*mlIterator)->printTitle();
    cout << (*mlIterator)->getTitle() << endl;
  }
}



void ADD (vector<Media*> *MediaList)
{
  char input[100];
  int inputInteger = -1;
  float inputFloat = -1;
  double inputDouble = -1;
  cout << "What is the type of media you want to add? ";
  cin.get(input, 100);
  cin.clear();
  cin.ignore(1000, '\n');
  if((strcmp(input, "VIDEOGAME") == 0) || (strcmp(input, "Videogame") == 0)) {
    VideoGames* newVideoGame = new VideoGames;
    cout << "What is the title? ";
    cin.get(input, 100);
    cin.clear();
    cin.ignore(1000, '\n');
    newVideoGame->setTitle(input);
    cout << "What is the publishing year? ";
    cin >> inputInteger;
    newVideoGame->setYear(inputInteger);
    cout << "What is the publisher? ";
    
    cin.get(input, 100);
    cin.clear();
    cin.ignore(1000, '\n');
    newVideoGame->setPublisher(input);
    cout << "What is the rating? ";
    cin >> inputInteger;
    newVideoGame->setRating(inputInteger);
    MediaList->push_back(newVideoGame);
    newVideoGame->printTitle();
    //(MediaList->begin())->printTitle();
    return;
  }
  else if(strcmp(input, "MUSIC") == 0) {
    Music *newMusic = new Music;
    cout << "What is the title? ";
    cin.get(input, 100);
    cin.clear();
    cin.ignore(1000, '\n');
    newMusic->setTitle(input);
    cout << "Whos is the artist? ";
    cin.get(input, 100);
    cin.clear();
    cin.ignore(1000, '\n');
    newMusic->setArtist(input);
    cout << "Who is the publisher? ";
    cin.get(input, 100);
    cin.clear();
    cin.ignore(1000, '\n');
    newMusic->setPublisher(input);
    cout << "What year was it published? ";
    cin >> inputInteger;
    newMusic->setYear(inputInteger);
    cout << "How long (in seconds) is the song? ";
    cin >> inputDouble;
    newMusic->setDuration(inputDouble);
    MediaList->push_back(newMusic);
    return;
  }
  else if(strcmp(input, "MOVIE") == 0) {
    Movies* newMovie = new Movies;
    cout << "What is the title? ";
    cin.get(input, 100);
    cin.clear();
    cin.ignore(1000, '\n');
    newMovie->setTitle(input);
    cout << "Who is the director? ";
    cin.get(input, 100);
    cin.clear();
    cin.ignore(1000, '\n');
    newMovie->setDirector(input);
    cout << "What year was it released? ";
    cin >> inputInteger;
    newMovie->setYear(inputInteger);
    cout << "How long (in minutes) is the movie? ";
    cin >> inputDouble;
    newMovie->setDuration(inputDouble);
    cout << "What is the rating? ";
    cin >> inputFloat;
    newMovie->setRating(inputFloat);
    MediaList->push_back(newMovie);
    return;
  }
  else {
    cout << "The valid catagories of media are:\n";
    cout << "VIDEOGAME   MUSIC   MOVIE\n";
    ADD(MediaList);
  }
}
