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
  srand(time(NULL));
  int randomNumber = rand()%101;
  int input = -1;
  bool play = true;
  while(play)
  {
    cout << "Try to guess the number!" << endl;
    while(input != randomNumber)
    {
      cin >> input;
      if(input > randomNumber)
      {
	cout << "Your guess is too high" << endl;
      }
      else if(input < randomNumber)
      {
	cout << "Your guess is too low" << endl;
      }
      else
      {
      cout << "You are Correct!" << endl;
      }
    }
    if(checkIfPlayAgain() == false)
    {
      play = false;
    }
    input = -1;
  }
  return 0;
}

