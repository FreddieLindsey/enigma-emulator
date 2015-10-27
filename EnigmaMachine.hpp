#ifndef EnigmaMachine_h
#define EnigmaMachine_h

  #include <iostream>
  #include <memory>
  #include "PlugBoard.hpp"
  #include "Rotor.hpp"
  #include "Reflector.hpp"

  class EnigmaMachine {
    private:
      PlugBoard pb;
      vector<shared_ptr<Rotor>> rts;
      Reflector refl;

      void rotor_encode_decode(int& c, bool encode_decode);
      void rotate_rotors(void);
      int getBaseCharacter(char& base, const char c);

    public:
      EnigmaMachine(string& plugboard, vector<string>& rotors);
      ~EnigmaMachine();
      void receive(const char c);
  };

#endif
