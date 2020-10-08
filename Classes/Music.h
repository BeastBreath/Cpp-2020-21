#include <cstring>

#ifndef MEDIA_H
#define MEDIA_H
#include "Media.h"
#endif

using namespace std;

class Music : public Media
{
 private:
  char artist[100];
  char publisher[100];
  int duration;
 public:
  char* getArtist();
  char* getPublisher();
  int getDuration();
  void setArtist(char* newArtist);
  void setPublisher(char* newPublisher);
  void setDuration(int newDuration);
};
