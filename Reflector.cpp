#include "Reflector.hpp"

Reflector::Reflector(void) : map_size(ALPHABET_SIZE) {}

void Reflector::reflect(int& c) {
  c = (c + (map_size / 2)) % map_size;
}
