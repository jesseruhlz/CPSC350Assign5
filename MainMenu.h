//this will be the header for the menu
//the menu will be like what is shown on the outline paper
//user will input a number to declare what action they want to perform
#include <iostream>
using namespace std;

class MainMenu
{
  private:
    int userAction;

  public:
    MainMenu();
    ~MainMenu();

    void Welcome();
    void displayMainMenu();
};
