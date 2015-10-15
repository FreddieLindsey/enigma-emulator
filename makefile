CPP = g++
FLAGS = -Wall -Werror -pedantic -std=c++11

enigma: Main.o EnigmaMachine.o Reflector.o
	$(CPP) $(FLAGS) -o enigma $^

Main.o: Main.cpp
	$(CPP) $(FLAGS) -c Main.cpp

%.o: %.cpp %.hpp
	$(CPP) $(FLAGS) -o $@ -c $<

clean:
	rm -rf enigma *.o

.PHONY: clean
