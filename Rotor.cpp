#include "Rotor.hpp"

Rotor::Rotor (string file_content, int ALPHABET_SIZE)
  : map_(ALPHABET_SIZE), offset(0) {
  // Initialise
  istringstream content(file_content);
  string num;
  char delim = ' ';

  // Set map to input file given
  for (int i = 0; i < ALPHABET_SIZE; i++) {
    getline(content, num, delim);
    int el_numero = stoi(num);
    map_[i] = el_numero;
  }
}

void Rotor::encode(char& c) {
  // Intialise
  int ALPHABET_SIZE = map_.size();
  char base_letter;

  // Determine letter case and validity
  getBaseCharacter(base_letter, c);
  if (base_letter == '!') return; // TODO: Use exception handling

  // Get position and translate
  int position = (c - int(base_letter) + offset + ALPHABET_SIZE) % ALPHABET_SIZE;
  c = base_letter + this->map_[position];
}

void Rotor::decode(char& c) {
  // Intialise
  int ALPHABET_SIZE = map_.size();
  char base_letter;

  // Determine letter case and validity
  getBaseCharacter(base_letter, c);
  if (base_letter == '!') return; // TODO: Use exception handling

  // Find position in forward array

  // Letter's place in alphabet and thus wire hole
  int position = c - int(base_letter);

  // Find the original letter for that hole (without offset)
  for (int i = 0; i < ALPHABET_SIZE; i++) {
    if (map_[i] == position) {
      position = i;
      break;
    }
  }

  // Translate position with offset
  int letter = (position - offset + ALPHABET_SIZE) % ALPHABET_SIZE;

  // Retrieve output
  c = base_letter + this->map_[letter];
}

bool Rotor::rotate (void) {
  int ALPHABET_SIZE = map_.size();
  offset = (offset - 1 + ALPHABET_SIZE) % ALPHABET_SIZE;
  return offset == 0;
}

void Rotor::getBaseCharacter(char& base, const char c) {
  // Determine letter case and validity
  if (c >= 'A' && c <= 'Z') {
    base = 'A';
  } else if (c >= 'a' && c <= 'z') {
    base = 'a';
  } else {
    base = '!';
  }
  return;
}
