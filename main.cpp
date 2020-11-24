#include "DataBase.h"
using namespace std;

int main(int argc, char** argv)
{
  DataBase d1;
  MainMenu menu;

  d1.readFile();
  menu.Welcome();
  d1.runProgram();
  d1.writeFile();
  //d1.printMasterStudent();
  return 0;
}
