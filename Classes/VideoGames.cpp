#include <cstring>
#include <iostream>
#include "VideoGames.h"

using namespace std;

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
