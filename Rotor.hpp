#ifndef Rotor_h
#define Rotor_h

  #include <iostream>

  using namespace std;

  class Rotor {
    public:
      Rotor(string file_content);
      void receive(char& c);
      bool rotate(void);
  };

#endif
