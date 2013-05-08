#include "Frames.h"

Frames::Frames()
{
    update=new Timer();
    update->start();

    //ctor
}

Frames::~Frames()
{
    //dtor
}

void Frames::frameCap()
{
    int frames_per_seccond = 100;
    if(update->get_ticks() < 1000 / frames_per_seccond)
    {
        //Sleep the remaining frame time
        SDL_Delay( ( 1000 / frames_per_seccond ) - update->get_ticks() );
    }
    update->start();
}
