#include "Main.hpp"

int main(int argc, char **argv) {
  // If there are no arguments to the program, exit 1
  if (argc <= 1) {
    cout << "Usage: enigma [rotor1.rot rotor2.rot ...] plugboard.pb" << endl;
    exit(1);
  }

  // Get information about the rotors
  vector<string> rotors(argc - 2);
  for (size_t i = 0; i < rotors.size(); i++) {
    get_string_from_file(argv[i+1], rotors[i]);
  }

  // Get information about the plugboard
  string plugboard;
  get_string_from_file(argv[argc - 1], plugboard);

  // Create an Enigma Machine with the plugboard and rotors given
  shared_ptr<EnigmaMachine> em (new EnigmaMachine(plugboard, rotors));

  // Send each character from STDIN to the EnigmaMachine to process
  char c;
  while (cin >> c) { if (!iswspace(c)) em->receive(c); }
  cout << endl;

  return 0;
}

// Returns the string from the file if present, otherwise exit 1.
void get_string_from_file(char* filename, string& out) {
  // Ensure the file could be opened
  ifstream file_input(filename);
  if (!file_input.is_open()) {
    cout << filename << " could not be opened. Does it exist? Is it an alien?" << endl;
    exit(1);
  }

  // Read the data from the file
  file_input.seekg (0, file_input.end);
  out.reserve(file_input.tellg());
  file_input.seekg(0, file_input.beg);
  out.assign(std::istreambuf_iterator<char>(file_input),
             std::istreambuf_iterator<char>());

  file_input.close();
}
