//implementation of MainMenu class
#include "MainMenu.h"
using namespace std;

MainMenu::MainMenu(){
  //default constructor
}

MainMenu::~MainMenu(){
  //destructor
}

void MainMenu::Welcome(){
  cout << "\n**** Student & Faculty Records Database ****\n";
  cout << "\n**** Type in a number to declare action ****\n";
  displayMainMenu();
}

void MainMenu::displayMainMenu(){
  cout << endl;
  cout << "1. Print all students and their information." << endl;
  cout << "2. Print all faculty and their information." << endl;
  cout << "3. Find and display student information given ID." << endl;
  cout << "4. Find and display faculty information given ID." << endl;
  cout << "5. Given student ID, get faculty advisor of student." << endl;
  cout << "6. Given faculty ID, get names of their advisees." << endl;
  cout << "7. Add a new student." << endl;
  cout << "8. Delete a student, given their ID." << endl;
  cout << "9. Add a new faculty member." << endl;
  cout << "10. Delete a faculty member, given their ID" << endl;
  cout << "11. Change a student's advisor given both the student's ID and the faculty ID." << endl;
  cout << "12. Remove an advisee from faculty, given ID." << endl;
  cout << "13. Rollback." << endl;
  cout << "14. Exit." << endl;
}
