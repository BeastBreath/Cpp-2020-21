#include<cstring>
#include<iostream>
#include<vector>

#ifndef ROOM_H
#define ROOM_H
#include "rooms.h"
#endif

using namespace std;

void addItem(char* newItem){

}
vector<char*>* getItems(){
  return &items;
}
void setTitle(char* newTitle){
  strcpy(title, newTitle);
}
char* getTitle(){
  return title;
}
void setDescription (char* newDescription){
  strcpy(description, newDescription);
}
char* getDescrition(){
  return description;
}
