/*
Header filer for Movies class
Made by Nividh Singh in October 2020
*/

#include <cstring>
#include <iostream>

#ifndef MEDIA_H
#define MEDIA_H
#include "Media.h"
#endif

using namespace std;

class Movies : public Media {
 private:
  double duration;
  char director[100];
  float rating;
 public:
  double getDuration();
  char* getDirector();
  float getRating();
  void setDuration(double newDuration);
  void setDirector(char* newDirector);
  void setRating(float newRating);
  void printDuration();
  void printDirector();
  void printRating();
 int getType();
};
