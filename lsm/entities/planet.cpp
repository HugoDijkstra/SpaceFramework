#include "planet.h"

Planet::Planet() {}

Planet::~Planet() {}
Planet *Planet::generatePlanet(SDL_Renderer *renderer, Vector2 size) {
  Uint32 rmask, gmask, bmask, amask;
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
  rmask = 0xff000000;
  gmask = 0x00ff0000;
  bmask = 0x0000ff00;
  amask = 0x000000ff;
#else
  rmask = 0x000000ff;
  gmask = 0x0000ff00;
  bmask = 0x00ff0000;
  amask = 0xff000000;
#endif

  Uint32 color;

  SDL_Surface *surface;
  surface =
      SDL_CreateRGBSurfaceWithFormat(0, 16, 16, 32, SDL_PIXELFORMAT_RGBA32);

  if (surface == NULL) {
    std::cout << "Error in creating surface: " << SDL_GetError() << std::endl;
    return NULL;
  }

  srand(time(NULL));
  Uint32 *pixels = (Uint32 *)surface->pixels;
  SDL_LockSurface(surface);
  Planet *planet = new Planet();
  for (unsigned int x = 0; x < 16; x++) {
    for (unsigned int y = 0; y < 16; y++) {
      color = 0xFFFFFFFF;
      pixels[x + (y * 16)] = color;
      std::cout << "Color: " << color << std::endl;
    }
  }
  surface->pixels = (void *)pixels;
  SDL_UnlockSurface(surface);

  planet->image = new Image(SDL_CreateTextureFromSurface(renderer, surface));
  SDL_FreeSurface(surface);
  // planet->imageSize = size;
  planet->position = Vector2(300, 300);
  return planet;
}
