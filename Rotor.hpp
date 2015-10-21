#ifndef Rotor_h
#define Rotor_h

  #include <iostream>
  #include <sstream>
  #include <vector>

  using namespace std;

  class Rotor {
    private:
      vector<int> map_encode;
      vector<int> map_decode;
      int offset;

    public:
      Rotor(string file_content, int ALPHABET_SIZE);
      void encode(int& c);
      void decode(int& c);
      bool rotate(void);
  };

#endif
