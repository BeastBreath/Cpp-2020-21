/*
Cpp filer for Videogame class
Made by Nividh Singh in October 2020
*/

#include <cstring>
#include <iostream>

#ifndef VIDEOGAMES_H
#define VIDEOGAMES_H
#include "VideoGames.h"
#endif

using namespace std;

int VideoGames::getType() {
return 3;
}
float VideoGames::getRating() {
  return rating;
}
void VideoGames::setRating (float rtng) {
  rating = rtng;
}
char* VideoGames::getPublisher() {
  return publisher;
}
void VideoGames::setPublisher (char* pblshr) {
  strcpy(publisher, pblshr);
}
void VideoGames::printRating() {
  cout << rating;
}
void VideoGames::printPublisher() {
  cout << publisher;
}
