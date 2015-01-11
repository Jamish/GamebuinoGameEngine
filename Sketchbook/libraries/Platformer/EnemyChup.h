#ifndef ENEMYCHUP_H
#define ENEMYCHUP_H

#include "Enemy.h"

class EnemyChup : public Enemy {
    public:  	
        //Properties

        //Methods
    
        //Methods to Override
        void update();
        void draw(int x_screen, int y_screen);    
        
    private:

        
};

#endif