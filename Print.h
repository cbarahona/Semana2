#ifndef PRINT_H
#define PRINT_H
#include "SDL/SDL_ttf.h"
#include "StringToint.h"
#include "SDL/SDL.h"
//#include "Frames.h"
//#include "SDL/SDL.h"
class Print
{
    public:
        int score;
     int die;
   void getScore(SDL_Surface* scren);
     SDL_Color textColor;
        void prin(SDL_Surface* scren);
        void muerte();
        Print();
        TTF_Font *font ;
        SDL_Surface * score_surface ;
 SDL_Surface * score_die ;
 SDL_Surface * dies ;

        virtual ~Print();
    protected:
    private:
        bool init();

        //int upd();

};

#endif // PRINT_H
