#include "Faculty.h"
using namespace std;

Faculty::Faculty(){};

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
};

void Faculty::printFaculty(){
  cout << "Faculty ID: " << id << endl;
  cout << "Advisor Name: " << name << endl;
  cout << "Level: " << level << endl;
  cout << "Department: " << department << endl;
  //cout << "Advisee IDs: " << printAdivsees();
  cout << endl;
}

void Faculty::printAdivsees(){
  if (numAdvisees == 0){
    cout << "There Are No Advisses." << endl;
  }
  else{
    for (int i = 0; i < maxArray; ++i){
      if (adviseeIDArr[i] != -1){
        cout << adviseeIDArr[i];
        if (i < numAdvisees - 1){
          cout << ", ";
        }
      }
    }
  }
  cout << endl;
}

void Faculty::addAdvisee(int aid){
  //if the array is full part
  if (numAdvisees == maxArray){
    //this will increase size if the array is full
    int *temporary = new int[numAdvisees];

    for (int i = 0; i < numAdvisees; ++i){
      temporary[i] = adviseeIDArr[i];
    }
    adviseeIDArr = new int[numAdvisees * 2];
    maxArray = numAdvisees * 2;
    //move over old array
    for (int i = 0; i < numAdvisees; ++i){
      adviseeIDArr[i] = temporary[i];
    }
    for (int i = 0; i < numAdvisees * 2; ++i){
      adviseeIDArr[i] = -1;
    }
    adviseeIDArr[++numAdvisees] = aid;
  }

  //if the array is not full component
  else{
    int f = 0;
    for (int i = 0; i < maxArray; ++i){
      //if the student is being advised by the faculty person
      if (adviseeIDArr[i] = aid){
        f = maxArray;
      }
    }
    //add the student if they are not being advised by the faculty member
    while (f < maxArray){
      if (adviseeIDArr[f] == -1){
        adviseeIDArr[f] = aid;
        ++numAdvisees;
        break;
      }
      ++f;
    }
  }
}


bool Faculty::removeAdvisee(int adviseeID){
  bool deleted = false;
  //gp through list, if the advisee id is found then delete from lsit
  for (int i = 0; i < maxArray; ++i){
    if (adviseeIDArr[i] == adviseeID){
      adviseeIDArr[i] = -1;
      --numAdvisees;
      deleted = true;
    }
  }
  if (!deleted){
    cout << "Advisee was not found." << endl;
  }
  return deleted;
}

int Faculty::getMaxArr(){
  return maxArray;
}

string Faculty::getDepartment(){
  return department;
}

int Faculty::getNumberOfAdvisees(){
  return numAdvisees;
}
