#this is a base class for the individual with their i.d., name and level
#this will be inherited by the student and the faculty member
#once inherited, the individual will add their specific attributes in their class
#include <iostream>
#ifndef included
#define included
using namespace std;

class Individual{
  public:
    int id;
    string name;
    string level;

    Individual();
    ~Individual();

    int getID();
    void setID();

    string getName();
    string getLevel();
};
#endif;
