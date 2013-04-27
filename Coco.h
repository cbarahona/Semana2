#ifndef COCO_H
#define COCO_H
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
//#include "SDL/SDL_ttf.h"
#include <string>


class Coco
{
    public:
        int x;
    int y;
    int velocity;
    int acceleration;
    int current_frame;
    SDL_Surface *images[6];
    SDL_Surface *screen;
    int frame_lenght;
    int frame_time_elapsed;

        Coco(SDL_Surface *screen);

        virtual ~Coco();
        void setX();
    void logic();
    void render();
    void jump();

    protected:
    private:
};

#endif // COCO_H
