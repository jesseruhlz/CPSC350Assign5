//this will be the main database header where we decalare the main reqs for the program
#include <iostream>
#include "BST.h"
#include "GenStack.h"
#include "MainMenu.h"
//#include "TreeNode.h"
using namespace std;

class DataBase
{
  public:
    BST<Student> masterStudent;
    BST<Faculty> masterFaculty;

    //GenStack<Student> *studentStack;
    GenStack<Faculty> *facultyStack;

    DataBase();
    ~DataBase();

    void readFile();
    void writeFile();
    //option 1 & 2
    //these two functions will print all student/faculty (the entire tree)
    void printMasterStudent(TreeNode<Student> *n);
    void printMasterFaculty(TreeNode<Faculty> *n);
    //option 3 & 4
    //these two functions will print name/info of advisee for student or name/info of afvisee for fauclty
    void outputMasterStudent(TreeNode<Student> *n, ofstream& outfile);
    void outputMasterFaculty(TreeNode<Faculty> *n, ofstream& outfile);

    //option 5 & 6
    //these functions will find and display student/faculty info given an id
    void displayStudentInformation(int i);
    void displayFacultyInformation(int i);

    //add student/faculty from userAction
    //option 7
    void addStudent();
    //option 9
    void addFaculty();

    //add student/faculty from an initial text file
    void addStudentFromFile(int i, string n, string l, double g, string m, int a);
    void addFacultyFromFile(int i, string n, string l, string d);

    TreeNode<Student>* getMasterStudentRoot();
    TreeNode<Faculty>* getMasterFacultyRoot();

    int checkInput(int l , int u, string m);
    void nodeToStack(TreeNode<Student> *n);
    //void rollback();
    void runProgram();
};
