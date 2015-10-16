#include "Reflector.hpp"

// Pre: Character is uppercase
void Reflector::reflect(char& c) {
  char base_letter;
  if (c >= 'A' && c <= 'Z') {
    base_letter = 'A';
  } else if (c >= 'a' && c <= 'z') {
    base_letter = 'a';
  } else { return; }
  c = base_letter + ((c - int(base_letter) + 13) % 26);
}
