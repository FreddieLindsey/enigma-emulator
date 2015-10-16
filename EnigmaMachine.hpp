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
      void receive(const char& c);
  };

#endif
