#ifndef ENEMY_H
#define ENEMY_H

#include "MovingActor.h"

#define T_E_CHUP 0
#define T_E_CHOMP 1
#define T_E_CHUP_FLY 2

class Enemy : public MovingActor {
    public:  	
        //Properties
        uint8_t dead;
        uint8_t enemy_type;
        
        // struct data {
            // byte b[8]; // 8 bytes of extra AI or whatever?
        // };
        
        //Methods
        
        //Methods to Override
        Enemy();
    	void init(int _x, int _y, uint8_t _enemy_type);
        void update();
        
        void draw(int x_screen, int y_screen);
        void die();
        void collideWith(Actor* other);        
        
    protected:
        void reverse();
        void update_chup();
        void update_chomp();
        void update_chup_fly();
        void update_base();
        
        void draw_chup(int x_screen, int y_screen);
        void draw_chomp(int x_screen, int y_screen);
        void draw_chup_fly(int x_screen, int y_screen);
        void draw_base(int x_screen, int y_screen);
        
};

#endif