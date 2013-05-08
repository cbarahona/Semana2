#include "Print.h"

Print::Print()
{
    this->score=0;
     this->die=0;
  this->score_surface = NULL;
 this->score_die = NULL;
 this->dies = NULL;
this->textColor = { 100, 0, 0 };
font = TTF_OpenFont( "Press Style.ttf", 30 );
    //ctor
}

Print::~Print()
{
    SDL_FreeSurface( score_surface );
    SDL_FreeSurface( score_die );
    SDL_FreeSurface( dies );

    //dtor
}

void Print::prin(SDL_Surface* scren){

    StringToint letras;
    SDL_Rect offset;
        offset.x = 0;
        offset.y = 0;
score_surface = TTF_RenderText_Solid( font, letras.toString(score+=5).c_str(), textColor );
        SDL_BlitSurface( score_surface, NULL, scren, &offset );
        SDL_Rect offset2;
            offset2.x = 500;
            offset2.y = 0;
            SDL_Rect offset3;
            offset3.x = 400;
            offset3.y = 0;

            score_die =TTF_RenderText_Solid( font,letras.toString(die).c_str(), textColor );
            SDL_BlitSurface( score_die, NULL, scren, &offset2 );

            dies =TTF_RenderText_Solid( font,"Muertes: ", textColor );
            SDL_BlitSurface( dies, NULL, scren, &offset3 );

}
void Print::muerte(){
this->die++;
}
void Print::getScore(SDL_Surface* scren){
    StringToint letras;
    SDL_Rect offset;
        offset.x = 100;
        offset.y = 0;
score_surface = TTF_RenderText_Solid( font, letras.toString(score).c_str(), textColor );
SDL_BlitSurface( score_surface, NULL, scren, &offset );
SDL_Rect offset3;
            offset3.x = 0;
            offset3.y = 0;
dies =TTF_RenderText_Solid( font,"EL SCORE ES: ", textColor );
            SDL_BlitSurface( dies, NULL, scren, &offset3 );

}
