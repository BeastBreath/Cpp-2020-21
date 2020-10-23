#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

class rooms {
 private:
  chayr title[100];
  char description[1000];
  vector<char*> items;
 public:
  void addItem(char* newItem);
  vector<char*>* getItems();
  void setTitle(char* newTitle);
  char* getTitle();
  void setDescription (char* newDescription);
  char* getDescrition();
};
