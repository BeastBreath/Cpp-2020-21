
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
  void printRating();
  void printPublisher();
};
