CPP = g++
FLAGS = -Wall -Werror -pedantic -std=c++11

enigma: Main.o EnigmaMachine.o Reflector.o PlugBoard.o Rotor.o
	$(CPP) $(FLAGS) -o enigma $^

%.o: %.cpp %.hpp
	$(CPP) $(FLAGS) -o $@ -c $<

clean:
	rm -rf enigma *.o *.gch

.PHONY: clean
