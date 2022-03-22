build:
	g++ -Wall -std=c++17 -I./libs/ src/*.cpp -lSDL2 -llua5.4 -o engine

run:
	./engine

clean:
	rm engine
