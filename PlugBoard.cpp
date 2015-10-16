#include "PlugBoard.hpp"

using namespace std;

PlugBoard::PlugBoard(string file_content) {
  // Initialise
  stringstream cnt(file_content);
  string num1, num2;
  char delim = ' ';

  // Process string
  while (getline(cnt, num1, delim) && getline(cnt, num2, delim)) {
    int uno = stoi(num1); int dos = stoi(num2);
    this->map_[uno] = dos;
    this->map_[dos] = uno;
  }

}

void PlugBoard::map(char& c) {
  int letter = c - int('A');
  c = this->map_[letter];
}
