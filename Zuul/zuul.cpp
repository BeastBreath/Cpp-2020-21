#include<cstring>
#include<iostream>
#include<vector>
#include<iterator>
#include<fstream>
#include <map>

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
char* getNextLine(char* fileInput, int &index);

int main()
{
  ifstream myFile("RoomInfo.txt", ifstream::in);
  vector <rooms*> roomList;
  myFile.seekg (0, myFile.end);
  int length = myFile.tellg();
  myFile.seekg (0, myFile.beg);
  
  char* file = new char[length];
  int index = 0;
  char* line = new char[500];
  myFile.read(file, length);
  cout << length << endl;
  while(index < length) {
    rooms* myRoom = new rooms();
    strcpy(line, getNextLine(file, index));
    myRoom->setTitle(line);
    strcpy(line, getNextLine(file, index));
    myRoom->setDescription(line);
    map<char*, char*>* myRoomMap = myRoom->getMap();
    while((strcmp(line, "NEXTROOM") != 0) && (index < length)) {
      char* direction = new char[20];
      char* nextRoom = new char[30];
      strcpy(direction, getNextLine(file, index));
      cout << direction << endl;
      if(strncmp(direction, "NEXTROOM", 8) == 0) {
	break;
      }
      strcpy(nextRoom, getNextLine(file, index));
      myRoomMap->insert(pair<char*, char*>(direction, nextRoom));
      cout << nextRoom << endl;
    }
    roomList.push_back(myRoom);
  }
  
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

char* getNextLine(char* fileInput, int &index) {
  char* line = new char[500];
  int count = 0;
  //cout << "G\n";
  if(fileInput[index] == '\n') {
    //cout << "F\n";
    index++;
  }
  /* if(fileInput[index] == 'EOF') {
    line[0] = 'EOF';
    line[1] = '\0';
    return line;
  }*/
  //cout << "H\n";
  if(index +1 == strlen(fileInput)) {
    //cout << "I\n";
    line[count] = fileInput[index];
    index++;
    line[count] = '\0';
    return line;
  }
  //cout << "J\n";
  while (fileInput[index] != '\n') {
    //cout << "K\n";
    //cout << "K";
    line[count] = fileInput[index];
    count++;
    index++;
    if(index +1 == strlen(fileInput)) {
      line[count] = fileInput[index];
      index++;
      return line;
    }
  }
  //cout << "L\n";
  line[count] = '\0';
  return line;
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
  char* item = getSecondWord(myInfo->input);
  vector<char*>* inventoryItems = myInfo->inventoryItems;
  vector<char*>:: iterator inventoryIterator;
  for(inventoryIterator = inventoryItems->begin(); inventoryIterator < inventoryItems->end(); inventoryIterator++) {
    if(strcmp((*inventoryIterator), item) == 0) {
      myInfo->currentRoom->addItem(item);
      myInfo->inventoryItems->erase(inventoryIterator);
      return;
    }
  }
  cout << "Item not found\n";
}


void INVENTORY(personInfo* myInfo) {
  vector<char*>* inventoryItems = myInfo->inventoryItems;
  vector<char*>:: iterator inventoryIterator;
  cout << "You have the following items: \n";
  for(inventoryIterator = inventoryItems->begin(); inventoryIterator < inventoryItems->end(); inventoryIterator++) {
    cout << (*inventoryIterator) << endl;
  }
}

int getFirst(char* firstWord) {
  if (strcmp(firstWord, "INVENTORY") == 0) {
    return 0;
  }
  else if (strcmp(firstWord, "DROP") == 0) {
    return 1;
  }
  else if (strcmp(firstWord, "PICK") == 0) {
    return 2;
  }
  else if (strcmp(firstWord, "GO") == 0) {
    return 3;
  }
  else if (strcmp(firstWord, "QUIT") == 0) {
    return 4;
  }
  return 5;
}

char* getFirstWord(char* input) {
  char* firstWord = new char[100];
  for (int i = 0; i < strlen(input); i++) {
    if(input[i] != ' ') {
      firstWord[i] = input[i];
    }
    else {
      firstWord[i] = '\0';
      return firstWord;
    }
  }
  firstWord[strlen(input)] = '\0';
  return firstWord;
}

char* getSecondWord(char* input) {
  char* secondWord = new char[100];
  int i;
  for(i = 0;(input[i] != ' ') && (i < strlen(input)); i++) {
  }
  for(int count = i + 1; count < strlen(input); count++) {
    if(input[count] != ' ') {
      secondWord[count - i - 1] = input[count];
    }
    else {
      secondWord[count+1] = '\0';
      return secondWord;
      
    }
  }
  secondWord[strlen(input)] = '\0';
  return secondWord;
}
