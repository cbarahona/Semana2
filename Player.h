#ifndef PLAYER_H
#define PLAYER_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
//#include "SDL/SDL_ttf.h"
#include <string>

class Player
{
public:
    int x;
    int y;
    int velocity;
    int acceleration;
    int current_frame;
    SDL_Surface *images[9];
    int zd;
    SDL_Surface salti;
    SDL_Surface *screen;

    Player(SDL_Surface *screen);
    void setZD();
    void logic();
    void render();
    void jump();
    void die();
    virtual ~Player();
};

#endif // PLAYER_H
