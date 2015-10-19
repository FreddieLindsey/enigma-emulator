#include "Rotor.hpp"

Rotor::Rotor (string file_content, int ALPHABET_SIZE)
  : map_forwards(ALPHABET_SIZE), map_backward(ALPHABET_SIZE) {
  // Initialise
  istringstream content(file_content);
  string num;
  char delim = ' ';

  // Set map to input file given
  for (int i = 0; i < ALPHABET_SIZE; i++) {
    getline(content, num, delim);
    int el_numero = stoi(num);
    map_forwards[i] = el_numero;
    map_backward[el_numero] = i;
  }
}

void Rotor::encode(char& c) {
  char base_letter;
  if (c >= 'A' && c <= 'Z') {
    base_letter = 'A';
  } else if (c >= 'a' && c <= 'z') {
    base_letter = 'a';
  } else { return; }
  c = base_letter + this->map_forwards[c - int(base_letter)];
}

void Rotor::decode(char& c) {
  char base_letter;
  if (c >= 'A' && c <= 'Z') {
    base_letter = 'A';
  } else if (c >= 'a' && c <= 'z') {
    base_letter = 'a';
  } else { return; }
  c = base_letter + this->map_backward[c - int(base_letter)];
}

bool Rotor::rotate (void) {
  // cout << "Rotating!!..." << endl;
  return true;
}
