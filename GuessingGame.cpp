#include <iostream>

using namespace std;

int main()
{
  cout << "Try to guess a random number\n";
  int randomNumber = 5;
  int input = -1;
  while(input != randomNumber)
  {
    cin >> input;
  }
  return 0;
}



