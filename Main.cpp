// skeleton C++ file, you will need to edit this and other files to implement your enigma machine
#include <cstdlib>
#include <cstring>
#include <stdexcept>
#include <iostream>
#include <fstream>

#include "EnigmaMachine.hpp"

using namespace std;

void get_plugboard(int index, char **args);
void get_rotor(int index, char **args);

int main(int argc, char **argv) {

  // If there are no arguments to the program, exit 1
  if (argc <= 1) {
    cout << "Usage: enigma [rotor1.rot rotor2.rot ...] plugboard.pb" << endl;
    exit(1);
  }

  // Create an empty Enigma Machine
  EnigmaMachine* em = new EnigmaMachine();

  // Print out information about the plugboard
  get_plugboard(argc - 1, argv);

  // Print out information about the rotors
  cout << "There are " << argc - 2 << " rotors. See below:" << endl;
  for (int i = 1; i < argc - 1; i++) {
    get_rotor(i, argv);
  }

  em->receive('a'); // Proof of concept. TODO: Delete

  // Memory clean up
  delete(em);

  return 0;
}

void get_plugboard(int index, char **args) {
  // Initialise
  ifstream plugboard(args[index]);
  string line;

  if (!plugboard.is_open()) {
    cout << args[index] << " could not be opened. Does it exist? Is it an alien?" << endl;
    exit(1);
  }

  cout << "Content of file:" << endl << "-----START----------" << endl;
  while (getline(plugboard, line)) {
    cout << line;
  }
  cout << endl << "-----END------------" << endl;

  plugboard.close();
}

void get_rotor(int index, char **args) {
  // Initialise
  ifstream rotor(args[index]);
  string line;

  if (!rotor.is_open()) {
    cout << args[index] << " could not be opened. Does it exist? Is it an alien?" << endl;
    exit(1);
  } else {
    cout << "Rotor " << index << ":\t" << args[index] << endl;
  }

  cout << "-----START----------" << endl;
  while (getline(rotor, line)) {
    cout << line;
  }
  cout << endl << "-----END------------" << endl;

  rotor.close();
}
