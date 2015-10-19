#ifndef EnigmaMachine_h
#define EnigmaMachine_h

  #include <iostream>
  #include "PlugBoard.hpp"
  #include "Reflector.hpp"

  class EnigmaMachine {
    private:
      PlugBoard pb;
      Reflector refl;
    public:
      EnigmaMachine(int ALPHABET_SIZE, string plugboard);
      void receive(char& c);
  };

#endif
