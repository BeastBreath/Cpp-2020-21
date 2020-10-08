#include <cstring>

#ifndef MEDIA_H
#define MEDIA_H
#include "Media.h"
#endif

#ifndef MOVIES_H
#define MOVIES_H
#include "Movies.h"
#endif

int Movies::getDuration() {
  return duration;
}
char* Movies::getDirector() {
  return director;
}
float Movies::getRating() {
  return rating;
}
void Movies::setDuration(int newDuration){
  duration = newDuration;
}
void Movies::setDirector(char* newDirector){
  strcpy(director, newDirector);
}
void Movies::setRating(float newRating) {
  rating = newRating;
}



