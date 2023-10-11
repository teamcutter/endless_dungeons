test:
	g++ -v ./main.cpp ./src/Engine.cpp ./src/SpriteManager.cpp ./src/Vector2D.cpp ./src/Transform.cpp ./src/Knight.cpp ./src/Animation.cpp ./src/RigidBody.cpp ./src/KeyboardHandler.cpp  ./src/Timer.cpp ./Vendor/tinyxml/tinystr.cpp ./Vendor/tinyxml/tinyxml.cpp ./Vendor/tinyxml/tinyxmlerror.cpp ./Vendor/tinyxml/tinyxmlparser.cpp ./src/Map.cpp ./src/TileLayer.cpp ./src/MapParser.cpp -o ./bin/test -lSDL2 -lSDL2_image && ./bin/test