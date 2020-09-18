#include <iostream>
#include <cstring>

using namespace std;

bool checkIfPalindrome(char input[80], int half, int length)
{
  cout << "A" << input << endl;
  for(int i = 0; i < half; i++) {
    if (input[i] != input[length - 1 - i]) {
      return false;
    }
  }
  return true;
  
}

int main()
{

  char input[80];
  cout << "Enter your input\n";
  cin.get(input, 80);
  cin.get();
  int length = strlen(input);
  int half = length/2;
  if(length%2 == 1) {
    half++;
  }
  bool isPalindrome = checkIfPalindrome(input, half, length);
  if(isPalindrome) {
    cout << "It is a palindrome" << endl;
  }
  else {
    cout << "It is not a palindrome" << endl;
  }
  return 0;
}
