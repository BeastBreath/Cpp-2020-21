/*
rooms.h file
Made by Nividh Singh
October 20th, 2020
*/
#include <cstring>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class rooms {
 private:
  char* title;//Room title
  char* description;//Room description
  vector<char*> items;//Items in the room
 map<char*, char*> directions;//Rooms around that room
 public:
  rooms();//Constructor
 ~rooms();//Destructor
  map<char*, char*>* getMap();//gets the map
  bool deleteItem(char* newItem);//Deletes an item from the room, and returns if it worked or didn't work
  void addItem(char* newItem);//Adds an item to the items in a room
  vector<char*>* getItems();//Returns the items in the room
  void setTitle(char* newTitle);//Sets title
  char* getTitle();//Sets description
  void setDescription (char* newDescription);//Sets description
  char* getDescription();//Gets discription
};
