#ifndef ENEMY_H
#define ENEMY_H

#include "MovingActor.h"

class Enemy : public MovingActor {
    public:  	
        //Properties
        uint8_t dead;
        
        //Methods
    
        //Methods to Override
    	Enemy(int _x, int _y);
        void update();
        void draw(int x_screen, int y_screen);
        void die();
        void collideWith(Actor* other);        
        
    protected:
        void reverse();
        
};

#endif