#include<cstring>
#include<iostream>
#include<vector>

#ifndef ROOMS_H
#define ROOMS_H
#include "rooms.h"
#endif

using namespace std;

void rooms::addItem(char* newItem){
  items.push_back(newItem);
}
void rooms::deleteItem(char* newItem) {
    vector<char*>:: iterator itemsIterator;
   for(itemsIterator = items->begin(); itemsIterator < items->end(); itemsIterator) {
     if(strcmp((*itemsIterator), newItem) == 0) {
       items->erase(roomIterator);
       return;
     }
   }
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
