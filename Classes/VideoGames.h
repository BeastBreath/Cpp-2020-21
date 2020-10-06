#include <cstring>
#include <iostream>

using namespace std;

class VideoGames {
 private:
  float rating;
  char publisher[100];
 public:
  float getRating();
  void setRating(float rtng);
  char* getPublisher();
  void setPublisher(char* pblshr);
  
};
