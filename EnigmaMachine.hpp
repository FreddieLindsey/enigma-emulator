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
      vector<Rotor*> rts;
      Reflector refl;

      void rotor_encode_decode(char& c, bool encode_decode);
      void rotate_rotors(void);

    public:
      EnigmaMachine(int ALPHABET_SIZE, string& plugboard, vector<string>& rotors);
      ~EnigmaMachine();
      void receive(char& c);
  };

#endif
