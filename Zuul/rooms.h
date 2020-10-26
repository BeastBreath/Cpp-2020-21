#include <cstring>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class rooms {
 private:
  char title[100];
  char description[1000];
  vector<char*> items;
 map<char*, char*> directions;
 public:
 map<char*, char*>* getMap();
  void deleteItem(char* newItem);
  void addItem(char* newItem);
  vector<char*>* getItems();
  void setTitle(char* newTitle);
  char* getTitle();
  void setDescription (char* newDescription);
  char* getDescrition();
};
