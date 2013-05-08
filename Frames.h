#ifndef FRAMES_H
#define FRAMES_H

#include "Timer.h"
class Frames
{
    public:
        Frames();
        Timer* update;
        void frameCap();
        virtual ~Frames();
    protected:
    private:
};

#endif // FRAMES_H
