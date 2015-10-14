// skeleton C++ file, you will need to edit this and other files to implement your enigma machine
#include <cstdlib>
#include <stdexcept>
#include <iostream>
#include <fstream>

using namespace std;

void get_plugboard(int index, char **args);
void get_rotors(int index_s, int index_f, char **args);

int main(int argc, char **argv) {

  // If there are no arguments to the program, exit 1
  if (argc <= 1) {
    cout << "Usage: enigma [rotor1.rot rotor2.rot ...] plugboard.pb" << endl;
    std::exit(1);
  }

  // Print out information about the plugboard
  get_plugboard(argc - 1, argv);

  return 0;
}

void get_plugboard(int index, char **args) {
  // Initialise
  ifstream plugboard(args[index]);
  string line;

  if (!plugboard.is_open()) {
    cout << args[index] << " could not be opened. Does it exist? Is it an alien?" << endl;
    std::exit(1);
  }

  cout << "Content of file:" << endl << "-----START----------" << endl;
  while (getline(plugboard, line)) {
    cout << line;
  }
  cout << "-----END------------" << endl;

  plugboard.close();
}
