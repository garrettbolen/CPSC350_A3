#include "GenStack.h"
#include <fstream>

class SyntaxChecker{
public:

  SyntaxChecker();
  ~SyntaxChecker();

  bool check(string filename);

  GenStack<char>* stack;
};
