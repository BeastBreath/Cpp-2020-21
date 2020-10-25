
#include<cstring>
#include<iostream>
#include<vector>
#include<iterator>

#ifndef ROOMS_H
#define ROOMS_H
#include "rooms.h"
#endif

using namespace std;

struct personInfo {
  rooms* currentRoom = new rooms();
  vector<char*>* inventoryItems;
  char* input;
};

char* getFirstWord(char* input);//Returns first word from the input
char* getSecondWord(char* input);//Returns second word from the input
int getFirst(char* firstWord);//Gets a number value for what command the user put for the first word
void INVENTORY(personInfo* myInfo);//Prints inventory items
void PICK(personInfo* myInfo);
void DROP(personInfo* myInfo);
void GO(personInfo* myInfo);

int main()
{

  char title[3][3] = {
    {'a', 'a', '\0'},
    {'b', '\0'},
    {'c', '\0'}
  };

  char* egTitle = new char[100];
  rooms* sittingRoom1 = new rooms();
  strcpy(egTitle, "Sitting Room");
  sittingRoom1->setTitle(egTitle);

  personInfo* myInfo = new personInfo();
  myInfo->inventoryItems = new vector<char*>;
  cout << "Start" << endl;
  char* input = new char[101];
  //cin.get(input, 100);
  //cin.get();
  char* firstWord = new char();
  firstWord = getFirstWord(input);
  //cout << firstWord << endl;
  char* secondWord = new char();
  secondWord = getSecondWord(input);
  //cout << secondWord << endl;
  //INVENTORY(myInfo);
}

void GO(personInfo* myInfo) {

}

void PICK(personInfo* myInfo) {
  char* item = getSecondWord(myInfo->input);
  vector<char*>* roomItems = myInfo->currentRoom->getItems();
  vector<char*>:: iterator roomIterator;
  cout << "You have the following items: \n";
  for(roomIterator = roomItems->begin(); roomIterator < roomItems->end(); roomIterator) {
    if(strcmp((*roomIterator), item) == 0) {
      myInfo->inventoryItems->push_back(item);
      myInfo->currentRoom->deleteItem(item);
      return;
    }
  }



}

void DROP(personInfo* myInfo) {
