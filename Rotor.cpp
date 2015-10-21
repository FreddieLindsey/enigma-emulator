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
  encode_decode(c, map_encode);
}

void Rotor::decode(int& c) {
  encode_decode(c, map_decode);
}

void Rotor::encode_decode(int& c, vector<int>& map) {
  int map_s = map.size();
  c = (c + map[(c + offset) % map_s] + map_s) % map_s;
}

bool Rotor::rotate (void) {
  int map_s = map_encode.size();
  offset = (offset + 1 + map_s) % map_s;
  return offset == 0;
}
