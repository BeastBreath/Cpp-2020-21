#include <cstring>
#include <iostream>

#ifndef STUDENT_H
#define STUDENT_H
#include "student.h"
#endif

using namespace std;

char* student::getFirstName(){
  return firstName;
}
void student::setFirstName(char* newFirstName) {
  strcpy(firstName, newFirstName);
}
char* student::getLastName(){
  return lastName;
}
void student::setLastName(char* newLastName) {
  strcpy(lastName, newLastName);
}
float student::getGPA() {
  return GPA;
}
void student::setGPA(float newGPA) {
  GPA = newGPA;
}
int student::getStudentID() {
return studentID;
}
void student::setStudentID(int newStudentID) {
  studentID = newStudentID;
}
