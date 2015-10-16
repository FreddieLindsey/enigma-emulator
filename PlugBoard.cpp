#include "PlugBoard.hpp"

using namespace std;

PlugBoard::PlugBoard(string file_content, vector<int>& map)
  : map_(map) {
  // Initialise
  stringstream cnt(file_content);
  string num1, num2;
  char delim = ' ';

  // Reset map
  for (size_t i = 0; i < map.size(); i++) {
    this->map_[i] = i;
  }

  // Process string
  while (getline(cnt, num1, delim) && getline(cnt, num2, delim)) {
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
  int letter = c - int(base_letter);
  c = base_letter + this->map_[letter];
}
