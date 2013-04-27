#ifndef ENEMY_H
#define ENEMY_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
//#include "SDL/SDL_ttf.h"
#include <string>

class Enemy
{
public:
    int x;
    int y;
    int velocity;
    int acceleration;
    int current_frame;
    SDL_Surface *images[3];
    SDL_Surface *screen;
    int frame_lenght;
    int frame_time_elapsed;

    Enemy(SDL_Surface *screen);
    void setX();
    void logic();
    void render();
    void jump();

    virtual ~Enemy();
};

#endif // ENEMY_H
