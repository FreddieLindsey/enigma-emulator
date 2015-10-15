#include "EnigmaMachine.hpp"

void EnigmaMachine::receive(const char& c) {
  char character_encode(c);
  refl.reflect(character_encode);
  std::cout << character_encode;
}
