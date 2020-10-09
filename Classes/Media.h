#include <cstring>
#include <iostream>

using namespace std;

class Media
{
private:
  char title[100];
  int year;
protected:
public:
  int getYear();
  void setYear(int yr);
  char* getTitle();
  void setTitle(char* ttl);
  virtual void setPublisher(char* newPublisher);
  virtual char* getPublisher();
  virtual void setRating(float newRating);
  virtual float getRating();
  virtual void setArtist(char* newArtist);
  virtual char* getArtist();
  virtual void setDuration(int newDuration);
  virtual int setDuration();
  virtual void setDirector(char* newDirector);
  virtual char* getDirector();
};
