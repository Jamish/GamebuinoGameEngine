#ifndef ENEMYCHOMP_H
#define ENEMYCHOMP_H

#include "Enemy.h"

class EnemyChomp : public Enemy {
    public:  	
        //Properties

        //Methods
    
        //Methods to Override
        void update();
        void draw(int x_screen, int y_screen);    
        
    private:

        
};

#endif