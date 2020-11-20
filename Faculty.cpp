#include "Faculty.h"
using namespace std;

Faculty::Faculty(){
  //default constructor
}

Faculty::Faculty(int i, string n, string l, string d){
  id = i;
  name = n;
  level = l;
  department = d;
  adviseeIDArr = new int[4];
  numAdvisees = 0;
  //set to four because of 1. i 2. n 3. l 4. d
  maxArray = 4;

  //initializing adviseeArr
  for (int i = 0; i < 4; ++i){
    adviseeIDArr[i] = -1;
  }
}

Faculty::~Faculty(){
  //destructor
  delete[] adviseeIDArr;
}

void Faculty::printFaculty(){
  cout << "Faculty ID: " << id << endl;
  cout << "Advisor Name: " << name << endl;
  cout << "Level: " << level << endl;
  cout << "Department: " << department << endl;
  cout << "Advisee IDs: " << printAdivsees();
  cout << endl;
}
