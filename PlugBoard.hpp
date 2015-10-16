#ifndef PlugBoard_h
#define PlugBoard_h

  #include <iostream>
  #include <sstream>
  #include <fstream>
  #include <tuple>
  #include <vector>

  using namespace std;

  class PlugBoard {
    private:
      vector<tuple<int, char>> map_;
    public:
      PlugBoard(string file_content);
      void encode(char& c);
      void decode(char& c);
  };

#endif
