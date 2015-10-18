#include "EnigmaMachine.hpp"

EnigmaMachine::EnigmaMachine(int ALPHABET_SIZE, string& plugboard, vector<string>& rotors)
  : pb(plugboard, ALPHABET_SIZE) {}

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
  vector<Rotor*>::iterator iter = encode_decode ?
    this->rts.begin() :
    this->rts.end();
  bool continue_ = true;

  while (continue_) {
    // iter.receive(c)
    iter += encode_decode ? 1 : -1 ;
    continue_ = encode_decode ?
      iter == this->rts.end() :
      iter == this->rts.begin();
  }
}

void EnigmaMachine::rotate_rotors(void) {
  vector<Rotor*>::iterator iter = this->rts.begin();

  bool rotate_next = true;
  while (iter != this->rts.end() && rotate_next) {
    // rotate_next = iter.rotate();
    iter++;
  }
}
