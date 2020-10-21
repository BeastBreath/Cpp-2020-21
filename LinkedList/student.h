#include<cstring>
#include <iostream>

using namespace std;

class student {
 private:
  char* firstName;
  char* lastName;
  float GPA;
  int studentID;
 public:
  char* getFirstName();
  void setFirstName(char* newFirstName);
  char* getLastName();
  void setLastName(char* newLastName);
  float getGPA();
  void setGPA(float newGPA);
  int getStudentID();
  void getStudentID(int newStudentID);
  
};











