/*This source code copyrighted by Lazy Foo' Productions (2004-2013)
and may not be redistributed without written permission.*/

//The headers
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "Background.h"
#include "Player.h"
#include "Enemy.h"
#include "Coco.h"
#include "Timer.h"
#include <string>
#include "SDL/SDL_ttf.h"
//Screen attributes
const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 500;
const int SCREEN_BPP = 32;

SDL_Surface *screen = NULL;

Timer* update;
std::string toString(int number)
{
    if (number == 0)
        return "0";
    std::string temp="";
    std::string returnvalue="";
    while (number>0)
    {
        temp+=number%10+48;
        number/=10;
    }
    for (int i=0;i<(int)temp.length();i++)
        returnvalue+=temp[temp.length()-i-1];
    return returnvalue;
}

bool init()
{
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;
    }
    //Initialize SDL_mixer
    if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
    {
        return false;
    }

    //Initialize SDL_ttf
    if( TTF_Init() == -1 )
    {
        return false;
    }

    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    //Set the window caption
    SDL_WM_SetCaption( "SDL Runner Lab Progra 3", NULL );

    //If everything initialized fine
    return true;
}

void frameCap()
{
    int frames_per_seccond = 60;
    if(update->get_ticks() < 1000 / frames_per_seccond)
    {
        //Sleep the remaining frame time
        SDL_Delay( ( 1000 / frames_per_seccond ) - update->get_ticks() );
    }
    update->start();
}

int main( int argc, char* args[] )
{
    //Initialize
    init();
    update=new Timer();
    update->start();
    SDL_Surface * game_over = IMG_Load( "game_over.png" );

    TTF_Font *font = TTF_OpenFont( "Press Style.ttf", 30 );
    SDL_Color textColor = { 100, 0, 0 };
    SDL_Surface * score_surface = NULL;
    SDL_Surface * score_die = NULL;
    SDL_Surface * dies = NULL;

    Mix_Chunk *jump = Mix_LoadWAV( "jump.wav" );
    Mix_Chunk *dieEx = Mix_LoadWAV( "explosion.wav" );

    Background background(screen);
    Player player(screen);
    Enemy enemy(screen);
    Coco enemyCoco(screen);

    SDL_Event event;
    //Quit flag
    bool quit = false;
     int score=0;
     int die=0;


    while( quit == false )
    {
        //If there's an event to handle
        if( SDL_PollEvent( &event ) )
        {
            //If a key was pressed
            if( event.type == SDL_KEYDOWN )
            {
                //Set the proper message surface
                switch( event.key.keysym.sym )
                {
                    case SDLK_ESCAPE: quit = true; break;
                   case SDLK_UP:
                        if(player.isJump==false){
                        player.jump();
                        Mix_PlayChannel( -1, jump, 0 );
                        }
                    break;
                }
            }
            //If the user has Xed out the window
            else if( event.type == SDL_QUIT )
            {
                //Quit the program
                quit = true;
            }
        }

        background.logic();
        player.logic();
        enemy.logic();
        enemyCoco.logic();
        SDL_Rect offset;
        offset.x = 0;
        offset.y = 0;

        if(player.x-enemy.x<50
           && player.x-enemy.x>-50
           && player.y-enemy.y<50
           && player.y-enemy.y>-50
           ){

                player.setZD();
            }

            if(player.x-enemyCoco.x<50
           && player.x-enemyCoco.x>-50
           && player.y-enemyCoco.y<50
           && player.y-enemyCoco.y>-50
           ){

                player.setZD();
            }

        background.render();
        player.render();
        enemy.render();
        enemyCoco.render();

        SDL_Surface * score_surface = TTF_RenderText_Solid( font, toString(score+=5).c_str(), textColor );
        SDL_BlitSurface( score_surface, NULL, screen, &offset );
        SDL_FreeSurface( score_surface );
        SDL_Rect offset2;
            offset2.x = 500;
            offset2.y = 0;
            SDL_Rect offset3;
            offset3.x = 400;
            offset3.y = 0;

            SDL_Surface * score_die =TTF_RenderText_Solid( font,toString(die).c_str(), textColor );
            SDL_BlitSurface( score_die, NULL, screen, &offset2 );
            SDL_FreeSurface( score_die );

            SDL_Surface * dies =TTF_RenderText_Solid( font,"Muertes: ", textColor );
            SDL_BlitSurface( dies, NULL, screen, &offset3 );
            SDL_FreeSurface( dies );


        if(player.gameover==true){
            SDL_Surface * score_die =TTF_RenderText_Solid( font,toString(die+=1).c_str(), textColor );
            SDL_BlitSurface( score_die, NULL, screen, &offset2 );
            SDL_FreeSurface( score_die );

            SDL_Surface * dies =TTF_RenderText_Solid( font,"Muertes: ", textColor );
            SDL_BlitSurface( dies, NULL, screen, &offset3 );
            SDL_FreeSurface( dies );
            player.gameover=false;
            Mix_PlayChannel( -1, dieEx, 0 );
        //break;
        }

        frameCap();

        //Update the screen
        if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }

    }

    while( quit == false )
    {
        //If there's an event to handle
        if( SDL_PollEvent( &event ) )
        {
            //If a key was pressed
            if( event.type == SDL_KEYDOWN )
            {
                //Set the proper message surface
                switch( event.key.keysym.sym )
                {
                    case SDLK_ESCAPE: quit = true; break;
                }
            }
            //If the user has Xed out the window
            else if( event.type == SDL_QUIT )
            {
                //Quit the program
                quit = true;
            }
        }

        SDL_Rect offset;
        offset.x = 0;
        offset.y = 0;
        SDL_BlitSurface( game_over, NULL, screen, &offset );

        frameCap();

        //Update the screen
        if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }

    }

    //SDL_Quit();

    return 0;
}
