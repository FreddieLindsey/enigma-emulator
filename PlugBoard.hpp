#ifndef PlugBoard_h
#define PlugBoard_h

  #include <iostream>
  #include <sstream>
  #include <vector>

  using namespace std;

  class PlugBoard {
    private:
      vector<int> map_;
    public:
      PlugBoard(string file_content, int ALPHABET_SIZE);
      void map(int& c);
  };

#endif
