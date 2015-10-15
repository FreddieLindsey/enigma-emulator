#include "Main.hpp"

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
  unique_ptr<EnigmaMachine> em (new EnigmaMachine());

  // Get information about the plugboard
  get_plugboard(argc - 1, argv);

  // Get information about the rotors
  for (int i = 1; i < argc - 1; i++) {
    get_rotor(i, argv);
  }

  char c;
  while (cin >> c) {
    if (!iswspace(c)) em->receive(c);
  }
  cout << endl; // Return prompt on new line

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

  plugboard.close();
}

void get_rotor(int index, char **args) {
  // Initialise
  ifstream rotor(args[index]);
  string line;

  if (!rotor.is_open()) {
    cout << args[index] << " could not be opened. Does it exist? Is it an alien?" << endl;
    exit(1);
  }

  rotor.close();
}
