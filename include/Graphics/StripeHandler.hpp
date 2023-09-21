#include <string>
#include <map>
#include <SDL2/SDL_image.h>

class StripeHandler {
private:
    StripeHandler();
    static StripeHandler* _instance;
    std::map<std::string, SDL_Texture*> _stripes;

public:
    static StripeHandler* Instance();

    bool Create(std::string id, std::string path);
    void Delete(std::string id);
    void Destroy();
    void Draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE);
};