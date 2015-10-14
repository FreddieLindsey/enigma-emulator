CPP = g++
FLAGS = -Wall -Werror -pedantic -std=c++11

enigma: Main.o EnigmaMachine.o
	$(CPP) $(FLAGS) -o enigma $^

Main.o: Main.cpp
	$(CPP) $(FLAGS) -c Main.cpp

EnigmaMachine.o: EnigmaMachine.cpp EnigmaMachine.hpp
	$(CPP) $(FLAGS) -c EnigmaMachine.cpp

clean:
	rm -rf enigma *.o

.PHONY: clean
