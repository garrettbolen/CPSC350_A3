#include "SyntaxChecker.h"

//default constructor
SyntaxChecker::SyntaxChecker(){
  stack = new GenStack<char>();
}

//destructor
SyntaxChecker::~SyntaxChecker(){
  delete stack;
}

//this method opens the file and checks its syntax
bool SyntaxChecker::check(string filename){
  ifstream inFS(filename);
  //if the file doesn't exist, the method will return false
  if(!inFS.is_open()){
    cout << "File not found." << endl;
    return false;
  }
  //some basic variables to keep track of each line and character
  string line = "";
  char top = ' ';
  char expected = ' ';
  int lineNum = 1;
  //this while loop will read through the whole file
  while(getline(inFS, line)){
    //this for loop will iterate over each character in a line
    for(int i = 0; i < line.length(); ++i){
      //these if statements set expected to be the appropriate character
      top = stack->peek();
      if(top == '(')
        expected = ')';
      else if(top == '{')
        expected = '}';
      else if(top == '[')
        expected = ']';
      //this if statement will push the opening delimiters onto the stack
      if(line[i] == '(' || line[i] == '{' || line[i] == '['){
        stack->push(line[i]);
      }
      /*each if statement here after will compare the top of the stack to the character
      in the line at the i index and catch any mismatches*/
      else if(line[i] == ')'){
        if(top != '('){
          cout << "Error in line " << lineNum << ": ";
          cout << "Expected '" << expected << "' found ')'" << endl;
          inFS.close();
          return false;
        }
        else
          stack->pop();
      }
      else if(line[i] == '}'){
        if(top != '{'){
          cout << "Error in line " << lineNum << ": ";
          cout << "Expected '" << expected << "' found '}'" << endl;
          inFS.close();
          return false;
        }
        else
          stack->pop();
      }
      else if(line[i] == ']'){
        if(top != '['){
          cout << "Error in line " << lineNum << ": ";
          cout << "Expected '" << expected << "' found ']'" << endl;
          inFS.close();
          return false;
        }
        else
          stack->pop();
      }
    }
    lineNum++;
  }
  //if this point is reached and the stack isn't empty, it means a delimiter is missing
  if(!stack->isEmpty()){
    cout << "Error at end of file: " << "Expected '" << expected << "'" << endl;
    inFS.close();
    return false;
  }
  //if this point is reached, the syntax is valid and the method returns true
  inFS.close();
  return true;
}
