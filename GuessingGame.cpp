#include <iostream>

using namespace std;

bool checkIfPlayAgain()
{
  bool answer = false;
  char ch = 'a';
  while(!answer)
  {
    cout << "Do you want to play again? y for yes, n for no" << endl;
    cin >> ch;
    if (ch == 'y')
    {
      return true;
      answer = true;
    }
    else if (ch == 'n')
    {
      return false;
      answer = true;
    }
  }
  return false;
}

int main()
{
  int randomNumber = 5;
  int input = -1;
  bool play = true;
  while(play)
  {
    cout << "Try to guess the number!" << endl;
    while(input != randomNumber)
    {
      cin >> input;
    }
    if(checkIfPlayAgain() == false)
    {
      play = false;
    }
    input = -1;
  }
  return 0;
}

