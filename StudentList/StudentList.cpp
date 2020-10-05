/*
By: Nividh Singh
Date: October 5, 2020
This program creates a list of students with student names, GPA's and ID's and allows users to add, delete and print the list

Credit: https://stackoverflow.com/questions/5907031/printing-the-correct-number-of-decimal-points-with-cout
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <cstring>

using namespace std;

//Struct for storing student data
struct student {
  char firstName[100];
  char lastName[100];
  int studentID;
  float studentGPA;
};

void deletefunc(vector<student> &Students);
void add (vector<student> &Students);
void print (vector<student> &Students);

//Main method
int main ()
{
  vector<student> Students;
  char input[8];
  bool programGoing = true;
  //While we are in the program
  while (programGoing) {
    cout << ">";
    cin >> input;
    //If command is DELETE, call delete function
    if(strcmp(input, "DELETE") == 0){
      deletefunc(Students);
    }
    //If command is ADD, call add function
    else if(strcmp(input, "ADD") == 0) {
      add(Students);
    }
    //If command is PRINT, call print function
    else if(strcmp(input, "PRINT") == 0) {
      print(Students);
    }
    //If command is quit, quit program
    else if(strcmp(input, "QUIT") ==0) {
      return(0);
    }
    //Otherwise give an error message about input
    else {
      cout << "Not Valid Input. Valid inputs are:\nPRINT\tADD\tDELETE\n";
    }
  }
}

//Delete function
void deletefunc(vector<student> &Students) {
  cout << "What is the student ID of the student you want to delete? ";
  int inputID = 0;
  cin >> inputID;
  //Goes through each student
  for (int i = 0; i < Students.size(); i++) {
    //Checks if student ID matches student ID that was inputed, and if it does deletes that student and exits function
    if (Students[i].studentID == inputID) {
      Students.erase(Students.begin() + i);
      return;
    }
  }
  cout << "Student not found" << endl;
}

//Add function
void add(vector<student> &Students) {
  //Creates a student and prompts and gets input for each student
  student inputStudent;
  cout << "Student first name: ";
  cin >> inputStudent.firstName;
  cout << "Student last name: ";
  cin >> inputStudent.lastName;
  cout << "Student ID: ";
  cin >> inputStudent.studentID;
  cout << "Student GPA: ";
  cin >> inputStudent.studentGPA;
  Students.push_back(inputStudent);//Adds student to vector
}

//Print function
void print (vector<student> &Students) {
  //Prints first row for each column definition
  cout << "ID \tGPA\tStudent Name\n";
  //Goes through each student
  for (int i = 0; i < Students.size(); i++) {
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    //Prints each student ID, GPA, and name, and formats it like a table
    cout << Students[i].studentID << "\t" << Students[i].studentGPA << "\t";
    cout << Students[i].lastName << ", " << Students[i].firstName << endl;
  }
}
