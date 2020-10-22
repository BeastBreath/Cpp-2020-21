#include<cstring>
#include<iostream>


#ifndef STUDENT_H
#define STUDENT_H
#include "student.h"
#endif

#ifndef NODE_H
#define NODE_H
#include "node.h"
#endif

void ADD(node* firstNode);

int main() {
  student newStudent;
  cout << "A\n";
  node* firstNode = new node(&newStudent);
  cout << "B\n";
  firstNode->setNext(NULL);
  cout << "C\n";
  
}



//ADD
//..

void ADD(node* firstNODE) {
  char* input = new char();
  int newStudentID;
  float newGPA;
  student* newStudent = new student();
  cout << "What is the student's first name? ";
  cin >> input;
  newStudent->setFirstName(input);

  cout << "What is the student's last name? ";
  cin >> input;
  newStudent->setLastName(input);

  cout << "What is the student ID? ";
  cin >> newStudentID;
  newStudent->setStudentID(newStudentID);
}



//PRINT
//Go through and print

//DELETE
//Call the destructor
//Fix previous node to point to next node

//QUIT
//Exit program

//AVERAGE
//Go through them and add them together
//Counter to count how many
//find the average

