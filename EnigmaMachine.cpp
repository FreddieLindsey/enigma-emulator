#include "EnigmaMachine.hpp"

EnigmaMachine::EnigmaMachine(int ALPHABET_SIZE, string plugboard)
  : pb(plugboard, ALPHABET_SIZE) {}

void EnigmaMachine::receive(char& c) {
  // FORWARDS DIRECTION OF TRAVEL
  pb.map(c);

  // REFLECTION
  refl.reflect(c);

  // BACKWARDS DIRECTION OF TRAVEL
  pb.map(c);

  // OUTPUT ENCODED CHARACTER
  std::cout << c;
}
