#include "PlugBoard.hpp"

using namespace std;

PlugBoard::PlugBoard(string file_content, int ALPHABET_SIZE)
  : map_(ALPHABET_SIZE) {
  // Initialise
  istringstream content(file_content);
  string num1, num2;
  char delim = ' ';

  // Reset map
  for (size_t i = 0; i < map_.size(); i++) {
    this->map_[i] = i;
  }

  // Process string
  while (getline(content, num1, delim) && getline(content, num2, delim)) {
    int uno = stoi(num1); int dos = stoi(num2);
    this->map_[uno] = dos;
    this->map_[dos] = uno;
  }
}

void PlugBoard::map(char& c) {
  char base_letter;
  if (c >= 'A' && c <= 'Z') {
    base_letter = 'A';
  } else if (c >= 'a' && c <= 'z') {
    base_letter = 'a';
  } else { return; }
  c = base_letter + this->map_[c - int(base_letter)];
}
