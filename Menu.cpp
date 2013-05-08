#include "Menu.h"

Menu::Menu(SDL_Surface *screen)
{
    this->screen = screen;
    this->image = IMG_Load( "menu.png" );
    //this->x = 0;
    //ctor
}

Menu::~Menu()
{
    SDL_FreeSurface( image );
    //dtor
}
void Menu::logic(){
SDL_Rect offset;
    offset.x = 0;
    offset.y = 0;

    SDL_BlitSurface( image, NULL, screen, &offset );

}

