/*
Cpp filer for Music class
Made by Nividh Singh in October 2020
*/

#include <cstring>

#ifndef MEDIA_H
#define MEDIA_H
#include "Media.h"
#endif

#ifndef MUSIC_H
#define MUSIC_H
#include "Music.h"
#endif


using namespace std;

double Music::getDuration() {
  return duration;
}
void Music::setDuration (double newDuration) {
  duration = newDuration;
}
char* Music::getPublisher() {
  return publisher;
}
void Music::setPublisher (char* newPublisher) {
  strcpy(publisher, newPublisher);
}
char* Music::getArtist() {
  return artist;
}
void Music::setArtist (char* newArtist) {
  strcpy(artist, newArtist);
}

