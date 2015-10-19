#include "Rotor.hpp"

Rotor::Rotor (string file_content) {
  // cout << "Creating rotor";
}

void Rotor::receive(char& c) {
  cout << c << endl;
}

bool Rotor::rotate (void) {
  cout << "Rotating!!..." << endl;
  return true;
}
