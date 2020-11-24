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
  int advisor = -1; //initalize to advisor is not assigned

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
      switch (lineCounter){
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
          name = line; //this line is the name of the individual
          break;
        }
        case 4:
        {
          level = line; //this line is the level of the individual
          break;
        }
        case 5:
        {
          gpa = stod(line); //this line is the gpa
          break;
        }
        case 6:
        {
          major = line; //this line is the major
          break;
        }
        //here we create a node from student object, then insert into tree
        case 7:
        {
          try{
            advisor = stoi(line);
            Student *stud = new Student(i, name, level, gpa, major, advisor);
            TreeNode<Student> *studNode = new TreeNode<Student>(stud,i);
            masterStudent.insert(studNode); //using BST<Student> masterStudent from DataBase.h
          }
          catch (exception e){
            cout << "Incorrect Format. Could not create node and add to tree." << endl;
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

  masterStudentFile.open("outputTest.txt");
  //use recursion to ouput master student to the table file
  if (masterStudentFile.is_open()){
    masterStudentFile << masterStudent.getSize() << endl; //gets the number of students
    TreeNode<Student> *n = masterStudent.getRoot();
    outputMasterStudent(n, masterStudentFile);
    //n->printRecursion(TreeNode<Student> *n, masterStudentFile);
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
    cout << endl;
    if (n->right != NULL){
      printMasterStudent(n->right);
    }
  }
  else{
    cout << "*** Student tree is empty ***" << endl;
  }
}

void DataBase::outputMasterStudent(TreeNode<Student> *n, ofstream& outfile/*string s*/){
  //ofstream outfile;
  //outfile.open(s);

  if (n != NULL){
    outfile << "***" << endl;
    //this will oputput student data from the tree into the file
    outfile << n->data->getID() << endl;
    outfile << n->data->getName() << endl;
    outfile << n->data->getLevel() << endl;
    outfile << n->data->getGPA() << endl;
    outfile << n->data->getMajor() << endl;
    outfile << n->data->getAdvisorID() << endl;

    //this is the almost the same as below printRecursion(...)
    /*
    if (n->left != NULL){
      outputMasterStudent(n->left, s);
    }
    if (n->right != NULL){
      outputMasterStudent(n->right, s);
    }*/
    //rearraning above to look like below
    outputMasterStudent(n->left, outfile);
    //outfile << n->data << endl;
    outputMasterStudent(n->right, outfile);
  }
  //printRecursion(n, outfile);
  /*
  if (n != NULL){
    outputMasterStudent(n->left, outfile);
    outfile << n->data << endl;
    outputMasterStudent(n->right, outfile);
  }*/
  //outfile.close();
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
        if (!masterStudent.isInTree(i)){ //searchNode may not be correct, maybe make sure node is in tree
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
  cout << endl;
  cout << "Grade: ";
  getline(cin, level);

  while (true){
    cout << endl;
    cout << "GPA: ";
    answerDouble = 0;
    answer = "";
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
    if (answerInt == 1) //student has an advisor
    {
      cout << endl;
      cout << "Advisor ID: ";
      while (true){
        answerInt = 0;
        answer = "";
        cin >> answer;

        try{
          advisor = stoi(answer);
          if(masterFaculty.isInTree(advisor)){ //again maybe change to check if node is in tree and return it
            Faculty *fac = masterFaculty.search(advisor);
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
  masterStudent.insert(studNode);
}

void DataBase::addStudentFromFile(int i, string n, string l, double g, string m, int a){
  Student *stud = new Student(i ,n, l, g, m, a);
  TreeNode<Student> *studNode = new TreeNode<Student>(stud, i);
  masterStudent.insert(studNode);
}

void DataBase::displayStudentInformation(int i){
  if(masterStudent.isInTree(i)){
    masterStudent.search(i)->printStudent();
  }
  else{
    cout << "*** Student not in system ***" << endl;
  }
}

TreeNode<Student>* DataBase::getMasterStudentRoot(){
  return masterStudent.getRoot();
}

int DataBase::checkInput(int l, int u, string m){
  string answer;
  int answerInt;
  while (true){
    cout << endl;
    cout << m;

    answerInt = 0;
    answer = "";
    cin >> answer;
    try{
      answerInt = stoi(answer);
      if (answerInt < u && answerInt >= 0){
        return answerInt;
      }
      else{
        cout << "*** Input a correct command number ***" << endl;
      }
    }
    catch (exception e){
      cout << "*** Input an integer to perform a command. ***" << endl;
    }
  }
}

void DataBase::runProgram(){
  bool isRunning = true;
  while (isRunning){
    int userAction;
    userAction = checkInput(-1,15, "Choose an option from the main menu: ");

    switch (userAction)
    {
      // print all students and their info
      case 1:
      {
        if (masterStudent.isEmpty()){
          cout << endl;
          cout << "*** No students in the database ***" << endl;
          break;
        }
        cout << endl;
        printMasterStudent(masterStudent.getRoot());
        break;
      }

      //print all faculty and their info
      case 2:
      {
        /*
        if (masterFaculty.isEmpty()){
          cout << "*** No faculty in the database ***" << endl;
          break;
        }
        cout << endl;
        printMasterFaculty(masterFaculty.getRoot());
        */
        break;
      }

      //find and display student info given id
      case 3:
      {
        if (masterStudent.isEmpty()){
          cout << "*** No students in database ***" << endl;
          break;
        }
        int t;
        while (true){
          t = checkInput(0,10000, "Please enter a student ID: ");

          if(masterStudent.isInTree(t)){
            displayStudentInformation(t);
            break;
          }
          else{
            cout << "*** That student is not in the database ***" << endl;
          }
        }
        break;
      }

      //find and display faculty info given their id
      case 4:
      {
        /*
        if (masterFaculty.isEmpty()){
          cout << "*** No faculty in the database ***" << endl;
          break;
        }
        int t;
        while (true){
          t = checkInput(0,1000, "Please enter a faculty ID: ");

          if(masterFaculty.isInTree(t)){
            displayFacultyInformation(t);
            break;
          }
          else{
            cout << "*** That faculty member is not in the database ***" << endl;
          }
        }*/
        break;
      }

      //print name and info of student advisor given the students ID
      case 5:
      {
        /*
        if (masterStudent.isEmpty()){
          cout << "*** No students in database ***" << endl;
          break;
        }
        int t;
        cout << " *** Current students in the database ***" << endl;
        printMasterStudent(masterStudent.getRoot());

        while(true){
          t = checkInput(0,1000, "Please enter a student ID: ");
          if (masterStudent.isInTree(t)){
            displayFacultyInformation(masterStudent.search(t)->getAdvisorID());
            break;
          }
          else{
            cout << "*** Student is not in the database ***" << endl;
          }
        }*/
        break;
      }

      //given, a faculty id, print all the names and info of their numAdvisees
      case 6:
      {
        /*
        if(masterFaculty.isEmpty()){
          cout << "*** No faculty in the database ***" << endl;
          break;
        }
        int t;
        cout << "*** Faculty members in the database ***" << endl;
        printMasterFaculty(masterFaculty.getRoot());
        while (true){
          t = checkInput(0,1000, "Please enter a faculty ID: ");
          if(masterFaculty.isInTree(t)){
            Faculty *fac = masterFaculty.search(t);
            for (int i = 0; i < fac->getMaxArr(); ++i){
              if (fac->adviseeIDArr[i] != -1){
                displayStudentInformation(fac->adviseeIDArr[i]);
              }
            }
            break;
          }
          else{
            cout << "*** Faculty not in the database ***" << endl;
          }
        }
        */
        break;
      }

      //add a new student
      case 7:
      {
        addStudent();
        cout << "*** student added ***" << endl;
        cout << "*** Press '0' to display menu options ***" << endl;
        break;
      }

      //delete a student given their id
      case 8:
      {
        int t;
        if (masterStudent.isEmpty()){
          cout << "*** No students in database ***" << endl;
          break;
        }
        cout << "*** Here are the current students in the database ***" << endl;
        printMasterStudent(masterStudent.getRoot());
        while (true){
          t =checkInput(0,10000, "Enter a student ID: ");
          if (masterStudent.isInTree(t)){
            if (masterStudent.search(t)->getAdvisorID() != -1){
              masterFaculty.search(masterStudent.search(t)->getAdvisorID())->removeAdvisee(t);
            }
            masterStudent.deleteNode(t);
            cout << "*** Student Deleted ***" << endl;
            cout << "*** Press '0' to display menu options ***" << endl;
            break;
          }
          else{
            cout << "*** Student is not in the database ***" << endl;
          }
        }
        break;
      }

      //add a new faculty member
      case 9:
      {
        /*
        addFaculty();
        cout << "*** Faculty member added ***" << endl;
        cpit << "*** Press '0' to display options ***" << endl;
        */
        break;
      }

      //deletea faculty member given the id
      case 10:
      {
        /*
        int t;
        if (masterFaculty.isEmpty()){
          cout << "*** No faculty members are in this database ***" << endl;
          break;
        }
        cout << "Current faculty in database: " << endl;
        printMasterFaculty(masterFaculty.getRoot());

        while (true){
          t = checkInput(0,1000, "Please enter a daculty ID: ");
          if (masterFaculty.isInTree(t)){
            if (masterFaculty.search(t)->numAdvisees > 0){
              for (int i = 0; i < masterFaculty.search(t)->maxArray; ++i){
                if (masterFaculty.search(t)->adviseeIDArr[i] != -1){
                  masterStudent.search(masterFaculty.search(t)->adviseeIDArr[i])->setAdvisor(-1);
                }
              }
            }
            masterFaculty.deleteNode(t);
            cout << "*** Faculty deleted ***" << endl;
          }
        }
        */
        break;
      }

      //change a students advisor given the students if and the new faculty memebr id
      case 11:
      {
        /*
        if (masterFaculty.isEmpty()){
          cout << "*** No faculty members are in the database ***" << endl;
          break;
        }
        if (masterStudent.isEmpty()){
          cout << "*** No students are in the database ***" << endl;
          break;
        }
        int f;
        int s;
        cout << "Current students in database: " << endl;
        printMasterStudent(masterStudent.getRoot());
        while (true){
          s = checkInput(0,1000, "Please enter a student ID: ");
          if (masterStudent.isInTree(s)){
            while (true){
              f = checkInput(0,1000, "Please enter a faculty ID: ");
              if (masterFaculty.isInTree(f)){
                break;
              }
              else{
                cout << "Faculty is not in the database" << endl;
              }
            }
            break;
          }
          else{
            cout << "*** Student is not in the database ***" << endl;
          }
        }
        masterStudent.search(s)->setAdvisor(f);
        masterFaculty.search(f)->addAdvisee(s);
        cout << "*** Advisor was changed ***" << endl;
        cout << "*** Press '0' to display options ***" << endl;
        */
        break;
      }

      //case 12 remove advisee from faculty member


      //rollback come back to it later
      case 13:
      {
        break;
      }

      //exit
      case 14:
      {
        isRunning = false;
        cout << "*** Exiting Program ***" << endl;
        //write to file once the program and changes have been made
        break;
      }

      //default
      default:
      {
        MainMenu m;
        m.displayMainMenu();
        break;
      }
    }
  }
}
