#include <iostream>
#include "Individual.h"
using namespace std;

class Student: public Individual
{
  public:
    double GPA;
    string major;
    int advisorID;

    Student();
    Student(int i, string n, string l, string mf, double g, int af);
    ~Student();

    void setAdvisor(int aid);
    void printStudent();

    double getGPA();
    string getMajor();
    int getAdvisorID();
};
