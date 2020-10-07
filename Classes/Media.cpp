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
