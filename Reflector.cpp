#include "Reflector.hpp"

void Reflector::reflect(int& c) {
  c = (c + (ALPHABET_SIZE / 2)) % ALPHABET_SIZE;
}
