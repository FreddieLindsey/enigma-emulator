#!/usr/bin/env bash

TESTDATA="TEST DATA TEST DATA TEST DATA TEST DATA"
ROTORS=$(ls rotors/*.rot)
COMMAND="echo -e \"$TESTDATA\" | ./enigma "

ROTOR_COUNT=0
for i in `seq 1 1400`; do
  for j in ${ROTORS[@]}; do
    COMMAND+=" $j"
    ROTOR_COUNT=$((ROTOR_COUNT + 1))
  done
done
COMMAND+=" plugboards/I.pb"

if [[ $ROTOR_COUNT > $(($(getconf ARG_MAX) / 32)) ]]; then
  ROTOR_COUNT=$(($(getconf ARG_MAX) / 32))
fi
echo -e "Rotor count:\t$ROTOR_COUNT"

make clean 1>/dev/null
make 1>/dev/null
COMMAND=$(echo -e $COMMAND)

BOB=date
OS=$(uname)
if [[ $OS == 'Darwin' ]]; then
  BOB=gdate
fi

echo -e "Starting process...\n"
T=$($BOB +%s%6N)
eval $COMMAND
T_=$($BOB +%s%6N)
echo -e "Finished process...\n"
echo -e "Time taken:\t0.$((T_ - T)) seconds"
