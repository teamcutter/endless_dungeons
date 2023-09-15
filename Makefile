test:
	g++ main.cpp -o ./src/test -lSDL2 && ./src/test

clean:
	rm ./src/*