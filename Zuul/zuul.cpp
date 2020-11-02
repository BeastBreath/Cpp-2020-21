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

//This struct keeps track of all the information about a person. This also makes it easier to add more people to the game
struct personInfo {
  rooms* currentRoom = new rooms();//Keeps track of what room the person is in
  vector<char*>* inventoryItems;//Keeps track of items in inventory
  vector <rooms*>* roomList;//Keeps track of all the rooms
  char* input = new char[100];//Keeps track of the input
  int tasksDone = 0;//Keeps track of how many tasks have been done
};

bool playGame(personInfo* myInfo);
rooms* getRoom(char* roomName);
char* getFirstWord(char* input);
char* getSecondWord(char* input);
void INVENTORY(personInfo* myInfo);
void PICK(personInfo* myInfo);
void DROP(personInfo* myInfo);
void GO(personInfo* myInfo);
char* getNextLine(char* fileInput, int &index);
void HELP(personInfo *myInfo);

int main()
{
  cout << "HELLO! Welcome to Zuul. Many things in this game are randomized, so you can't just memorize locations :). You are in the white house. Your first goal is to pick up the ghost and ghostbuster!" << endl;

  //The next few line gets input from a file and puts it into the program so we can use it 
  ifstream myFile("RoomInfo.txt", ifstream::in);
  vector <rooms*> roomList;
  myFile.seekg(0, myFile.end);
  int length = myFile.tellg();
  myFile.seekg(0, myFile.beg);
  char* file = new char[length];
  int index = 0;
  char* line = new char[500];
  myFile.read(file, length);

  //This while loop goes line by line and sets up the rooms with titles, descriptions, and their respective maps and it does this by reading in from the file (which is now stored as charectors in memory)
  while(index < length) {
    rooms* myRoom = new rooms();
    strcpy(line, getNextLine(file, index));
    myRoom->setTitle(line);
    strcpy(line, getNextLine(file, index));
    myRoom->setDescription(line);
    map<char*, char*>* myRoomMap = myRoom->getMap();
    //This while loop keeps going and adding stuff to the map, in pairs of two (direction and room name that is in that direction)
    while((strcmp(line, "NEXTROOM") != 0) && (index < length)) {
      char* direction = new char[20];
      char* nextRoom = new char[30];
      strcpy(direction, getNextLine(file, index));
      //This if statement checks if the next line says nextroom, which is how we change the room
      if(strncmp(direction, "NEXTROOM", 8) == 0) {
	break;
      }
      strcpy(nextRoom, getNextLine(file, index));
      myRoomMap->insert(pair<char*, char*>(direction, nextRoom));
    }
    roomList.push_back(myRoom);
  }

  //The next few lines does the same thing, except it does it with the file for items
  ifstream itemFile("Items.txt", ifstream::in);
  index = 0;
  itemFile.seekg(0, itemFile.end);
  length = itemFile.tellg();
  itemFile.seekg(0, itemFile.beg);
  char* itemF = new char[length];
  itemFile.read(itemF, length);
  srand(time(NULL));
  //The while loop goes through the file and puts the items in random rooms
  while(index < length) {
    char* item = new char[30];
    int randomNumber = rand()%(roomList.size());
    strcpy(item, getNextLine(itemF, index));
    roomList.at(randomNumber)->addItem(item);
  }

  //The next few lines creates the information about the person
  int randomNumber = rand()%(roomList.size());//We get a random number for the room the person is in
  personInfo* myInfo = new personInfo();//We create a struct to store the person's information
  myInfo->roomList = &roomList;//Next we set the room vector
  myInfo->currentRoom = myInfo->roomList->at(randomNumber);//Then we set the room we are in to a random room
  myInfo->inventoryItems = new vector<char*>;//Finally we make a new vector for the inventory Items

  //The next loop is the loop for the game play
  bool playing = true;
  HELP(myInfo);
  while(playing) {
    playing = playGame(myInfo);
  }
}

//This is the function that calls the other functions depending on what the user enters
bool playGame(personInfo* myInfo) {
  //Check winning conditions. There are three tasks, and the following if statements check if the tasks have been completed
  if(myInfo->tasksDone == 0) {
    vector<char*>* inventoryItems = myInfo->inventoryItems;
    vector<char*>:: iterator inventoryIterator;
    bool firstCondition = false;
    bool secondCondition = false;
    //This for loop goes through the inventory, and if we find both the ghost and ghost buster in the inventory we move to the next task
    for(inventoryIterator = inventoryItems->begin(); inventoryIterator < inventoryItems->end(); inventoryIterator++) {
      if (strncmp((*inventoryIterator), "President John Adams Ghost",  5) == 0) {
	firstCondition = true;
      }
      if(strncmp((*inventoryIterator), "Ghost Buster", 5) == 0) {
	secondCondition = true;
      }
    }
    if(firstCondition && secondCondition) {
      myInfo->tasksDone++;
      cout << "Wow! You saved the President from pissing his pants! The next job is to put the pen and Donald Trump in the Oval Office" << endl;
    }
  }
  else if (myInfo->tasksDone == 1) {
    bool firstCondition;
    bool secondCondition;
    vector<rooms*>:: iterator roomIterator;
    //We go through the rooms until we get to the oval office
    for(roomIterator = myInfo->roomList->begin(); roomIterator < myInfo->roomList->end(); roomIterator++) {
      //Once we find it, we look for if the pen and trump are in the oval office, and if they are we move on to the final task
      if(strncmp((*roomIterator)->getTitle(), "Oval Office", 5) == 0) {
	vector<char*>* roomItems = (*roomIterator)->getItems();
	vector<char*>::iterator itemIterator;
	firstCondition = false;
	secondCondition = false;
	for(itemIterator = roomItems->begin(); itemIterator < roomItems->end(); itemIterator++) {
	  if (strncmp((*itemIterator), "Pen",  5) == 0) {
	    firstCondition = true;
	  }
	  if(strncmp((*itemIterator), "Donald Trump", 5) == 0) {
	    secondCondition = true;
	  }
	}
      }
    }
    if(firstCondition && secondCondition) {
      myInfo->tasksDone++;
      cout << "Amazing Job! Now the president can get some work done (except of course he won't). Next, you have to put the Obama and the secret service agent in the south sitting room" << endl;
    }
  }
  else if (myInfo->tasksDone == 2) {

    bool firstCondition;
    bool secondCondition;
    vector<rooms*>:: iterator roomIterator;
    //We go room by room until we get to the south sitting room
    for(roomIterator = myInfo->roomList->begin(); roomIterator < myInfo->roomList->end(); roomIterator++) {
      //Once we find it, we just set that room to the current room
      if(strncmp((*roomIterator)->getTitle(), "South Sitting Room", 10) == 0) {
	vector<char*>* roomItems = (*roomIterator)->getItems();
	vector<char*>::iterator itemIterator;
	firstCondition = false;
	secondCondition = false;
	//Now we check if the secret service agent and barack obama are in the sitting room, and if they are we end the game
	for(itemIterator = roomItems->begin(); itemIterator < roomItems->end(); itemIterator++) {
	  if (strncmp((*itemIterator), "Secret Service Agent",  5) == 0) {
	    firstCondition = true;
	  }
	  if(strncmp((*itemIterator), "Barrack Obama", 5) == 0) {
	    secondCondition = true;
	  }
	}
      }
    }
    if(firstCondition && secondCondition) {
      myInfo->tasksDone++;
      cout << "Wonderful, you beat the game. The next version of this game is coming out when Nividh Singh becomes president of the USA" << endl;
      return false;
    }
  }
  
  cout << "> ";
  //The next lines get the first word of the input
  char* input = new char[100];
  cin.get(input, 100);
  cin.get();
  strcpy(myInfo->input, input);
  char* firstWord = new char [100];
  strcpy(firstWord, getFirstWord(input));
  //The following are just a series of if statements that call the functions
  if(strcmp(firstWord, "DROP") == 0) {
    DROP(myInfo);
    return true;
  }
  else if(strcmp(firstWord, "PICK") == 0) {
    PICK(myInfo);
    return true;
  }
  else if(strcmp(firstWord, "GO") == 0) {
    GO(myInfo);
    return true;
  }
  else if(strcmp(firstWord, "HELP") == 0) {
    if (myInfo->tasksDone == 0) {
      cout << "TASK: Pick up President John Adam's Ghost and the ghost buster" << endl;
    }
    else if (myInfo->tasksDone == 1) {
      cout << "TASK: Put a Pen and Trump in the Oval Office" << endl;
    }
    else if (myInfo->tasksDone == 2) {
      cout << "TASK: Put Barrack Obama and a Secret Service Agent in the South Sitting room" << endl;
    }
    HELP(myInfo);
    return true;
  }
  else if(strcmp(firstWord, "QUIT") == 0) {
    return false;
  }
  else if(strcmp(firstWord, "INVENTORY") == 0) {
    INVENTORY(myInfo);
    return true;
  }
  else {
    cout << "Invalid Command. Valid Commands are:" << endl;
    cout << "DROP   PICK   GO   HELP   QUIT   INVENTORY" << endl;
    return true;
  }
  return true;
}

//This is the help function. This prints out all the information (what room, what exits, what items in room
void HELP(personInfo *myInfo) {

  cout << "You are in the " << myInfo->currentRoom->getTitle() << endl;
  map<char*, char*>::iterator it;
  cout << "The Exits are:\n";
  //This loops goes through the map and prints out the exits
  for(it = myInfo->currentRoom->getMap()->begin(); it != myInfo->currentRoom->getMap()->end(); it++) {
    cout << it->first << endl;
    //cout << it->second << endl;
  }
  cout << "The items in this room are:\n";
  vector<char*>::iterator itemIterator;
  //This loop goes through the items in the room and prints them out one by one
  for (itemIterator = myInfo->currentRoom->getItems()->begin();
       itemIterator != myInfo->currentRoom->getItems()->end();
       itemIterator++) {
    cout << (*itemIterator) << endl;
  }
}

//This function gets the next line of a file
char* getNextLine(char* fileInput, int &index) {
  char* line = new char[500];
  int count = 0;
  //If the value at that index is a new line, then we just increase the index, but don't add it to the output (stored in line)
  if(fileInput[index] == '\n') {
    index++;
  }
  //If the index is at the last value, then do the same thing, except return
  if(index +1 == strlen(fileInput)) {
    line[count] = fileInput[index];
    index++;
    line[count] = '\0';
    return line;
  }
  //We don't see a \n, we keep adding charectors to the output
  while (fileInput[index] != '\n') {
    line[count] = fileInput[index];
    count++;
    index++;
    
    //If there is a \n that got through the loop statement somehow, we catch it here (for some reason that happens)
    if(index +1 == strlen(fileInput)) {
      line[count] = fileInput[index];
      index++;
      return line;
    }
  }
  //Once we get a \n, we add a \0 and return the line
  line[count] = '\0';
  return line;
}

//This function is used when the user wants to go to another room
void GO(personInfo* myInfo) {
  char* secondWord = getSecondWord(myInfo->input);
  char* newRoom = new char [30];
  bool found = false;
  map<char*, char*>::iterator directionIterator;
  //We keep going through the map for that room to see what room is in the direction the user asked
  for(directionIterator = myInfo->currentRoom->getMap()->begin();
      directionIterator != myInfo->currentRoom->getMap()->end();
      directionIterator++) {
    //If we find the room name, we break out of the loop
    if(strncmp(directionIterator->first, secondWord, 2) == 0) {
      strcpy(newRoom, directionIterator->second);
      found = true;
      break;
    }
  }
  if(!found) {
    cout << "Invalid direction" << endl;
    return;
  }
  vector<rooms*>:: iterator roomIterator;
  //Now we try to find out what room has that name, and we go through the rooms until we find it
  for(roomIterator = myInfo->roomList->begin(); roomIterator < myInfo->roomList->end(); roomIterator++) {
    //Once we find it, we just set that room to the current room
    if(strncmp((*roomIterator)->getTitle(), newRoom, strlen(newRoom)) == 0) {
      myInfo->currentRoom = (*roomIterator);
      HELP(myInfo);return;
    }
  }
  cout << "AN UNKNOWN ERROR HAS OCCURED. PLEASE CONTACT WINDOWS TO FIX THIS\n\n SIKE I DON'T KOW WHAT WENT WRONG" << endl;
  HELP(myInfo);
}

//This is called when the user wants to pick up something
void PICK(personInfo* myInfo) {
  char* item = getSecondWord(myInfo->input);
  vector<char*>* roomItems = myInfo->currentRoom->getItems();
  vector<char*>:: iterator roomIterator;
  //This loop goes through the items in the room, and adds the item to the inventory and delete's it from the room
  for(roomIterator = roomItems->begin(); roomIterator != roomItems->end(); roomIterator++) {
    //If the item name is found, we change where it is from the room to inventory
    if(strncmp((*roomIterator), item, strlen(item)) == 0) {
      myInfo->inventoryItems->push_back(item);
      myInfo->currentRoom->deleteItem(item);
      return;
    }
  }
  cout << "Item not found\n";
}

//This is symetrical to the pick method, except it deletes it from inventory an adds it to the room
void DROP(personInfo* myInfo) {
  char* item = getSecondWord(myInfo->input);
  vector<char*>* inventoryItems = myInfo->inventoryItems;
  vector<char*>:: iterator inventoryIterator;
  //This goes through the items in the room
  for(inventoryIterator = inventoryItems->begin(); inventoryIterator < inventoryItems->end(); inventoryIterator++) {
    //If the item is found then we drop it
    if(strncmp((*inventoryIterator), item, strlen(item)) == 0) {
      myInfo->currentRoom->addItem(item);
      myInfo->inventoryItems->erase(inventoryIterator);
      return;
    }
  }
  cout << "Item not found\n";
}

//This goes through the inventory, and prints everything out
void INVENTORY(personInfo* myInfo) {
  vector<char*>* inventoryItems = myInfo->inventoryItems;
  vector<char*>:: iterator inventoryIterator;
  cout << "You have the following items: \n";
  //The loop just goes through the inventory
  for(inventoryIterator = inventoryItems->begin(); inventoryIterator < inventoryItems->end(); inventoryIterator++) {
    cout << (*inventoryIterator) << endl;
  }
}

//This gets the first word from the input. It does this by going charector by charector looking for a space, or the end of the word.
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

//This returns the second word from input, and it goes charector by charector until it gets to a space, and then keeps going until the end of the string and returns that
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
