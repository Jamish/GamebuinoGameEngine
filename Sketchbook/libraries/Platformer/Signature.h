#ifndef SIGNATURE_H
#define SIGNATURE_H

#include <Arduino.h>
#include "Actor.h"

class Engine;

class Signature {
    public:
        //Properties
        uint8_t type_byte;
        uint8_t tile_x;
        uint8_t tile_y;
        Actor* actor;
        
        //Methods
        Signature();
        void init(uint8_t _tile_x, uint8_t _tile_y, uint8_t type, uint8_t subtype);
        void update();
        void disable();
        void destroy();
        uint8_t getType();
        uint8_t getSubType();
};

#endif