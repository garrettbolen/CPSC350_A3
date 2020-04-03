#include "GenStack.h"

//default constructor
template <typename type> GenStack<type>::GenStack(){
  myArray = new type[128];
  mSize = 128;
  top = -1;
}

//overloaded constructor
template <typename type> GenStack<type>::GenStack(int maxSize){
  myArray = new type[maxSize];
  mSize = maxSize;
  top = -1;

}

//destructor
template <typename type> GenStack<type>::~GenStack(){
  delete myArray;
}

template <typename type> void GenStack<type>::push(type data){
  //Checks if the stack is full
  if(top >= mSize - 1){
    //If so, a new array is allocated with an additional slot for the new data
    type* tempArray = new type[mSize + 1];
    for(int i = 0; i < mSize; ++i)
      tempArray[i] = myArray[i];
    tempArray[++top] = data;
    delete myArray;
    myArray = tempArray;
    tempArray = NULL;
    mSize++;
    return;
  }
  myArray[++top] = data;
}

template <typename type> type GenStack<type>::pop(){
  //Checks if the stack is empty
  if(top < 0){
    cout << "Stack underflow." << endl;
    return ' ';
  }
  return myArray[top--];
}

template <typename type> type GenStack<type>::peek(){
  return myArray[top];
}

template <typename type> bool GenStack<type>::isFull(){
  return (top == mSize - 1);
}

template <typename type> bool GenStack<type>::isEmpty(){
  return (top == -1);
}

//This line forces support for char type (fixes undefined reference error)
template class GenStack<char>;
