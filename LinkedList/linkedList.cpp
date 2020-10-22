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



int main() {
  student newStudent;
  cout << "A\n";
  node firstNode(&newStudent);
  cout << "B\n";
  firstNode.setNext(NULL);
  cout << "C\n";
  
}
/*
//ADD
//..

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
*/
