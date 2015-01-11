#ifndef PLAYER_H
#define PLAYER_H

#include "MovingActor.h"

class Player : public MovingActor {
    public:
        //Properties
        uint8_t ani_timer;
        long ani_next;
        uint8_t ani_length;
        uint8_t ani_current;
        uint8_t ani_frame;
        bool invuln_frame; // A little hack so the player doesn't die when stomping on two enemies at once
        
        //Methods
        void ani_restart();
        
        //Methods to Override
        void init(int _x, int _y);
        void update();
        void draw(int x_screen, int y_screen);
        void die();
        void collideWith(Actor* other);
        
        
    private:
        void jump();
        
        
};

#endif