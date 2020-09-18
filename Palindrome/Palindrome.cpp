#include <iostream>
#include <cstring>

using namespace std;

int main()
{

  char input[80];
  cout << "Enter your input\n";
  cin.get(input, 80);
  cin.get();
  int length = strlen(input);
  char revInput[length];
  cout << "input: " << input << endl;
  for(int i = 0; i < length; i++) {
    revInput[length - i - 1] = input[i];
  }
  cout << "input: " << input << endl;
  revInput[length] = '\0';
  if(strcmp(input, revInput) == 0) {
    cout << "It is a palindrome" << endl;
  }
  cout << "input: " << input << endl;
  cout << "rev: " << revInput << endl;
  return 0;
}
