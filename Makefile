test:
	g++ -v ./main.cpp ./src/Engine.cpp ./src/SpriteManager.cpp ./src/Vector2D.cpp ./src/Transform.cpp ./src/Knight.cpp ./src/Animation.cpp -o ./bin/test -lSDL2 -lSDL2_image && ./bin/test