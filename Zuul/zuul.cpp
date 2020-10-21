#include<cstring>
#include<iostream>
#include<vector>

#ifndef ROOM_H
#define ROOM_H
#include "rooms.h"
#endif

using namespace std;

char* getFirstWord(char* input);
char* getSecondWord(char* input);

int main()
{
  char* input = new char();
  cin.get(input, 100);
  cin.get();
  char* firstWord = new char();
  firstWord = getFirstWord(input);
  cout << firstWord << endl;
  char* secondWord = new char();
  secondWord = getSecondWord(input);
  cout << secondWord << endl;
}

char* getFirstWord(char* input) {
  char* firstWord = new char();
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
  char* secondWord = new char();
  int i;
  for(i = 0;(input[i] != ' ') && (i < strlen(input)); i++) {
  }
  cout << "i is " << i << endl;
  for(int count = i + 1; count < strlen(input); count++) {
    if(input[count] != ' ') {
      secondWord[count] = input[count];
    }
    else {
      secondWord[i+1] = '\0';
      cout << "I " << secondWord << endl;
      return secondWord;
      
    }
  }
  secondWord[strlen(input)] = '\0';
  cout << "B " << secondWord << endl;
  return secondWord;
}
