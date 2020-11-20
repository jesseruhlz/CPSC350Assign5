//implementation of Student.h
#include "Student.h"

using namespace std;

Student::Student(){
  //default constructor
  //will remain empty bc we should not have a default student
}

Student::Student(int i, string n, string l, string mf, double g, int af){
  id = i;
  name = n;
  level = l;
  majorField = mf;
  GPA = g;
  advisorID = af;
}

Student::~Student(){
  //destructor
}

void Student::setAdvisor(int aid){
  advisorID = aid;
}

void Student::printStudent(){
  cout << "Student ID: " << id << endl;
  cout << "Student Name: " << name << endl;
  cout << "Grade Level: " << level << endl;
  cout << "Major: " << majorField << endl;
  cout << "GPA: " << GPA << endl;
  cout << "Advisor ID: " << advisorID;

  if (advisorID == -1){
    cout << "No advisor assigned." << endl;
  }
  else{
    cout << advisorID << endl;
  }
}

double Student::getGPA(){
  return GPA;
}

string Student::getMajor(){
  return majorField;
}
