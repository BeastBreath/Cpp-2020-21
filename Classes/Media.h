/*
Header filer for Media class
Made by Nividh Singh in October 2020
*/

#include <cstring>
#include <iostream>

using namespace std;

class Media
{
private:
  char title[100];
  int year;
  char NA[5];
protected:
public:
  ~Media();
  Media();
  int getYear();
  void setYear(int yr);
  char* getTitle();
  void setTitle(char* ttl);
  void printTitle();
  void printYear();
  virtual void setPublisher(char* newPublisher);
  virtual char* getPublisher();
  virtual void setRating(float newRating);
  virtual float getRating();
  virtual void setArtist(char* newArtist);
  virtual char* getArtist();
  virtual void setDuration(double newDuration);
  virtual double getDuration();
  virtual void setDirector(char* newDirector);
  virtual char* getDirector();
  virtual void printPublisher();
  virtual void printRating();
  virtual void printArtist();
  virtual void printDuration();
  virtual void printDirector();
};
