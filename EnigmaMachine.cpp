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
  cout << c;

  // ROTATE ROTORS
  rotate_rotors();
}

void EnigmaMachine::rotor_encode_decode(char& c, bool encode_decode) {
  int count = encode_decode ? 0 : rts.size() - 1;

  while (count < (int) rts.size() && count >= 0) {
    if (encode_decode) {
      rts[count]->encode(c);
    } else {
      rts[count]->decode(c);
    }
    count += encode_decode ? 1 : -1 ;
  }
}

void EnigmaMachine::rotate_rotors(void) {
  vector<Rotor*>::iterator iter = this->rts.begin();

  bool rotate_next = true;
  while (iter != this->rts.end() && rotate_next) {
    rotate_next = (*iter)->rotate();
    iter++;
  }
}
