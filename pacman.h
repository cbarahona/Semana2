#ifndef PACMAN_H
#define PACMAN_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
//#include "SDL/SDL_ttf.h"
#include <string>

class pacman
{
    public:
        Mix_Chunk *jumpp;
        pacman();
        pacman(SDL_Surface *screen);
        int x;
        int y;
    int velocity;
    int acceleration;
    int current_frame;
    SDL_Surface *images[2];
    SDL_Surface *screen;
    int frame_lenght;
    int frame_time_elapsed;
     void logic();
    void render();

        virtual ~pacman();
    protected:
    private:
};

#endif // PACMAN_H
