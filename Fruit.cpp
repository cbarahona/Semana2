#include "Fruit.h"

Fruit::Fruit(SDL_Surface *screen)
{
    this->screen = screen;
    this->images= IMG_Load( "food.png" );
    this->x = 1000;
    this->y = 400;
    this->acceleration=2;
    this->velocity=0;
    this->current_frame=0;
     this->frame_lenght=1;
    this->frame_time_elapsed=0;
    //ctor
}

Fruit::~Fruit()
{
    SDL_FreeSurface( images );
    //dtor
}
void Fruit::logic()
{
    x-=15;
    if(x<-100)
        x=1000;
}
void Fruit::render()
{
    SDL_Rect offset;

    offset.x = x - images->w/2;
    offset.y = y - images->h/2;

    SDL_BlitSurface( images, NULL, screen, &offset );
}
void Fruit::atacado(int x,int y){
if(this->x-x<50
           && this->x-x>-50
           && this->y-y<50
           && this->y-y>-50
           ){
                this->x=1200;
            }
}
