#include "pacman.h"

pacman::pacman(SDL_Surface *screen)
{
    this->screen = screen;
    this->images[0] = IMG_Load( "pacman1.png" );
    this->images[1] = IMG_Load( "pacman2.png" );
    this->x = 0;
    this->y = 400;
    this->acceleration=2;
    this->velocity=0;
    this->current_frame=0;
     this->frame_lenght=5;
    this->frame_time_elapsed=0;
this->jumpp = Mix_LoadWAV( "wakawaka.wav" );

    //ctor
}

pacman::~pacman()
{
    SDL_FreeSurface( images[0] );
    SDL_FreeSurface( images[1] );

    //dtor
}

void pacman::logic()
{
    x+=10;
    if(x>1000)
        x=0;
}
void pacman::render(){
     SDL_Rect offset;
    offset.x = x - images[current_frame]->w/2;
    offset.y = y - images[current_frame]->h/2;
    SDL_BlitSurface( images[current_frame], NULL, screen, &offset );
    if(frame_time_elapsed>=frame_lenght){
        frame_time_elapsed=0;

    current_frame++;
    if(current_frame>1){
        current_frame=0;
    Mix_PlayChannel( -1, jumpp, 0 );
    }
}
frame_time_elapsed++;
    }

