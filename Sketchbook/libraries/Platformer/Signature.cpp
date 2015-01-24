#include "Engine.h"
#include "Signature.h"
Signature::Signature() {
    type_byte = 0;
}

void Signature::init(uint8_t _tile_x, uint8_t _tile_y, uint8_t type, uint8_t subtype) {
    actor = NULL;
    tile_x = _tile_x;
    tile_y = _tile_y;
    type_byte = type + (subtype << 4);
}

uint8_t Signature::getType() {
    return type_byte & 0x0F;
}

uint8_t Signature::getSubType() {
    return type_byte >> 4;
}

void Signature::update() {
    
    int x = tile_x * SPRITE_SIZE;
    int y = tile_y * SPRITE_SIZE;
    int x_screen = x - eng.camera_x;
    int y_screen = y - eng.camera_y;

    // If off screen //on screen and the actor is null, initialize a new one using the types
    if(x_screen < -SPRITE_SIZE || x_screen > LCDWIDTH + (4*SPRITE_SIZE) || y_screen < -SPRITE_SIZE || y_screen > LCDHEIGHT + (4*SPRITE_SIZE)){
        // If off screen, deactivate actor (UNLESS IT'S A PLAYER).
        if (actor && getType() != T_PLAYER) {
            disable();
        }
        
    } else {
        // If on screen and actor is null
        if (!actor) {
            switch (getType()) {
                case T_PLAYER:
                    eng.player.init(x, y);
                    actor = &eng.player;
                    break;
                case T_ENEMY:
                    Enemy* p_enemy = eng.getFreeEnemy();
                    if (p_enemy) {
                        p_enemy -> init(x, y, getSubType());
                    }
                    
                    actor = p_enemy;
                    break;
            }
        }
        
    }
    
    if (actor) {
        actor->update();
        
        tile_x = actor->x / SPRITE_SIZE;
        tile_y = actor->y / SPRITE_SIZE;
        
        if (!actor->active) {
            destroy();
        }
    }
    

}

// Disable the actor (hibernate)
void Signature::disable() {
    actor->active = 1;
    actor = NULL;
}

// Destroy the actor's tie to the signature (the signature itself is deactivated (i.e., enemy dies))
void Signature::destroy() {
    actor = NULL;
    type_byte = 0;
}



