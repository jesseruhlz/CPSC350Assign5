#include <string>
#include <fstream>
#include "DataBase.h"
#include <stack>
using namespace std;

DataBase::DataBase(){};
DataBase::~DataBase(){};

void DataBase::readFile(){
  ifstream masterStudentFile;
  ifstream masterFacultyFile;

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
  //END OF READING STUDENT TEXT FILE
  //will add masterFacultyFile opening and reading here
  //will be very similar to masterStudentFaculty but will different vars and values being read
  //reading the facult files begin HERE
  int numberOfFaculty = 0;
  int fi = 0;
  string fn = "";
  string fl = "";
  string fd = "";
  int advID = 0;

  int lineCount = 1;
  int createdCount = 0;
  int na = 0;
  masterFacultyFile.open("facultyTable.txt");
  if (masterFacultyFile.is_open()){
    try{
      getline(masterFacultyFile, line); //number of faculty in file
      if (line != ""){
        numberOfFaculty = stoi(line);
      }
    }
    catch (exception e){
      cout << "*** Incorrect Format ***" << endl;
    }

    while (getline(masterFacultyFile,  line)){
      switch (lineCount){
        case 1:
        {
          if (line != "***"){
            cout << "***Incorrect Format ***" << endl;
          }
          break;
        }
        case 2:
        {
          fi = stoi(line);
          break;
        }
        case 3:
        {
          fn = line;
          break;
        }
        case 4:
        {
          fl = line;
          break;
        }
        case 5:
        {
          fd = line;
          break;
        }
        //can have multiple advisees so take a x amount of lines
        case 6:
        {
          try{
            na = stoi(line);
          }
          catch (exception e){
            cout << "*** Incorrect format ***" << endl;
          }
          Faculty *fac = new Faculty(fi, fn, fl, fd);
          createdCount++;
          for (int k = 0; k < na; ++k){
            getline(masterFacultyFile, line);
            advID = stoi(line);
            fac->addAdvisee(advID);
          }
          //here we will create the faculty node and insert it into the tree
          TreeNode<Faculty> *facNode = new TreeNode<Faculty>(fac, fi);
          masterFaculty.insert(facNode);
          break;
        }
        default:break;
      }
      ++lineCount;
      if (createdCount == numberOfFaculty){
        break;
      }
      if (lineCount > 6){
        lineCount = 1;
      }
    }
  }
  else{
    cout << "*** Faculty Table was not found, therefore creating with no faculty in it. ***" << endl;
  }
  masterFacultyFile.close();
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
  ofstream masterFacultyFile;
  masterFacultyFile.open("outputFacultyTable.txt");
  if (masterFacultyFile.is_open()){
    masterFacultyFile << masterFaculty.getSize() << endl;
    TreeNode<Faculty> *n = masterFaculty.getRoot();
    outputMasterFaculty(n, masterFacultyFile);
  }
  masterFacultyFile.close();

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

void DataBase::printMasterFaculty(TreeNode<Faculty> *n){
  if (n != NULL){
    if (n->left != NULL){
      printMasterFaculty(n->left);
    }
    n->data->printFaculty();
    cout << endl;
    if (n->right != NULL){
      printMasterFaculty(n->right);
    }
  }
  else{
    cout << "*** Faculty Tree is empty ***" << endl;
  }
}

void DataBase::outputMasterStudent(TreeNode<Student> *n, ofstream& outfile/*string s*/){
  if (n != NULL){
    outfile << "***" << endl;
    //this will oputput student data from the tree into the file
    outfile << n->data->getID() << endl;
    outfile << n->data->getName() << endl;
    outfile << n->data->getLevel() << endl;
    outfile << n->data->getGPA() << endl;
    outfile << n->data->getMajor() << endl;
    outfile << n->data->getAdvisorID() << endl;

    //rearraning above to look like below
    outputMasterStudent(n->left, outfile);
    outputMasterStudent(n->right, outfile);
  }
  //printRecursion(n, outfile);
  /*
  if (n != NULL){
    outputMasterStudent(n->left, outfile);
    outfile << n->data << endl;
    outputMasterStudent(n->right, outfile);
  }*/
}

void DataBase::outputMasterFaculty(TreeNode<Faculty> *n, ofstream& outfile){
  if (n != NULL){
    outfile << "***" << endl;
    outfile << n->data->getID() << endl;
    outfile << n->data->getName() << endl;
    outfile << n->data->getLevel() << endl;
    outfile << n->data->getDepartment() << endl;
    outfile << n->data->getNumberOfAdvisees() << endl;
    //output the list of their advisees
    if (n->data->getNumberOfAdvisees() > 0){
      for (int i = 0; i < n->data->maxArray; ++i){
        if (n->data->adviseeIDArr[i] != -1){
          outfile << n->data->adviseeIDArr[i] << endl;
        }
      }
    }
    outputMasterFaculty(n->left, outfile);
    outputMasterFaculty(n->right, outfile);
  }
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
    cout << "Press (1) for Yes" << endl;
    cout << "Press (2) for No" << endl;
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
  //GenStack *studentStack = new GenStack();
  //stack<Node *> stack;
  //Node *curr = studNode;
  //studentStack->push(masterStudent);
//stack.push(curr);
}

//adding faculty will be similar to how we add the students
void DataBase::addFaculty(){
  cout << "*** Adding new faculty member ***" << endl;
  int i;
  string n;
  string l;
  string d;
  int answerInt = 0;
  int numEntries = 0;
  string answer = "";

  while (true){
    cout << "ID of Faculty Member: ";
    answerInt = 0;
    answer = "";
    cin >> answer;
    try{
      i = stoi(answer);
      if(i > 0){
        break;
      }
    }
    catch (exception e){
      cout << "*** Incorrect input ***" << endl;
    }
  }

  string line;
  cout << endl;
  cout << "Name of faculty member: ";
  cin.ignore();
  getline(cin, n);
  cout << endl;
  cout << "Level of faculty member: ";
  getline(cin, l);
  cout << endl;
  cout << "Department of faculty member: ";
  getline(cin, d);

  Faculty *fac = new Faculty(i,n,l,d);
  //adding their advisees
  if (!masterStudent.isEmpty()){
    cout << "Does this faculty member have and advisees?" << endl;
    cout << "Press (1) for Yes" << endl;
    cout << "Press (2) for No" << endl;

    while (true){
      answerInt = 0;
      answer = "";
      cin >> answer;
      try{
        answerInt = stoi(answer);
        if (answerInt == 1 || answerInt == 2){
          break;
        }
      }
      catch (exception e){
        cout << "*** Incorrect Input ***" << endl;
      }
    }
    if (answerInt == 1 && !masterStudent.isEmpty()){
      cout << endl;
      cout << "How many advisees does this member have? " << endl;
      while (true){
        cout << "Enter an integer: ";
        answerInt = 0;
        answer = "";
        cin >> answer;

        try{
          answerInt = stoi(answer);
          if (answerInt > 0 && answerInt <= masterStudent.getSize()){
            numEntries = answerInt;
            break;
          }
          else{
            cout << "*** Enter an integer less than the size of the student tree: " << masterStudent.getSize()<< endl;
          }
        }
        catch (exception e){
          cout << "*** Incorrect input ***" << endl;
        }
      }
      for (int v = 0; v < numEntries; ++v){
        while (true){
          cout << "Enter a students ID: ";
          answerInt = 0;
          answer = "";
          cin >> answer;
          try{
            answerInt = stoi(answer);
            if(masterStudent.isInTree(answerInt)){
              fac->addAdvisee(answerInt);
              masterStudent.search(answerInt)->setAdvisor(i);
              break;
            }
            else{
              cout << "*** Student not found in the tree ***" << endl;
            }
          }
          catch (exception e){
            cout << "*** input an integer ***" << endl;
          }
        }
      }
    }
  }
  TreeNode<Faculty> *facNode = new TreeNode<Faculty>(fac, i);
  masterFaculty.insert(facNode);
}

void DataBase::addStudentFromFile(int i, string n, string l, double g, string m, int a){
  Student *stud = new Student(i ,n, l, g, m, a);
  TreeNode<Student> *studNode = new TreeNode<Student>(stud, i);
  masterStudent.insert(studNode);
}

void DataBase::addFacultyFromFile(int i, string n, string l, string d){
  Faculty *fac = new Faculty(i, n, l, d);
  TreeNode<Faculty> *facNode = new TreeNode<Faculty>(fac, i);
  masterFaculty.insert(facNode);
}

void DataBase::displayStudentInformation(int i){
  if(masterStudent.isInTree(i)){
    masterStudent.search(i)->printStudent();
  }
  else{
    cout << "*** Student not in system ***" << endl;
  }
}

void DataBase::displayFacultyInformation(int i){
  if(masterFaculty.isInTree(i)){
    masterFaculty.search(i)->printFaculty();
  }
  else{
    cout << "*** Faculty is not in the system ***" << endl;
  }
}

TreeNode<Student>* DataBase::getMasterStudentRoot(){
  return masterStudent.getRoot();
}

TreeNode<Faculty>* DataBase::getMasterFacultyRoot(){
  return masterFaculty.getRoot();
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

/*
void DataBase::nodeToStack(TreeNode<Student> *root){
  GenStack<Student> s;
  Student *curr = root;
  while (s != NULL || curr != NULL){
    if (curr != NULL){
      s.push(curr);
      curr = curr->left;
    }
    else{
      curr = curr->right;
    }
  }
}
*/

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

        if (masterFaculty.isEmpty()){
          cout << "*** No faculty in the database ***" << endl;
          break;
        }
        cout << endl;
        printMasterFaculty(masterFaculty.getRoot());

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

        if (masterFaculty.isEmpty()){
          cout << "*** No faculty in the database ***" << endl;
          break;
        }
        int t;
        while (true){
          t = checkInput(0,10000, "Please enter a faculty ID: ");

          if(masterFaculty.isInTree(t)){
            displayFacultyInformation(t);
            break;
          }
          else{
            cout << "*** That faculty member is not in the database ***" << endl;
          }
        }
        break;
      }

      //print name and info of student advisor given the students ID
      case 5:
      {

        if (masterStudent.isEmpty()){
          cout << "*** No students in database ***" << endl;
          break;
        }
        int t;
        cout << " *** Current students in the database ***" << endl;
        printMasterStudent(masterStudent.getRoot());

        while(true){
          t = checkInput(0,10000, "Please enter a student ID: ");
          if (masterStudent.isInTree(t)){
            displayFacultyInformation(masterStudent.search(t)->getAdvisorID());
            break;
          }
          else{
            cout << "*** Student is not in the database ***" << endl;
          }
        }
        break;
      }

      //given, a faculty id, print all the names and info of their numAdvisees
      case 6:
      {

        if(masterFaculty.isEmpty()){
          cout << "*** No faculty in the database ***" << endl;
          break;
        }
        int t;
        cout << "*** Faculty members in the database ***" << endl;
        printMasterFaculty(masterFaculty.getRoot());
        while (true){
          t = checkInput(0,10000, "Please enter a faculty ID: ");
          if(masterFaculty.isInTree(t)){
            Faculty *fac = masterFaculty.search(t);
            for (int i = 0; i < fac->getMaxArr(); ++i){
              if (fac->adviseeIDArr[i] != -1){
                displayStudentInformation(fac->adviseeIDArr[i]);
                cout << "***" << endl;
              }
            }
            break;
          }
          else{
            cout << "*** Faculty not in the database ***" << endl;
          }
        }

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

        addFaculty();
        cout << "*** Faculty member added ***" << endl;
        cout << "*** Press '0' to display options ***" << endl;

        break;
      }

      //deletea faculty member given the id
      //this option is having trouble and keeps prompting the user to input a faculty id even
      //after they have delted a faculty member
      case 10:
      {

        int t;
        if (masterFaculty.isEmpty()){
          cout << "*** No faculty members are in this database ***" << endl;
          break;
        }
        cout << "Current faculty in database: " << endl;
        printMasterFaculty(masterFaculty.getRoot());

        while (true){
          t = checkInput(0,10000, "Please enter a faculty ID: ");
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
            break;
          }
          else{
            cout << "*** Faculty is not in the database ***";
          }
        }

        break;
      }

      //change a students advisor given the students if and the new faculty memebr id
      case 11:
      {

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
          s = checkInput(0,10000, "Please enter a student ID: ");
          if (masterStudent.isInTree(s)){
            while (true){
              f = checkInput(0,10000, "Please enter a faculty ID: ");
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

        break;
      }

      //case 12 remove advisee from faculty member
      case 12:
      {

        if (masterFaculty.isEmpty()){
          cout << "*** There are no faculty members in the databse ***" << endl;
          break;
        }
        if (masterStudent.isEmpty()){
          cout << "*** There are no students in the database ***" << endl;
          break;
        }

        int f;
        int s;
        while (true){
          f = checkInput(0,10000, "Enter a faculty ID: ");
          if (masterFaculty.isInTree(f)){
            cout << endl;
            cout << "This member is advising: " << endl;
            masterFaculty.search(f)->printAdivsees();

            while (true){
              s = checkInput(0,10000, "Enter a student ID: ");
              if (masterStudent.isInTree(s)){
                break;
              }
              else{
                cout << endl;
                cout << "*** That student is not in the database ***"<<endl;
              }
            }
            break;
          }
          else{
            cout << "*** That faculty is not in the database ***" << endl;
          }
        }
        if (masterFaculty.search(f)->removeAdvisee(s)){
          masterStudent.search(s)->setAdvisor(-1);
          cout << "*** Advisor removed from assigned student ***" << endl;
        }
        else{
          cout << "*** Advisor was not removed from assigned student ***"<< endl;
        }

        break;
      }


      //rollback come back to it later
      case 13:
      {
        try{
          //masterStudent = studentStack->pop();
          //stack.pop();
        }
        catch (exception e){
          cout << "Rollback is not available for this" << endl;
        }
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
