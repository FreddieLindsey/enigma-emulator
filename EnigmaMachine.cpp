#include "EnigmaMachine.hpp"

EnigmaMachine::EnigmaMachine(int ALPHABET_SIZE, string& plugboard, vector<string>& rotors)
  : pb(plugboard, ALPHABET_SIZE), rts(rotors.size()), refl(ALPHABET_SIZE) {
  for (size_t i = 0; i < rts.size(); i++) {
    rts[i] = new Rotor(rotors[i], ALPHABET_SIZE);
  }
}

EnigmaMachine::~EnigmaMachine() {
  for (size_t i = 0; i < rts.size(); i++) {
    delete(rts[i]);
  }
}

void EnigmaMachine::receive(char& c) {
  // FORWARDS DIRECTION OF TRAVEL
  pb.map(c);

  // THROUGH ROTORS, ENCODING
  rotor_encode_decode(c, true);

  // REFLECTION
  refl.reflect(c);

  // THROUGH ROTORS, DECODING
  rotor_encode_decode(c, false);

  // BACKWARDS DIRECTION OF TRAVEL
  pb.map(c);

  // OUTPUT ENCODED CHARACTER
  cout << c << endl;

  // ROTATE ROTORS
  rotate_rotors();
}

void EnigmaMachine::rotor_encode_decode(char& c, bool encode_decode) {
  vector<Rotor*>::iterator iter = encode_decode ? rts.begin() : rts.end() - 1;

  while (iter >= rts.begin() && iter < rts.end()) {
    if(encode_decode) {
      (*iter)->encode(c); iter++;
    } else {
      (*iter)->decode(c); iter--;
    }
  }
}

void EnigmaMachine::rotate_rotors(void) {
  vector<Rotor*>::iterator iter = rts.begin();

  bool rotate_next = true;
  while (iter != rts.end() && rotate_next) {
    rotate_next = (*iter)->rotate();
    iter++;
  }
}
