main: main.o profile.o network.o
	g++ -o main main.o profile.o network.o -std=c++11

tests: tests.o profile.o network.o
	g++ -o tests tests.o profile.o network.o -std=c++11

network.o: network.cpp profile.h network.h

profile.o: profile.cpp profile.h

main.o: main.cpp profile.h network.h

tests.o: tests.cpp doctest.h profile.h network.h

clean:
	rm -f *.o
