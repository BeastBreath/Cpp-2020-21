#include <iostream>

using namespace std;

//Method for asking if player wants to play again
bool checkIfPlayAgain()
{
  bool answer = false;//Varialbe for if answer is valid
  char ch = 'a';//Char for the answer
  //While loop for if the answer isn't valid
  while(!answer)
  {
    cout << "Do you want to play again? y for yes, n for no" << endl;
    cin >> ch;
    if (ch == 'y')//If answer is yes
    {
      return true;
      answer = true;
    }
    else if (ch == 'n')//If answer is no
    {
      return false;
      answer = true;
    }
  }
  return false;
}

//main method
int main()
{
  srand(time(NULL));
  int randomNumber = rand()%101;//random number
  int input = -1;//input number
  bool play = true;//boolean for if the game is being played
  while(play)
  {
    cout << "Try to guess the number!" << endl;
    while(input != randomNumber)//While the guess isn't correct
    {
      cin >> input;
      if(input > randomNumber)//If the guess is too high
      {
	cout << "Your guess is too high" << endl;
      }
      else if(input < randomNumber)//If the guess is too low
      {
	cout << "Your guess is too low" << endl;
      }
      else//If the guess is correct
      {
      cout << "You are Correct!" << endl;
      }
    }
    if(checkIfPlayAgain() == false)//Check if player wants to play again
    {
      play = false;
    }
    input = -1;//Reset the input
    randomNumber = rand()%101;//Reset random number
  }
  return 0;
}
