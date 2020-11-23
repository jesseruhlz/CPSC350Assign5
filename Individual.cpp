//implementation of Individual class
#include "Individual.h"

using namespace std;

Individual::Individual(){
  //default constructor
}

Individual::~Individual(){
  //destructor
}

int Individual::getID(){
  return id;
}

void Individual::setID(int w){
  id = w;
}

string Individual::getName(){
  return name;
}

string Individual::getLevel(){
  return level;
}
