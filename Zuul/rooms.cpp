#include<cstring>
#include<iostream>
#include<vector>

#ifndef ROOM_H
#define ROOM_H
#include "rooms.h"
#endif

using namespace std;

void rooms::addItem(char* newItem){

}
vector<char*>* rooms::getItems(){
  return &items;
}
void rooms::setTitle(char* newTitle){
  strcpy(title, newTitle);
}
char* rooms::getTitle(){
  return title;
}
void rooms::setDescription (char* newDescription){
  strcpy(description, newDescription);
}
char* rooms::getDescrition(){
  return description;
}
