#ifndef MOVINGACTOR_H
#define MOVINGACTOR_H

#include "Actor.h"

class MovingActor : public Actor {
    public:
        //Properties
        int8_t facing;
        float vx;
        float vy;
        float g;
        bool air;
        
        //Methods
        
        //Methods to Override
        void init(int _x, int _y);
        void update();
        void draw(int x_screen, int y_screen);
    
    private:
        virtual void reverse();
        
};

#endif