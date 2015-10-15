#ifndef EnigmaMachine_h
#define EnigmaMachine_h

  #include <iostream>
  #include "Reflector.hpp"

  class EnigmaMachine {
    private:
      Reflector refl;
    public:
      void receive(const char& c);
  };

#endif
