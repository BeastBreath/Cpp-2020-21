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
  vector <rooms*>* roomList;
  char* input = new char[100];
  int tasksDone = 0;
};

bool playGame(personInfo* myInfo);
rooms* getRoom(char* roomName);
char* getFirstWord(char* input);//Returns first word from the input
char* getSecondWord(char* input);//Returns second word from the input
void INVENTORY(personInfo* myInfo);//Prints inventory items
void PICK(personInfo* myInfo);
void DROP(personInfo* myInfo);
void GO(personInfo* myInfo);
char* getNextLine(char* fileInput, int &index);
void HELP(personInfo *myInfo);

int main()
{
  cout << "HELLO! Welcome to Zuul. Many things in this game are randomized, so you can't just memorize locations :). You are in the white house" << endl;
  
  ifstream myFile("RoomInfo.txt", ifstream::in);
  vector <rooms*> roomList;
  myFile.seekg(0, myFile.end);
  int length = myFile.tellg();
  myFile.seekg(0, myFile.beg);
  
  char* file = new char[length];
  int index = 0;
  char* line = new char[500];
  myFile.read(file, length);
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
      //cout << direction << endl;
      if(strncmp(direction, "NEXTROOM", 8) == 0) {
	break;
      }
      strcpy(nextRoom, getNextLine(file, index));
      myRoomMap->insert(pair<char*, char*>(direction, nextRoom));
      //cout << nextRoom << endl;
    }
    roomList.push_back(myRoom);
  }

  
  ifstream itemFile("Items.txt", ifstream::in);
  index = 0;
  itemFile.seekg(0, itemFile.end);
  length = itemFile.tellg();
  itemFile.seekg(0, itemFile.beg);
  char* itemF = new char[length];
  itemFile.read(itemF, length);
  srand(time(NULL));
  while(index < length) {
    char* item = new char[30];
    //int randomNumber = rand()%(roomList.size());
    int randomNumber = rand();
    cout << randomNumber << endl;
    strcpy(item, getNextLine(itemF, index));
    roomList.at(randomNumber%roomList.size())->addItem(item);
  }
  int randomNumber = rand()/*%(roomList.size())*/;
  cout << randomNumber << endl;
  personInfo* myInfo = new personInfo();
  myInfo->roomList = &roomList;
  myInfo->currentRoom = myInfo->roomList->at(randomNumber%roomList.size());
  myInfo->inventoryItems = new vector<char*>;

  
  char* input = new char[101];
  char* firstWord = new char();
  firstWord = getFirstWord(input);
  char* secondWord = new char();
  secondWord = getSecondWord(input);
  //INVENTORY(myInfo);
  while(true) {
    playGame(myInfo);
  }
}

bool playGame(personInfo* myInfo) {
  cout << "> ";
  char* input = new char[100];
  cin.get(input, 100);
  cin.get();
  strcpy(myInfo->input, input);
  char* firstWord = new char [100];
  strcpy(firstWord, getFirstWord(input));
  if(strcmp(firstWord, "DROP") == 0) {
    cout << "DROP\n";
    DROP(myInfo);
  }
  else if(strcmp(firstWord, "PICK") == 0) {
    cout << "PICK\n";
    PICK(myInfo);
  }
  else if(strcmp(firstWord, "GO") == 0) {
    cout << "GO\n";
    GO(myInfo);
  }
  else if(strcmp(firstWord, "HELP") == 0) {
    HELP(myInfo);
  }
  else if(strcmp(firstWord, "QUIT") == 0) {
    return false;
  }
  else if(strcmp(firstWord, "INVENTORY") == 0) {
    cout << "INVENTORY\n";
    INVENTORY(myInfo);
  }
  else {
    cout << "Command not found" << endl;
  }
  return true;
}

void HELP(personInfo *myInfo) {

  /*vector<rooms*>::iterator it;
  for (it = myInfo->roomList->begin(); it != myInfo->roomList->end(); it++) {
    cout << (*it)->getTitle() << endl;
    }*/
  
  
  cout << "You are in the " << myInfo->currentRoom->getTitle() << endl;
  map<char*, char*>::iterator it;
  cout << "The Exits are:\n";
  for(it = myInfo->currentRoom->getMap()->begin(); it != myInfo->currentRoom->getMap()->end(); it++) {
    cout << it->first << endl;
    //cout << it->second << endl;
  }
  cout << endl;
  cout << "The items in this room are:\n";
  vector<char*>::iterator itemIterator;
  for (itemIterator = myInfo->currentRoom->getItems()->begin();
       itemIterator != myInfo->currentRoom->getItems()->end();
       itemIterator++) {
    cout << (*itemIterator) << endl;
  }
  cout << endl;
}

char* getNextLine(char* fileInput, int &index) {
  char* line = new char[500];
  int count = 0;
  if(fileInput[index] == '\n') {
    index++;
  }
  if(index +1 == strlen(fileInput)) {
    line[count] = fileInput[index];
    index++;
    line[count] = '\0';
    return line;
  }
  while (fileInput[index] != '\n') {
    line[count] = fileInput[index];
    count++;
    index++;
    if(index +1 == strlen(fileInput)) {
      line[count] = fileInput[index];
      index++;
      return line;
    }
  }
  line[count] = '\0';
  return line;
}

void GO(personInfo* myInfo) {
  char* secondWord = getSecondWord(myInfo->input);
  char* newRoom = new char [30];
  map<char*, char*>::iterator directionIterator;
  for(directionIterator = myInfo->currentRoom->getMap()->begin();
      directionIterator != myInfo->currentRoom->getMap()->end();
      directionIterator++) {
    if(strncmp(directionIterator->first, secondWord, 2) == 0) {
      strcpy(newRoom, directionIterator->second);
      cout << "ASAD" << endl;
      cout << newRoom << endl;
      break;
    }
  }
  vector<rooms*>:: iterator roomIterator;
  for(roomIterator = myInfo->roomList->begin(); roomIterator < myInfo->roomList->end(); roomIterator++) {
    if(strncmp((*roomIterator)->getTitle(), newRoom, strlen(newRoom)) == 0) {
      myInfo->currentRoom = (*roomIterator);
      cout << myInfo->currentRoom->getTitle() << endl;
      return;
    }
  }
  cout << "CRY CRY CRY" << endl;
}

void PICK(personInfo* myInfo) {
  char* item = getSecondWord(myInfo->input);
  vector<char*>* roomItems = myInfo->currentRoom->getItems();
  vector<char*>:: iterator roomIterator;
  for(roomIterator = roomItems->begin(); roomIterator < roomItems->end(); roomIterator) {
    cout << *roomIterator << endl;
    if(strncmp((*roomIterator), item, strlen(item)) == 0) {
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
    cout << (*inventoryIterator) << endl;
    if(strncmp((*inventoryIterator), item, strlen(item)) == 0) {
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

/*
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
}*/

char* getSecondWord(char* input) {
  char* secondWord = new char[100];
  int i;
  for(i = 0;(input[i] != ' ') && (i < strlen(input)); i++) {
  }
  for(int count = i + 1; count < strlen(input); count++) {
    if(input[count] != '\0') {
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
