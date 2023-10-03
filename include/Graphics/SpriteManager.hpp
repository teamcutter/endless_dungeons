#include <string>
#include <map>
#include <SDL2/SDL_image.h>

class SpriteManager {
private:
    SpriteManager();
    static SpriteManager* _instance;
    std::map<std::string, SDL_Texture*> _sprites;

public:
    static SpriteManager* Instance();

    bool Create(std::string id, std::string path);
    void Delete(std::string id);
    void Destroy();
    void Draw(std::string id, float x, float y, int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE);
    void DrawFrame(std::string id, float x, float y, int width, int height, int row, int frame, SDL_RendererFlip flip = SDL_FLIP_NONE);
};