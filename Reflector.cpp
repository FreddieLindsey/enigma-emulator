#include "Reflector.hpp"

// Pre: Character is uppercase
void Reflector::reflect(char& c) {
  c = 'A' + ((c - int('A') + 13) % 26);
}
