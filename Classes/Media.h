#include <cstring>
#include <iostream>

using namespace std;

class Media{
  private:
    char title[100];
    int year;
  public:
    int getYear();
    void setYear(int yr);
    char* getTitle();
    void setTitle(char* ttl);
};
