/*This source code copyrighted by Lazy Foo' Productions (2004-2013)
and may not be redistributed without written permission.*/

//The headers
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "Background.h"
#include "Player.h"
#include "Enemy.h"
#include "Coco.h"
#include "Frames.h"
#include "Print.h"
#include "Menu.h"
#include "pacman.h"
#include "Fruit.h"
//Screen attributes
const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 500;
const int SCREEN_BPP = 32;
SDL_Surface *screen = NULL;
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


int main( int argc, char* args[] )
{
    //Initialize
    init();
    SDL_Surface * game_over = IMG_Load( "game_over.png" );
    Print impri;
    Background background(screen);
    Player player(screen);
    Enemy enemy(screen);
    Coco enemyCoco(screen);
    Menu menus(screen);
    pacman pac(screen);
    Fruit fru(screen);
    Frames frx;
    SDL_Event event;
    //Quit flag
    bool quit = false;
    while( quit == false ){
        if(player.isplay==false){
       // menus.logic();
        //If there's an event to handle
        if( SDL_PollEvent( &event ) )
        {
            //If a key was pressed
            if( event.type == SDL_KEYDOWN )
            {
                //Set the proper message surface
                switch( event.key.keysym.sym )
                {
                    case SDLK_SPACE:
                        player.ispla();
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

        menus.logic();
        pac.logic();
        fru.logic();
        fru.atacado(pac.x,pac.y);
        pac.render();
        fru.render();


        if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }

    }else{
       // SDL_FreeSurface( menux );
        player.ismove();
        background.logic();
        player.logic();
        enemy.logic();
        enemyCoco.logic();
        player.atacado(enemy.x,enemy.y);
        player.atacado(enemyCoco.x,enemyCoco.y);
        background.render();
        player.render();
        enemy.render();
        enemyCoco.render();
        quit=player.quit;
        if(player.gameover==true){

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
                    case SDLK_SPACE:
                        player.isplay=true;
                         impri.muerte();
            player.gameover=false;
            impri.score=0;
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
        SDL_Rect offset;
        offset.x = 0;
        offset.y = 0;
        SDL_BlitSurface( game_over, NULL, screen, &offset );
        impri.getScore(screen);
        if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }

       // break;
        }else{
        impri.prin(screen);
        }
        frx.frameCap();
        //Update the screen
        if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }
    }
    }
    /*while( quit == false )
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
        impri.getScore(screen);
        if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }
        frx.frameCap();
    }*/
    //SDL_Quit();
    return 0;
}
