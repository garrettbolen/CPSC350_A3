#include "GenStack.h"
#include "SyntaxChecker.h"

int main(int argc, char const *argv[]) {

  if(argc < 2){
    cout << "Invalid number of arguments." << endl;
    return 1;
  }
  string filename = argv[1];
  SyntaxChecker sc;
  char input = ' ';

  while(true){
    if(sc.check(filename))
      cout << "File adheres to correct syntax." << endl;
    cout << "Analyze another file? Y/N: " << endl;
    cin >> input;
    if(toupper(input) == 'Y'){
      cout << "Enter the name of a file to be checked: " << endl;
      cin >> filename;
    }
    else
      break;
  }

  return 0;
}
