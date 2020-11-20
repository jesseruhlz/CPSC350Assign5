//implementation of Individual class
#include "Individual.h"

using namespace std;

Individual::Individual(){

}

Individual::~Individual(){

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
