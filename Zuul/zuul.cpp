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
int getFirst(char* firstWord);

int main()
{
  cout << "Start" << endl;
  char* input = new char[101];
  cin.get(input, 100);
  cin.get();
  char* firstWord = new char();
  firstWord = getFirstWord(input);
  cout << firstWord << endl;
  char* secondWord = new char();
  secondWord = getSecondWord(input);
  cout << secondWord << endl;
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
