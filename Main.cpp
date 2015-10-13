// skeleton C++ file, you will need to edit this and other files to implement your enigma machine
#include <stdexcept>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv) {

  // If there are no arguments to the program, exit 1
  if (argc <= 1) {
    cout << "Usage: enigma [rotor1.rot rotor2.rot ...] plugboard.pb" << endl;
    exit(1);
  }

  cout << "TODO: implement an Enigma machine" << endl;
  return 0;
}
