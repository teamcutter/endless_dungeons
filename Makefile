test:
	g++ -v ./src/main.cpp ./src/Engine.cpp ./src/StripeManager.cpp ./src/Vector2D.cpp ./src/Transform.cpp -o ./bin/test -lSDL2 -lSDL2_image && ./bin/test