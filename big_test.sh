#!/usr/bin/env bash

TESTDATA="TEST DATA TEST DATA TEST DATA TEST DATA"
INPUTS=()
ROTORS=$(ls rotors/*.rot)
COMMAND="echo -e \"$TESTDATA\" | ./enigma "

ROTOR_COUNT=0
for i in `seq 1 1000`; do
  for j in ${ROTORS[@]}; do
    COMMAND+=" $j"
    ROTOR_COUNT=$((ROTOR_COUNT + 1))
  done
done
COMMAND+=" plugboards/I.pb"

echo -e "Rotor count:\t$ROTOR_COUNT"

make clean 1>/dev/null
make 1>/dev/null
COMMAND=$(echo -e $COMMAND)

time { eval $COMMAND; }
