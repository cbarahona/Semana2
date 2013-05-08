#ifndef MENU_H
#define MENU_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

class Menu
{
    public:
        Menu(SDL_Surface *screen);
        void logic();
        virtual ~Menu();
    protected:
    private:
       // int x;
    SDL_Surface *image;
    SDL_Surface *screen;
};

#endif // MENU_H
