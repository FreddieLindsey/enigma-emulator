#include "EnigmaMachine.hpp"

EnigmaMachine::EnigmaMachine(PlugBoard& plugboard, vector<string> rotors)
  : pb(plugboard) {}

void EnigmaMachine::receive(const char& c) {
  char character_encode(c);

  // FORWARDS DIRECTION OF TRAVEL
  pb.map(character_encode);

  // REFLECTION
  refl.reflect(character_encode);

  // BACKWARDS DIRECTION OF TRAVEL
  pb.map(character_encode);

  // OUTPUT ENCODED CHARACTER
  std::cout << character_encode;
}
