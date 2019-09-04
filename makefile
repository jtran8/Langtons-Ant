langtonsAnt: main.o menu.o ant.o board.o inputChecker.o 
	g++ -std=c++11 main.o menu.o ant.o board.o inputChecker.o -o langtonsAnt

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

menu.o: menu.cpp
	g++ -std=c++11 -c menu.cpp

ant.o: ant.cpp
	g++ -std=c++11 -c ant.cpp

board.o: board.cpp
	g++ -std=c++11 -c board.cpp

inputChecker.o: inputChecker.cpp
	g++ -std=c++11 -c inputChecker.cpp

clean:
	rm *.o langtonsAnt
