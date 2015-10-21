#ifndef Rotor_h
#define Rotor_h

  #include <iostream>
  #include <sstream>
  #include <vector>

  using namespace std;

  class Rotor {
    private:
      vector<int> map_;
      int offset;
      void getBaseCharacter(char& base, const char c);

    public:
      Rotor(string file_content, int ALPHABET_SIZE);
      void encode(char& c);
      void decode(char& c);
      bool rotate(void);
  };

#endif
