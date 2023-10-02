test:
	g++ -v ./src/main.cpp ./src/Engine.cpp ./src/SpriteManager.cpp ./src/Vector2D.cpp ./src/Transform.cpp ./src/Knight.cpp -o ./bin/test -lSDL2 -lSDL2_image && ./bin/test