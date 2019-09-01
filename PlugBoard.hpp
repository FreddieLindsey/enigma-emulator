#ifndef PlugBoard_h
#define PlugBoard_h

#include <iostream>
#include <sstream>
#include <vector>
#include "Constants.hpp"

using namespace std;

class PlugBoard {
 private:
  vector<int> map_;

 public:
  PlugBoard(string file_content);
  void map(int &c);
};

#endif
