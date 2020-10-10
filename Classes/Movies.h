#include <cstring>

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
  void setDuration(double);
  void setDirector(char* newDirector);
  void setRating(float newRating);
  void printDuration();
  void printDirector();
  void printRating();

};
