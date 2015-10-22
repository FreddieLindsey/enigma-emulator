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
      void encode_decode(int&c, bool encode_decode);
      bool rotate(void);
  };

#endif
