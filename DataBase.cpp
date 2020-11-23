#include <string>
#include <fstream>
#include "DataBase.h"
using namespace std;

DataBase::DataBase(){};
DataBase::~DataBase(){};

void DataBase::readFile(){
  ifstream masterStudentFile;

  //reading thes student file provided
  int i = 0;
  string name = "";
  string level = "";
  double gpa = 0;
  string major = "";
  int advisor = -1 //initalize to advisor is not assigned

  string line;
  int numberOfStudents = 0;
  int lineCounter = 1;

  masterStudentFile.open("student.txt");

  if (masterStudentFile.is_open()){
    try{
      getline(masterStudentFile,line); //first line is amount of students in file
      if (line != ""){
        numberOfStudents = stoi(line);
      }
    }
    catch (exception e){
      cout << "Unable to open file or the file is in incorrect format" << endl;
    }

    for (int j = 0;  j < (7 * numberOfStudents); ++j){
      getline(masterStudentFile, line);
      swtich (lineCounter){
        case 1:
        {
          if (line != "***"){
            cout << "Incorrect Format" << endl;
          }
          break;
        }
        case 2:
        {
          try{
            i = stoi(line); //this line will be the id number of the student
          }
          catch (exception e){
            cout << "Incorrect Format" << endl;
          }
          break;
        }
        case 3:
        {
          n = line; //this line is the name of the individual
          break;
        }
        case 4:
        {
          l = line; //this line is the level of the individual
          break;
        }
        case 5:
        {
          g = stod(line); //this line is the gpa
          break;
        }
        case 6:
        {
          m = line; //this line is the major
          break;
        }
        //here we create a node from student object
        case 7:
        {
          try{
            a = stoi(line);
            Student *stud = new Student(i, n, l, g, m, a);
            TreeNode<Student> *studNode = new TreeNode<Student>(stud,i);
            masterStudent.insertNode(studNode); //using BST<Student> masterStudent from DataBase.h
          }
          catch (exception e){
            cout << "Incorrect Format" << endl;
          }
          break;
        }
        default:break;
      }
      ++lineCounter;
      if(lineCounter > 7){
        lineCounter = 1;
      }
    }
  }

  else{
    cout << "The student table was not found. Therfore starting application with no students in data base" << endl;
  }
  masterStudentFile.close();

  //will add masterFacultyFile opening and reading here
  //will be very similar to masterStudentFaculty but will different vars and values being read
}

//here is where we will read the trees to a file
void DataBase::writeFile(){
  ofstream masterStudentFile;

  masterStudentFile.open("student.txt");
  //use recursion to ouput master student to the table file
  if (masterStudentFile.is_open()){
    masterStudentFile << masterStudent.getSize() << endl; //gets the number of students
    TreeNode<Student> *n = masterStudent.getRoot();
    outputMasterStudent(n, "student.txt");
  }
  masterStudentFile.close();
  //will write the faculty tree like above code here

  cout << "*** Database is written to file ***" << endl;
}

void DataBase::printMasterStudent(TreeNode<Student> *n){
  if (n != NULL){
    if (n->left != NULL){
      printMasterStudent(n->left);
    }
    n->data->printStudent();
    if (n->right != NULL){
      printMasterStudent(n->right);
    }
  }
  else{
    cout << "*** Student tree is empty ***" << endl;
  }
}

void DataBase::outputMasterStudent(TreeNode<Student> *n, string s){
  ofstream outfile;
  outfile.open(s, true);
  if (n != NULL){
    outfile << "**" << endl;
    //this will oputput student data from the tree into the file
    outfile << n->data->getID() << endl;
    outfile << n->data->getName() << endl;
    outfile << n->data->getLevel() << endl;
    outfile << n->data->getGPA() << endl;
    outfile << n->data->getMajor() << endl;
    outfile << n->data->getAdvisorID() << endl;

    if (n->left != NULL){
      outputMasterStudent(n->left, s);
    }
    if (n->right != NULL){
      outputMasterStudent(n->right, s);
    }
  }
  outfile.close();
}

void DataBase::addStudent(){
  cout << "*** Adding a new student to database ***" << endl;
  int i;
  string name;
  string level;
  double gpa;
  string major;
  int advisor;

  int answerInt = 0;
  double answerDouble = 0;
  string answer = "";

  while (true){
    cout << "ID of student: ";
    answerInt = 0;
    answer = "";
    cin >> answer;

    try{
      i = stoi(answer);

      if (i > 0) //making the student id be greater than zero
      {
        if (!masterStudent.searchNode(i)){ //searchNode may not be correct, maybe make sure node is in tree
          break;
        }
        else{
          cout << "*** Student already exists in the tree ***" << endl;
        }
      }
      else{
        cout << "*** Invalid input. Enter a correct value ***" << endl;
      }
    }
    catch (exception e){
      cout << "*** Invalid input. Enter a correct value ***" << endl;
    }
  }

  string line;
  cout << endl;
  cout << "Name of student: ";
  cin.ignore();
  getline(cin, name);

  cout << "Grade: ";
  getline(cin, level);

  while (true){
    cout << endl;
    cout << "GPA: ";
    answerDouble = 0;
    asnwer = "";
    cin >> answer;
    try{
      gpa = stod(answer);
      if (gpa > 0 && gpa < 5){
        break;
      }
      else{
        cout << "*** Enter a GPA that is between 0 and 5. Any number outside these two will be incorrect. ***" << endl;
      }
    }
    catch (exception e){
      cout << "*** Invalid input. Enter a correct value ***" << endl;
    }
  }

  cout << endl;
  cout << "Major Field: ";
  cin.ignore();
  getline(cin, major);

  if (!masterFaculty.isEmpty()){
    cout << "Does this student have an existing advisor?" << endl;
    cout << "Yes" << endl;
    cout << "No" << endl;
    while (true){
      answerInt = 0;
      answer = "";
      cin >> answer;

      try{
        answerInt =  stoi(answer);
        if (answerInt == 1 || answerInt == 2){
          break;
        }
      }
      catch (exception e){
        cout << "*** Invalid input. Enter a correct value ***" << endl;
      }
    }
    if (answer == 1) //student has an advisor
    {
      cout << endl;
      cout << "Advisor ID: ";
      while (true){
        answerInt = 0;
        answer = "";
        cin >> answer;

        try{
          advisor = stoi(answer);
          if(masterFaculty.searchNode(advisor)){ //again maybe change to check if node is in tree and return it
            Faculty *fac = masterFaculty.searchNode(advisor);
            fac->addAdvisee(i);
            break;
          }
          else{
            cout << "That faculty member was not found." << endl;
          }
        }
        catch (exception e){
          cout << "Please enter an integer." << endl;
        }
      }
    }
    else{
      advisor = -1;
    }
  }
  else{
    advisor = -1;
  }
  Student *stud = new Student(i, name, level, gpa, major, advisor);
  TreeNode<Student> *studNode = new TreeNode<Student>(stud, i);
  masterStudent.insertNode(studNode);
}
