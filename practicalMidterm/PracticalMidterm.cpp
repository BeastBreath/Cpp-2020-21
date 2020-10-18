/*
Made by Nividh Singh
Date: 10/16/20
This program swaps the input
*/

#include <iostream>
#include <cstring>

using namespace std;

void replaceFirstLast(int i, char &result);

int main() {
  char result[81];
  //Loop for going five times
  for (int i = 0; i < 5; i++) {
    replaceFirstLast(i, *result);
    cout << result << endl;
  }
}

void replaceFirstLast (int iteration, char &result) {
  char input[81];
  cout << "This is the " << (iteration + 1) << " time. Please put something and the first and last letters of each word will be swapped\n";
  cin.get(input, 80);
  cin.get();
  int len = strlen(input);
  int firstLetterIndex = 0;
  //Loop that goes through each letter, and if the letter is a space, swaps the letter before and the first letter of the word and sets the following letter to be the first letter of the next word
  for(int i = 0; i < len; i++) {
    if(input[i] == ' ') {
      //replace first letter with last
      char temp = input[i - 1];
      input[i - 1] = input[firstLetterIndex];
      input[firstLetterIndex] = temp;
      //Change firstletterIndex to be next word's first letter
      firstLetterIndex = i + 1;
    }
  }
  //Changes the first and last letter of the last word
  if(input[len - 1] != ' ') {
    char temp = input[len - 1];
    input[len - 1] = input[firstLetterIndex];
    input[firstLetterIndex] = temp;
  }
  strcpy(&result, input);
}
