/*
Cpp filer for Movies class
Made by Nividh Singh in October 2020
*/

#include <cstring>
#include <iostream>

#ifndef MEDIA_H
#define MEDIA_H
#include "Media.h"
#endif

#ifndef MOVIES_H
#define MOVIES_H
#include "Movies.h"
#endif

using namespace std;

Movies::~Movies() {
delete[] director;
}
double Movies::getDuration() {
  return duration;
}
char* Movies::getDirector() {
  return director;
}
float Movies::getRating() {
  return rating;
}
void Movies::setDuration(double newDuration){
  duration = newDuration;
}
void Movies::setDirector(char* newDirector){
  strcpy(director, newDirector);
}
void Movies::setRating(float newRating) {
  rating = newRating;
}
void Movies::printDuration() {
  cout << duration;
}
void Movies::printDirector() {
  cout << director;
}
void Movies::printRating() {
  cout << rating;
}
