#include<cstring>
#include<iostream>
#include<vector>

#ifndef ROOMS_H
#define ROOMS_H
#include "rooms.h"
#endif

using namespace std;

rooms::rooms () {
 title = new char[100];
 description = new char[1000];
}

 map<char*, char*>* rooms::getMap() {
 return &directions;
 }

void rooms::addItem(char* newItem){
  items.push_back(newItem);
}
void rooms::deleteItem(char* newItem) {
 cout << "B" << endl;
 cout << newItem << endl;
    vector<char*>:: iterator itemsIterator;
   for(itemsIterator = items.begin(); itemsIterator != items.end(); itemsIterator) {
    cout <<  *itemsIterator << endl;
    if(strncmp((*itemsIterator), newItem, strlen(newItem)) == 0) {
       items.erase(itemsIterator);
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
char* rooms::getDescription(){
  return description;
}
