#ifndef PLAYER_H
#define PLAYER_H
#include "SDL/SDL_mixer.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
//#include "SDL/SDL_ttf.h"
#include <string>

class Player
{
public:
    Mix_Chunk *jumpp;
    Mix_Chunk *dieEx;
    void atacado(int x,int y);
    void ismove();
    bool quit;
    int x;
    int y;
    int velocity;
    int acceleration;
    int current_frame;
    SDL_Surface *images[10];
    int zd;
    SDL_Surface salti;
    SDL_Surface *screen;
    bool gameover;
    bool isJump;
    int frame_lenght;
    int frame_time_elapsed;
    Player(SDL_Surface *screen);
    void setZD();
    void logic();
    void render();
    void jump();
    void die();
    bool isplay;
    void ispla();
    virtual ~Player();
};

#endif // PLAYER_H
