#ifndef ACTOR_H
#define ACTOR_H

#include <Arduino.h>

class Engine;

class Actor {
    public:
        //Properties
        uint8_t type;
        uint8_t id;
        bool active;
        float x;
        float y;
        uint8_t w;
        uint8_t h;
        
        //Methods
        Actor();
        virtual void init(int _x, int _y);
        virtual void update();
        virtual void draw(int x_screen, int y_screen);
        virtual void collideWith(Actor* other);
        virtual void die();
        
        
};

#endif