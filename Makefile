test:
	g++ -v ./src/main.cpp ./src/Engine.cpp ./src/StripeHandler.cpp -o ./bin/test -lSDL2 -lSDL2_image && ./bin/test