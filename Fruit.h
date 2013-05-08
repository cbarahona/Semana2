#ifndef FRUIT_H
#define FRUIT_H


#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
class Fruit
{
    public:
        int x;
    int y;
    int velocity;
    int acceleration;
    int current_frame;
    SDL_Surface *images;
    SDL_Surface *screen;
    int frame_lenght;
    int frame_time_elapsed;
    void atacado(int x,int y);
    Fruit(SDL_Surface *screen);
    void logic();
    void render();
        Fruit();
        virtual ~Fruit();
    protected:
    private:
};

#endif // FRUIT_H
