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
void PRINT(node* firstNode);
void DELETE(node* firstNode);
float AVERAGE(node* firstNode);


using namespace std;

int main() {
  student newStudent;
  node* firstNode = new node(&newStudent);
  firstNode->setNext(NULL);
  ADD(firstNode);
  //PRINT(firstNode);
  //DELETE(firstNode);
  AVERAGE(firstNode);
}



//ADD
//..

void ADD(node* firstNode) {
  char* input = new char();
  int newStudentID;
  float newGPA;
  student* newStudent = new student();
  cout << "What is the student's first name? ";
  cin >> input;
  //newStudent->setFirstName(input);

  cout << "What is the student's last name? ";
  cin >> input;
  //newStudent->setLastName(input);

  cout << "What is the student ID? ";
  cin >> newStudentID;
  newStudent->setStudentID(newStudentID);

  cout << "What is the student GPA? ";
  cin >> newGPA;
  newStudent->setGPA(newGPA);

  node* thisNode = new node(newStudent);
  node* onNode = firstNode;
  if(firstNode->getNext() == NULL) {
    firstNode->setNext(thisNode);
    return;
  }
  else if(firstNode->getNext()->getStudent()->getStudentID() > newStudentID) {
    thisNode->setNext(firstNode->getNext());
    firstNode->setNext(thisNode);
    return;
  }
  else {
    while((onNode->getNext()->getStudent()->getStudentID() < newStudentID)) {
      onNode = onNode->getNext();
      if(onNode->getNext() == NULL) {
	onNode->setNext(thisNode);
	thisNode->setNext(NULL);
	return;
      } 
    }
    thisNode->setNext(onNode->getNext());
    onNode->setNext(thisNode);
    return;
  }
}



//PRINT
//Go through and print
void PRINT(node* firstNode) {
  if(firstNode->getNext() == NULL) {
    cout << "No students yet!\n";
    return;
  }
  cout << "first\tlast\tID\tGPA\n";
  node* onNode = firstNode->getNext();
  while(onNode->getNext() != NULL) {
    student* onStudent = onNode->getStudent();
    cout << onStudent->getFirstName() << "\t" << onStudent->getLastName()  << "\t";
    cout << onStudent->getStudentID() << "\t" << onStudent->getGPA() << "\n";
    onNode = onNode->getNext();
  } 
  cout << onNode->getStudent()->getFirstName() << "\t" << onNode->getStudent()->getLastName()  << "\t";
  cout << onNode->getStudent()->getStudentID() << "\t" << onNode->getStudent()->getGPA() << "\n";
  
}

//DELETE
//Call the destructor
//Fix previous node to point to next node
void DELETE(node* firstNode) {
  int inputStudentID;
  cout << "What is the studentID you want to search for? ";
  cin >> inputStudentID;
  node* onNode = firstNode;
  if(firstNode->getNext() == NULL) {
    cout << "No students yet!";
    return;
  }
  while(onNode->getNext() != NULL) {
    if(onNode->getNext()->getStudent()->getStudentID() == inputStudentID) {
      cout << "Are you sure you want to delete this student?\n";
      cout << "First Name: " << onNode->getNext()->getStudent()->getFirstName() << endl;
      cout << "Last Name: " << onNode->getNext()->getStudent()->getLastName() << endl;
      cout << "Student ID: " << onNode->getNext()->getStudent()->getStudentID() << endl;
      cout << "GPA: " << onNode->getNext()->getStudent()->getGPA() << endl;
      char* input = new char();
      cout << "Y for yes and N for no: ";
      cin >> input;
      if (strcmp(input, "Y") == 0) {
	onNode->setNext(onNode->getNext()->getNext());
	return;
      }
      else{
	return;
      }
    }
    onNode = onNode->getNext();
  }
  
}


//QUIT
//Exit program

//AVERAGE
//Go through them and add them together
//Counter to count how many
//find the average
float AVERAGE(node* firstNode) {
  int sum = 0;
  int count = 0;
  float average = 0;
  node* onNode = firstNode;
  if(firstNode->getNext() == NULL) {
    cout << "No students yet!";
    return -1;
  }
  onNode = firstNode->getNext();
  while(onNode->getNext() != NULL) {
    sum += onNode->getStudent()->getGPA();
    count++;
  }
  sum += onNode->getStudent()->getGPA();
  count++;
  average = (sum/count);
  return average;
}
