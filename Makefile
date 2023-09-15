test:
	g++ -v ./src/main.cpp ./src/windowrenderer.cpp -o ./bin/test -lSDL2 -lSDL2_image && ./bin/test

clean:
	rm ./src/*