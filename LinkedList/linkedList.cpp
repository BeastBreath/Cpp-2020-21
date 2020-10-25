/*
This program stores students (name, ID, and GPA). This program uses nodes to store students and point to the next student in the list, and sorts students in numerical order.
By: Nividh Singh
Date: 10/22/20
*/

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

bool GAME(node* currentNode, char* input);//Takes input and calls correct method
void ADD(node* currentNode);//ADD function for firts iteration
void ADD(node* currentNode, student* newStudent);//ADD function for after first iteration
void PRINT(node* currentNode, bool first);//Print functino
void DELETE(node* currentNode, bool first);//Delete function for first itteration
void DELETE(node* currentNode, bool first, int inputStudentID);//Delete function for after iteration
float AVERAGE(node* currentNode, bool first);//Average function for first interation
float AVERAGE(node* currentNode, bool first, int sum, int count);//Average funtion after first iteration

using namespace std;

//Main method
int main() {
  student newStudent;
  node* firstNode = new node(&newStudent);//This is the first node that points to the first one that the user puts in. You don't need a whole node, but its easier and symetrical to other nodes so I like this way better
  firstNode->setNext(NULL);//Sets next node to NULL
  char* input = new char[100];
  cout << "This program creates and stores students, sorting them by Student ID\nValid Commands are:\nHELP   ADD   PRINT   DELETE   AVERAGE   QUITE\n";
  //Loop for the program that keeps getting input from the user
  while(GAME(firstNode, input)) {}
}

//Function that takes user input and calls correspoinding method. It returns wether the program is going or not
//This function could be recursive, and thats why there is the GAME(firstNode, input) commented out so many times
bool GAME(node* firstNode, char* input) {
  cout << "> ";
  cin >> input;
  if(strcmp(input, "ADD") == 0) {
    ADD(firstNode);
    //GAME(firstNode, input);
    return true;
  }
  else if(strcmp(input, "PRINT") == 0) {
    PRINT(firstNode, true);
    //GAME(firstNode, input);
    return true;
  }
  else if(strcmp(input, "DELETE") == 0) {
    DELETE(firstNode, true);
    //GAME(firstNode, input);
    return true;
  }
  else if((strcmp(input, "AVERAGE") == 0) && AVERAGE(firstNode, true) != -1) {
    cout << "The average is: " << AVERAGE(firstNode, true) << endl;
    //GAME(firstNode, input);
    return true;
  }
  else if(strcmp(input, "HELP") == 0) {
    cout << "This program creates and stores students, sorting them by Student ID\nValid Commands are:\nHELP   ADD   PRINT   DELETE   AVERAGE   QUITE\n";
  }
  else if(strcmp(input, "QUIT") == 0) {
    return false;
  }
  else {
    cout << "Invalid input\n";
    //GAME(firstNode, input);
    return true;
  }
  return true;
}

//Function to add next node after first itteration, meaning user input about new student has already been taken
void ADD(node* currentNode, student* newStudent) {
  //If the next one is null, then just put the new student after that, by creating a node and changing null pointer to point to that, and changing the newNode's pointer to NULL
  if(currentNode->getNext() == NULL) {
    node* thisNode = new node(newStudent);
    currentNode->setNext(thisNode);
    thisNode->setNext(NULL);
    return;
  }
  //If the node after the one we are on has the same or greater student ID, then put the new student between the current node and the next node
  if(currentNode->getNext()->getStudent()->getStudentID() >= newStudent->getStudentID())  {
    node* thisNode = new node(newStudent);
    thisNode->setNext(currentNode->getNext());
    currentNode->setNext(thisNode);
    return;
  }
  //If the next student has an ID less than the new student's, then call the function again but with the next node
  if(currentNode->getNext()->getStudent()->getStudentID() < newStudent->getStudentID()) {
    ADD(currentNode->getNext(), newStudent);
    return;
  }
}

//Add function for the first iteration where we take user input
void ADD(node* currentNode) {
  //The first about 20 lines takes in user input and puts it into a student named newStudent
  char* input = new char[100];
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

  cout << "What is the student GPA? ";
  cin >> newGPA;
  //cout << "E" << endl;
  newStudent->setGPA(newGPA);
  //cout << "Aa" << endl;

  //If the next node is NULL, then we add the student in the next spot
  if(currentNode->getNext() == NULL) {
    node* thisNode = new node(newStudent);
    currentNode->setNext(thisNode);
    thisNode->setNext(NULL);
    return;
  }
  //If the next student is greater than or equal to the new student ID, then we insert the new student in between
  if(currentNode->getNext()->getStudent()->getStudentID() >= newStudent->getStudentID())  {
    node* thisNode = new node(newStudent);
    thisNode->setNext(currentNode->getNext());
    currentNode->setNext(thisNode);
    return;
  }
  //If the next studentID is greater than the new StudentID, we call the function again, and also pass in the student ID
  if(currentNode->getNext()->getStudent()->getStudentID() < newStudent->getStudentID()) {
    ADD(currentNode->getNext(), newStudent);
    return;
  }
  
  /*
  The following code is without using recursion, and I couldn't part with it after spending so long on it and not reading the instructions and the caps lock RECURSION :(
  node* thisNode = new node(newStudent);
  //cout << "Cc" << endl;
  node* onNode = firstNode;
  //cout << "Bb" << endl;
  if(firstNode->getNext() == NULL) {
    firstNode->setNext(thisNode);
    thisNode->setNext(NULL);
    //cout << "D" << endl;
    return;
  }
  else if(firstNode->getNext()->getStudent()->getStudentID() > newStudentID) {
    //cout << "DD" << endl;
    thisNode->setNext(firstNode->getNext());
    firstNode->setNext(thisNode);
    //cout << "C"<< endl;
    return;
  }
  else {
    while((onNode->getNext()->getStudent()->getStudentID() < newStudentID)) {
      onNode = onNode->getNext();
      //cout << "EE" << endl;
      if(onNode->getNext() == NULL) {
	//cout << "FF" << endl;
     	onNode->setNext(thisNode);
     	thisNode->setNext(NULL);
	//cout << "B" <<// endl;
     	return;
        } 
     }
    // cout << onNode->getNext()->getStudent()->getStudentID() << endl;
    // cout << thisNode->getStudent()->getStudentID() << endl;
     if(onNode->getNext()->getStudent()->getStudentID() == newStudentID) {
    //   cout << "asdf\n";
       thisNode->setNext(onNode->getNext());
    //   cout << onNode->getNext()->getStudent()->getFirstName() << endl;
       onNode->setNext(thisNode);
    //   cout << onNode->getNext()->getStudent()->getFirstName() << endl;
    //   cout << thisNode->getNext()->getStudent()->getFirstName() <<endl;
    //   cout << onNode->getNext()->getNext()->getStudent()->getFirstName() << endl;
     }
    
     onNode->setNext(thisNode);
     thisNode->setNext(NULL);
    // cout << "A" << endl;
    return;
    }*/
}



//PRINT
//Goes through and prints the student info from each Node
void PRINT(node* currentNode, bool first) {
  //If the next node is NULL and this is the first itteration, we output saying there aren't any students
  if((currentNode->getNext() == NULL) && first) {
    cout << "No students yet!\n";
    return;
  }
  //If its the first time but the next one isn't null, print out the top format text, and call the function again, this time saying it isn't the first itteration
  if (first) {
    cout << "first\tlast\tID\tGPA\n";
    PRINT(currentNode->getNext(), false);
    return;
  }
  //If it isn't the first itteration and the next one is NULL, then just print out the information from that NODE and return
  if(currentNode->getNext() == NULL) {
    cout << currentNode->getStudent()->getFirstName() << "\t" << currentNode->getStudent()->getLastName()  << "\t";
    cout << currentNode->getStudent()->getStudentID() << "\t" << currentNode->getStudent()->getGPA() << "\n";
    return;
  }
  //Otherwise, if the next node has something, then print out the info from that node and call the function, except for the next node 
  else {
    cout << currentNode->getStudent()->getFirstName() << "\t" << currentNode->getStudent()->getLastName()  << "\t";
    cout << currentNode->getStudent()->getStudentID() << "\t" << currentNode->getStudent()->getGPA() << "\n";
    PRINT(currentNode->getNext(), false);
    return;
  }
  /*
This part doesn't use recursion, but I couldn't part with it so here it is
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
  */
}

//DELETE
//This function gets an input from the user and deletes the student with the same name
void DELETE(node* currentNode, bool first) {
  int inputStudentID;
  cout << "What is the studentID you want to delete? ";
  cin >> inputStudentID;
  //If the next node is null, and this is the first itteration, output there are no students yet
  if((currentNode->getNext() == NULL) && first) {
    cout << "No students yet!\n";
    return;
  }
  //If the next node studentID is equal to the input studentID, double check with the user if they want to delete that kid, and then if they say yes delete them
  if(currentNode->getNext()->getStudent()->getStudentID() == inputStudentID) {
    cout << "Are you sure you want to delete this student?\n";
    cout << "First Name: " << currentNode->getNext()->getStudent()->getFirstName() << endl;
    cout << "Last Name: " << currentNode->getNext()->getStudent()->getLastName() << endl;
    cout << "Student ID: " << currentNode->getNext()->getStudent()->getStudentID() << endl;
    cout << "GPA: " << currentNode->getNext()->getStudent()->getGPA() << endl;
    char* input = new char[100];
    cout << "Y for yes and N for no: ";
    cin >> input;
    //If user said yes, delete the person
    if (strcmp(input, "Y") == 0) {
      //Call destructor for currentNode->getNext();
      currentNode->setNext(currentNode->getNext()->getNext());
      return;
    }
    //If user said no, don't do anything
    else if(strcmp(input, "N")==0) {
      cout << "Ok. Not deleting this student\n";
      return;
    }
    //If the user said something else, output that it was an invalid output
    else {
      cout << "Invalid input" << endl;
      return;
    }
  }
  //Otherwise, call the function agian with the next NODE in the list
  else{
    DELETE(currentNode->getNext(), false, inputStudentID);
    return;
  }
}

//Delete function for once we have the studentID
void DELETE(node* currentNode, bool first, int inputStudentID) {
  //If the next one is null, then tell the user that the ID they inputed isn't a valid ID
  if(currentNode->getNext() == NULL) {
    cout << "Student not found\n";
    return;
  }
  //If the ID is equal to the next one, then double check with the user
  else if(currentNode->getNext()->getStudent()->getStudentID() == inputStudentID) {
    cout << "Are you sure you want to delete this student?" << endl;
    cout << "First Name: " << currentNode->getNext()->getStudent()->getFirstName() << endl;
    cout << "Last Name: " << currentNode->getNext()->getStudent()->getLastName() << endl;
    cout << "Student ID: " << currentNode->getNext()->getStudent()->getStudentID() << endl;
    cout << "GPA: " << currentNode->getNext()->getStudent()->getGPA() << endl;
    char* input = new char[100];
    cout << "Y for yes N for no: ";
    cin >> input;
    //If the user says yes, delete the node (by skipping it and going to the next node
    if(strcmp(input, "Y") == 0) {
      //Call destructor for currentNode->getNext();
      currentNode->setNext(currentNode->getNext()->getNext());
      return;
    }
    //If the user says no, then do nothing
    else if(strcmp(input, "N") == 0) {
      cout << "Ok. Not deleting this student\n";
      return;
    }
    //If input is invalid, output invalide input
    else {
      cout << "Invalid input";
      return;
    }
  }
  //Otherwise, call the function again with the next node
  else {
    DELETE(currentNode->getNext(), false, inputStudentID);
    return;
  }
}

//AVERAGE
//Gets the average GPA of the class but is the first time (meaning sum and count are not declared)
float AVERAGE(node* currentNode, bool first) {
  int sum = 0;
  int count = 0;
  float average = 0;
  //If it is the first time and the next node is NULL, output there are no students yet
  if((currentNode->getNext() == NULL) && first) {
    cout << "No students yet!\n";
    return -1;
  }
  //If there are more people but its the first time, call the function again, inputting copies of the sum and count
  else if (first) {
    return AVERAGE(currentNode->getNext(), false, sum, count);
  }
  //If the next node is NULL, and its not the first itteration, add that node's GPA, add one to the count, and find the average, and return the average
  else if(currentNode->getNext() == NULL) {
    sum += currentNode->getStudent()->getGPA();
    count++;
    float average = sum/count;
    return average;
  }
  //Otherwise, just add the node's GPA and add one to the count and then call the function again with the next node
  else {
    sum += currentNode->getStudent()->getGPA();
    count++;
    return AVERAGE(currentNode->getNext(), false, sum, count);
  }
}

//Gets the average but isn't the first itteration (meaning sum and count are declared)
//Everything is the same as the other average function, besides the fact that the sum and count are being passed in, not made
float AVERAGE(node* currentNode, bool first, int sum, int count) {
  if((currentNode->getNext() == NULL) && first) {
    cout << "No students yet!\n";
    return -1;
  }
  else if (first) {
    return AVERAGE(currentNode->getNext(), false, sum, count);
  }
  
  else if(currentNode->getNext() == NULL) {
    sum += currentNode->getStudent()->getGPA();
    count++;
    float average = sum/count;
    return average;
  }
  else {
    sum += currentNode->getStudent()->getGPA();
    count++;
    return AVERAGE(currentNode->getNext(), false, sum, count);
  }
}
