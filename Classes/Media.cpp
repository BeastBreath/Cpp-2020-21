/*
Cpp filer for Media class
Made by Nividh Singh in October 2020
*/

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
void Media::printTitle() {
  cout << title;
}
void Media::printYear() {
  cout << year;
}
Media::Media() {
  //NA = new char[5];
strcpy(NA, "N/A\0");
}
void Media::setPublisher(char* newPublisher) {}
char* Media::getPublisher() {}
void Media::setRating(float newRating){}
float Media::getRating() {return -1; }
void Media::setArtist(char* newArtist) {}
char* Media::getArtist() {}
void Media::setDuration(double newDuration) {}
double Media::getDuration() {return -1; }
void Media::setDirector(char* newDirector) {}
char* Media::getDirector() {}
void Media::printPublisher() {}
void Media::printRating() {}
void Media::printArtist() {}
void Media::printDuration() {}
void Media::printDirector() {}
int Media::getType() {}
