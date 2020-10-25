/*
Header filer for Videogame class
Made by Nividh Singh in October 2020
*/

#include <cstring>
#include <iostream>

#ifndef MEDIA_H
#define MEDIA_H
#include "Media.h"
#endif

using namespace std;

class VideoGames : public Media {
private:
  float rating;
  char publisher[100];
public:
  float getRating();
  void setRating(float rtng);
  char* getPublisher();
  void setPublisher(char* newPublisher);
};
