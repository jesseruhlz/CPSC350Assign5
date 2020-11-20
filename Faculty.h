#include <iostream>
#include <array>
#include "DoubleLinkedList.h"
#include "Individual.h"
using namespace std;

class Faulty : public Individual
{
  public:
    string department;
    unsigned int numAdvisees;
    unsigned int maxArray;
    int *adviseeIDArr;

    Faculty();
    Faculty(int i, string n, string l, string d);
    ~Faculty();

    void printFaculty();
    void printAdivsees();

    void addAdvisee(int aid);
    bool removeAdvisee(int adviseeID);
    int getMaxArr();
    string getDepartment();
    int getNumberOfAdvisees();
};
