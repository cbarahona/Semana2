#include "Player.h"

Player::Player(SDL_Surface *screen)
{
    this->screen = screen;
    this->images[0] = IMG_Load( "player/1.png" );
    this->images[1] = IMG_Load( "player/2.png" );
    this->images[2] = IMG_Load( "player/3.png" );
    this->images[3] = IMG_Load( "player/4.png" );
    this->images[4] = IMG_Load( "player/5.png" );
    this->images[5] = IMG_Load( "player/perder01.png" );
    this->images[6] = IMG_Load( "player/perder02.png" );
    this->images[7] = IMG_Load( "player/perder03.png" );
    this->images[8] = IMG_Load( "player/perder04.png" );
    this->images[9] = IMG_Load( "player/perder05.png" );

    this->x = 200;
    this->y = 0;
    this->acceleration=2;
    this->velocity=0;
    this->current_frame=0;
    this->zd=0;
}

Player::~Player()
{
    SDL_FreeSurface( images[0] );
    SDL_FreeSurface( images[1] );
    SDL_FreeSurface( images[2] );
    SDL_FreeSurface( images[3] );
    SDL_FreeSurface( images[4] );
}

void Player::logic()
{
    y+=velocity;
    velocity+=acceleration;
    if(y>=500-images[current_frame]->w/2)
    {
        y=500-images[current_frame]->w/2;
        velocity=0;
    }
}

void Player::jump()
{
    this->zd=1;
    velocity=-30;

}

void Player::render(){
    SDL_Rect offset;
    if(this->zd==0){
    offset.x = x - images[current_frame]->w/2;
    offset.y = y - images[current_frame]->h/2;

    SDL_BlitSurface( images[current_frame], NULL, screen, &offset );

    current_frame++;
    if(current_frame>3)
        current_frame=0;
    }else if(zd==1){
    offset.x = x - images[4]->w/2;
    offset.y = y - images[4]->h/2;

    SDL_BlitSurface( images[4], NULL, screen, &offset );
    if(this->velocity==10){
        this->zd=0;
    }
    }else if(zd>=3){

    offset.x = x - images[current_frame]->w/2;
    offset.y = y - images[current_frame]->h/2;

    SDL_BlitSurface( images[current_frame], NULL, screen, &offset );

    current_frame++;
    zd++;
    }
}
void Player::setZD(){
    this->zd=3;
     this->current_frame=5;
}
