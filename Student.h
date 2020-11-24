#include <iostream>
#include "Individual.h"
using namespace std;

class Student: public Individual
{
  public:
    double GPA;
    string majorField;
    int advisorID;

    Student();
    Student(int i, string n, string l, double g, string m, int af);
    ~Student();
    //option 11
    //change advisor for student
    void setAdvisor(int aid);
    void printStudent();

    double getGPA();
    string getMajor();
    int getAdvisorID();
};
