//template class
//will include both the header as well as implementation
#include <iostream>
#include <fstream>
using namespace std;
//constant amount at which stack is increased to allocate more namespace

template<class T>
class GenStack
{
  public:
    GenStack(); //default
    GenStack(T maxSize); // overloaded constructor w/ T being any value type
    ~GenStack(); // destructor
    //GenStackResize(T arr); // a copy of the original stack that allocates new size

    T push(T data);
    T pop();
    T peek();
    T print(T arr);

    bool isFull();
    bool isEmpty();
    int getSize();

  private:
    T *myArray;
    int top;
    int mSize;

};

//default constructor
template <class T>
GenStack<T>::GenStack()
{
  //myArray = new T[100];
  //mSize = 100;
  //top = -1;
}

//overloaded constructor
template <class T>
GenStack<T>::GenStack(T maxSize)
{
  myArray = new T[maxSize];
  mSize = maxSize;
  top = -1;
}

// destructor
template <class T>
GenStack<T>::~GenStack()
{
  delete myArray;
}


template <class T>
T GenStack<T>::push(T data)
{
  //checks if stack is full
  if(isFull())
  {
    cout << "ERROR: stack is full" << endl;
    //this is where we will possibly send it to create a copy of stack w/ increased size
  }
  myArray[++top] = data;
}

template <class T>
T GenStack<T>::pop()
{
  //check if empty before removing
  if(isEmpty()){
    cout << "ERROR: stack is empty" << endl;
    return '\0';
    }
  return myArray[top--];
}
//function to create a new stack
//this will be a copy of the original, but allocate more space to it
/*
template <class T>
GenStack<T>::GenStackResize(int newSize)
{
  maxSize = newSize;
  T* copy = new T[maxSize];
  for (int i = 0; i < top; i++)
    copy[i] = arr[i];
  //msize = maxSize + BOUND;
  delete [] myArray;
  myArray = new T[maxSize];
  myArray = copy;
  delete[] copy;
}
*/
template <class T>
T GenStack<T>::peek()
{
  return myArray[top];
}

template <class T>
T GenStack<T>::print(T arr)
{
  if(isEmpty()){
    cout << "ERROR: stack is empty" << endl;
    return '\0';
  }
  else{
    cout << "Stack: ";
    for(int i = 0; i <= top; i++)
      cout << arr[i] << " ";
    cout << endl;
  }
}

template <class T>
bool GenStack<T>::isFull()
{
  return (top == mSize - 1);
}

template <class T>
bool GenStack<T>::isEmpty()
{
  return (top == -1);
}

template <class T>
int GenStack<T>::getSize()
{
  return top + 1;
}
