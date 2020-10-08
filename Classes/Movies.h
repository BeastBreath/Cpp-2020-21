#include <cstring>

#ifndef MEDIA_H
#define MEDIA_H
#include "Media.h"
#endif

using namespace std;

class Movies {
 private:
  int duration;
  char director[100];
  float rating;
 public:
  int getDuration();
  char* getDirector();
  float getRating();
  void setDuration(int newDuration);
  void setDirector(char* newDirector);
  void setRating(float newRating);

};
