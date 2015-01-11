#ifndef ENEMY_H
#define ENEMY_H

#include "MovingActor.h"

class Enemy : public MovingActor {
    public:  	
        //Properties
        uint8_t dead;
        struct data {
            byte b[8]; // 8 bytes of extra AI or whatever?
        };
        
        //Methods
    
        //Methods to Override
        Enemy();
    	void init(int _x, int _y);
        void update();
        void draw(int x_screen, int y_screen);
        void die();
        void collideWith(Actor* other);        
        
    protected:
        void reverse();
        
};

#endif