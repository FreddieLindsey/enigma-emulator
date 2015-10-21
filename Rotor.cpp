#include "Rotor.hpp"

Rotor::Rotor (string file_content, int ALPHABET_SIZE)
  : map_encode(ALPHABET_SIZE), map_decode(ALPHABET_SIZE), offset(0) {
  // Initialise
  istringstream content(file_content);
  string num;
  char delim = ' ';

  // Set map to input file given
  for (int i = 0; i < ALPHABET_SIZE; i++) {
    getline(content, num, delim);
    int diff = stoi(num) - i;
    map_encode[i] = diff;
    map_decode[i + diff] = - diff;
  }
}

void Rotor::encode(int& c) {
  // Intialise
  int ALPHABET_SIZE = map_encode.size();

  c = (c + map_encode[(c + offset) % ALPHABET_SIZE]) % ALPHABET_SIZE;
}

void Rotor::decode(int& c) {
  // Intialise
  int ALPHABET_SIZE = map_encode.size();

  c = (c + map_decode[(c + offset) % ALPHABET_SIZE]) % ALPHABET_SIZE;
}

bool Rotor::rotate (void) {
  int ALPHABET_SIZE = map_encode.size();
  offset = (offset + 1 + ALPHABET_SIZE) % ALPHABET_SIZE;
  return offset == 0;
}
