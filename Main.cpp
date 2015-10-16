#include "Main.hpp"

using namespace std;

int main(int argc, char **argv) {

  // COMMAND LINE CHECKS

  // If there are no arguments to the program, exit 1
  if (argc <= 1) {
    cout << "Usage: enigma [rotor1.rot rotor2.rot ...] plugboard.pb" << endl;
    exit(1);
  }

  // ASSUMED PARAMETERS
  #define ALPHABET_SIZE 26

  // Get information about the plugboard
  vector<int> map(ALPHABET_SIZE);
  PlugBoard *pb = new PlugBoard(get_string_from_file(argv[argc - 1]), map);

  // Get information about the rotors
  vector<string> rotors(argc - 1);
  for (int i = 1; i < argc - 1; i++) {
    rotors[i-1] = get_string_from_file(argv[i]);
  }

  // Create an empty Enigma Machine
  unique_ptr<EnigmaMachine> em (new EnigmaMachine(*pb, rotors));

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
string get_string_from_file(char* filename) {
  // Initialise
  ifstream pb(filename);
  string content;

  // Ensure the plugboard could be opened
  if (!pb.is_open()) {
    cout << filename << " could not be opened. Does it exist? Is it an alien?" << endl;
    exit(1);
  }

  // Read the data from the file
  pb.seekg (0, pb.end);
  content.reserve(pb.tellg());
  pb.seekg(0, pb.beg);
  content.assign((std::istreambuf_iterator<char>(pb)),
                  std::istreambuf_iterator<char>());

  pb.close();

  return content;
}
