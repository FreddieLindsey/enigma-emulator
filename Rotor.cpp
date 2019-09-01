#include "Rotor.hpp"

Rotor::Rotor(string file_content)
    : map_encode(ALPHABET_SIZE), map_decode(ALPHABET_SIZE), offset(0) {
  // Initialise
  istringstream content(file_content);
  string num;

  // Set map to input file given
  for (int i = 0; i < ALPHABET_SIZE; i++) {
    getline(content, num, INPUT_DELIM);
    int diff = stoi(num) - i;
    map_encode[i] = diff;
    map_decode[i + diff] = -diff;
  }
}

void Rotor::encode_decode(int& c, bool encode_decode) {
  vector<int>& map = encode_decode ? map_encode : map_decode;
  c = (c + map[(c + offset) % ALPHABET_SIZE] + ALPHABET_SIZE) % ALPHABET_SIZE;
}

bool Rotor::rotate(void) {
  offset = (offset + 1 + ALPHABET_SIZE) % ALPHABET_SIZE;
  return offset == 0;
}
