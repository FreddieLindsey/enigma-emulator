#ifndef PlugBoard_h
#define PlugBoard_h

  #include <iostream>
  #include <sstream>
  #include <tuple>
  #include <vector>

  using namespace std;

  class PlugBoard {
    private:
      vector<int> map_;
    public:
      PlugBoard(string file_content, vector<int>& map);
      void map(char& c);
  };

#endif
