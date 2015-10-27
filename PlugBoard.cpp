#include "PlugBoard.hpp"

using namespace std;

PlugBoard::PlugBoard(string file_content)
  : map_(ALPHABET_SIZE) {
  // Initialise
  istringstream content(file_content);
  string num1, num2;
  char delim = ' ';

  // Reset map
  for (size_t i = 0; i < map_.size(); i++) {
    map_[i] = i;
  }

  // Process string
  while (getline(content, num1, delim) && getline(content, num2, delim)) {
    int uno = stoi(num1) % map_.size();
    int dos = stoi(num2) % map_.size();
    map_[uno] = dos;
    map_[dos] = uno;
  }
}

void PlugBoard::map(int& c) {
  c = map_[c];
}
