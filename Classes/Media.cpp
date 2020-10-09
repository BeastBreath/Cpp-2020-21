#include <cstring>
#include <iostream>

#ifndef MEDIA_H
#define MEDIA_H
#include "Media.h"
#endif

using namespace std;


int Media::getYear() {
  return year;
}
void Media::setYear(int yr) {
  year = yr;
}
char* Media::getTitle(){
  return title;
}
void Media::setTitle(char* ttl) {
  strcpy(title, ttl);
}
void Media::setPublisher(char* newPublisher) {}
char* Media::getPublisher() {}
void Media::setRating(float newRating){}
float Media::getRating() {return 1; }
void Media::setArtist(char* newArtist) {}
char* Media::getArtist() {}
void Media::setDuration(int newDuration) {}
int Media::setDuration() {return 1; }
void Media::setDirector(char* newDirector) {}
char* Media::getDirector() {}
