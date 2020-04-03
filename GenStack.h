#include <iostream>
using namespace std;

//ensures that the header file is only included once at runtime
#pragma once

template <typename type> class GenStack{
public:
  GenStack(); // default constructor
  GenStack(int maxSize); // overloaded constructor
  ~GenStack(); // destructor

  //core funtions
  void push(type data); // insert an item
  type pop(); // remove

  //auxiliary/helper functions
  type peek(); // aka, top()
  bool isEmpty();
  bool isFull();

  int top;
  int mSize;

  type* myArray;  //memory address of the first block
};
