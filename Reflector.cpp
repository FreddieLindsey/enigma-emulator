#include "Reflector.hpp"

Reflector::Reflector(int ALPHABET_SIZE) : map_size(ALPHABET_SIZE) {}

void Reflector::reflect(char& c) {
  char base_letter;
  if (c >= 'A' && c <= 'Z') {
    base_letter = 'A';
  } else if (c >= 'a' && c <= 'z') {
    base_letter = 'a';
  } else { return; }
  c = base_letter + ((c - int(base_letter) + (map_size / 2)) % map_size);
}
