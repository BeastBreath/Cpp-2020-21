/*
This is the main cpp file for the classes program.
Made by Nividh Singh on October 2020
*/

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

//Main method
int main ()
{
  cout << "The program is starting. Please add a media type by typing ADD\n";
  vector<Media*> MediaList;//Vector for storing all Media
  char input[100];//Charector array for input
  bool programGoing = true;//Boolean to keep track of if the program is going or not
//while loop that keeps going until the user types quit
  while (programGoing) {
    cin.get(input, 100);
    cin.clear();
    cin.ignore(1000, '\n');
    //The following if and else if statements take what the user inputs and calls that function
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

//DELETE function
void DELETE (vector<Media* > *MediaList) {

  char input[100];
  cout << "What do you want to delete using? T for title and Y for year: ";
  cin >> input;
  int counter = 0;
	//If the input is year, the program searches by year
  if(strcmp(input, "Y") == 0) {
    int inputYear = -1;//Variable for storing input year
    cin >> inputYear;
    vector<Media*>:: iterator mlIterator;//Iterator to go through vector
    cout << "You are going to be deleting the following: \n";
	  //Loop that goes through everything and prints out the ones that match the year
    for(mlIterator = MediaList->begin(); mlIterator < MediaList->end(); mlIterator++) {
      if (inputYear == (*mlIterator)->getYear()) {
        (*mlIterator)->printTitle();
	cout << endl;
	counter++;//This keeps track of how many items matched that year
      }
    }
	  //If the counter is zero, we ask the user to try again
    if(counter == 0 && MediaList->size() != 0) {
      cout << "Nothing was released in that year. Please try again\n";
      DELETE(MediaList);
      return;
    }
	  else if(counter ==0) {
	  cout << "You don't have anything stored, please add something first" << endl;
		  return;
	  }
    cout << "Are you sure you want to delete these? Y for yes and N for no" << endl;
    char ch;
    cin >> ch;
	  //If user says yes, then we go through the vector again
    if(ch == 'Y' || ch == 'y') {
      //Goes through the vector the same number of times as the number of things that matched that year
      for (int i = 0; i < counter; i++) {
        vector<Media*>::iterator mlIterator;
        int index = 0;
	      //Goes through vector
        for(mlIterator = MediaList->begin(); mlIterator < MediaList->end(); mlIterator++) {
          index++;
		//If the input year is the same, then delete that and restart the iterator
          if(inputYear == (*mlIterator)->getYear()) {
            MediaList->erase(mlIterator);
		  mlIterator = MediaList->end();
          }
        }
      }
    }
  }
	//If the user says title, do the same thing 
  else if(strcmp(input, "T") == 0) {
    cin >> input;
    vector<Media*>:: iterator mlIterator;
    cout << "You are going to be deleting the following:\n";
	  //Go through vector
    for(mlIterator = MediaList->begin(); mlIterator < MediaList->end(); mlIterator++) {
      //If it matches, that print it out
	    if (strcmp(input,(*mlIterator)->getTitle()) == 0) {
        (*mlIterator)->printTitle();
	counter++;
      }
    }
	  //If the counter is zero, we ask the user to try again
    if(counter == 0 && MediaList->size() != 0) {
      cout << "Nothing was released in that year. Please try again\n";
      DELETE(MediaList);
      return;
    }
	  else if(counter ==0) {
	  cout << "You don't have anything stored, please add something first" << endl;
		  return;
	  }
	  
    cout << "Are you sure you want to delete these? Y for yes and N for no" << endl;
    char ch;
    cin >> ch;
    if(ch == 'Y' || ch == 'y') {
      //Go through vector the number of times that we have items in there
      for (int i = 0; i < counter; i++) {
	vector<Media*>::iterator mlIterator;
	int index = 0;
	      //Go through iterator
	for(mlIterator = MediaList->begin(); mlIterator < MediaList->end(); mlIterator++) {
	  index++;
		//If it matches, then print it out and restart iterator
	  if(strcmp(input, (*mlIterator)->getTitle()) == 0) {
	    MediaList->erase(mlIterator);
		  mlIterator = MediaList->end();
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

//Search Method
void SEARCH (vector<Media* > *MediaList) {
  char input[100];
  cout << "What do you want to search? T for title and Y for year: ";
  cin >> input;
	//If user says year, then search using year
  if(strcmp(input, "Y") == 0) {
    int inputYear = -1;
    cin >> inputYear;
    vector<Media*>:: iterator mlIterator;
	  //Go through the vector
    for(mlIterator = MediaList->begin(); mlIterator < MediaList->end(); mlIterator++) {
      //Print out title if the year matches
	    if (inputYear == (*mlIterator)->getYear()) {
	(*mlIterator)->printTitle();
		    cout << endl;
	//cout << *(*mlIterator)->getTitle() << endl << "asdfasdfasdf\n";
      }
    }
  }
	//If the user said title do the same thing using the title
  else if(strcmp(input, "T") == 0) {
    cin >> input;
    vector<Media*>:: iterator mlIterator;
	  //Go through the vector
    for(mlIterator = MediaList->begin(); mlIterator < MediaList->end(); mlIterator++) {
      //Print out the title if the title matches
	    if (strcmp(input, (*mlIterator)->getTitle()) == 0) {
	(*mlIterator)->printTitle();
		    cout << endl;
      }
    }
  }
  else {
    cout << "Not a valid command. Valid commands are T and Y" << endl;
    SEARCH(MediaList);
  }
}
 
//Print function
void PRINT (vector<Media*> *MediaList) {
  vector<Media*>:: iterator mlIterator;
  //Go through the vector and print every title
	for(mlIterator = MediaList->begin(); mlIterator < MediaList->end(); mlIterator++) {
    //(*mlIterator)->printTitle();
    cout << (*mlIterator)->getTitle() << endl;
  }
}

//ADD function
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
	//If the user said they want to add a video game, music, or movie, then go to that if statement
	//For each of them, the program prompts each of the fields, and then inputs that field into the object
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
