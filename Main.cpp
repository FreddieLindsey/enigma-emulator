#include "Main.hpp"

int main(int argc, char **argv) {

  // COMMAND LINE CHECKS

  // If there are no arguments to the program, exit 1
  if (argc <= 1) {
    cout << "Usage: enigma [rotor1.rot rotor2.rot ...] plugboard.pb" << endl;
    exit(1);
  }

  // ASSUMED PARAMETERS AND INIT
  #define ALPHABET_SIZE 26
  string file_content;

  // Get information about the rotors
  vector<string> rotors(argc - 1);
  for (int i = 1; i < argc - 1; i++) {
    get_string_from_file(argv[i], rotors[i-1]);
  }

  // Create an empty Enigma Machine
  get_string_from_file(argv[argc - 1], file_content);
  shared_ptr<EnigmaMachine> em (new EnigmaMachine(ALPHABET_SIZE, file_content, rotors));

  // Send each character from STD IN to the EnigmaMachine to process
  char c;
  while (cin >> c) {
    if (!iswspace(c)) em->receive(c);
  }
  cout << endl; // Return prompt on new line

  return 0;
}

// Gets information from the file, printing errors to cout.
// Returns the string from the whole file.
void get_string_from_file(char* filename, string& out) {
  // Initialise
  ifstream file_input(filename);

  // Ensure the plugboard could be opened
  if (!file_input.is_open()) {
    cout << filename << " could not be opened. Does it exist? Is it an alien?" << endl;
    exit(1);
  }

  // Read the data from the file
  file_input.seekg (0, file_input.end);
  out.reserve(file_input.tellg());
  file_input.seekg(0, file_input.beg);
  out.assign((std::istreambuf_iterator<char>(file_input)),
              std::istreambuf_iterator<char>());

  file_input.close();
}
