/*
Program Created by Nividh Singh on 9/17/20
Takes in an input and outputs if it is or if it isn't a palindrome
The definition of a palindrome for this project is a string of whose alphanumeric charectors read the same forward and backward, and is not case sensative
*/

#include <iostream>
#include <cstring>

using namespace std;

//Method for checking if the input is a Palindrome
bool checkIfPalindrome(char input[80])
{
  
  int length = strlen(input);
  int half = length/2;
  //for loop that goes from the start to the midde
  for(int i = 0; i < half; i++) {
    //If statement comparing the value in the first half to that in the second half
    if (input[i] != input[length - 1 - i]) {
      cout << i << endl;
      return false;
    }
  }
  return true;
  
}

//main method
int main()
{
  cout << "Please input something" << endl;
  char input[80];
  cin.get(input, 80);
  cin.get();
  char alphaNumInput[80];
  int count = 0;
  int length = strlen(input);
  //Takes out spaces and punctuation and makes everything uppercase
  for(int i = 0; i < length; i++) {
    if(input[i] < 123 && input[i] > 96) {
      //Lower Case
      alphaNumInput[count] = input[i] - 32;
      count++;
    }
    else if(input[i] < 91 && input[i] > 64) {
      //Upper Case
      alphaNumInput[count] = input[i];
      count++;
    }
    else if(input[i] < 58 && input[i] > 47) {
      //Number
      alphaNumInput[count] = input[i];
      count++;
    }
  }
  alphaNumInput[count] = '\0';  
  bool isPalindrome = checkIfPalindrome(alphaNumInput);
  //Prints is palindrome if the answer is a palindrome. Otherwise prints it is not a palindrome.
  if(isPalindrome) {
    cout << "This is a palindrome" << endl;
  }
  else {
    cout << "It is not a palindrome" << endl;
  }
  return 0;
}
