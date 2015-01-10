#include "Engine.h"
#include "Enemy.h"

const byte sprite[][8] PROGMEM = 
{
    {8,6,0xFC,0xD4,0xFC,0xA8,0x80,0xFC,}, //standing
    {8,6,0x0,0xFC,0xD4,0xFC,0xA8,0xFC,}, //running
};


Enemy::Enemy(int _x, int _y) : MovingActor(_x, _y) {
    type = T_ENEMY;
    facing = -1;
}

void Enemy::update() {
    if (dead == 0) {
        vx = facing / 2.0;
    
        if (!air && !(eng.solidCollisionAtPosition(x + vx + (w * facing), y+1, w, h))) {
            reverse();
        }
        
        MovingActor::update();
        
        
        //Max fall speed
        if (vy > 2.6) {
          vy = 2.6;
        }
    } else {
        dead++;
    }
    
    if (dead >= 20) {
        Actor::die();
    }
}

void Enemy::draw(int x_screen, int y_screen) {
    if (dead == 0) {
        //draw a white "outline"
        gb.display.setColor(WHITE);
        gb.display.fillRect(x_screen, y_screen+1, SPRITE_SIZE, SPRITE_SIZE-1);

        uint8_t flip = NOFLIP;
        if (facing == -1) {
            x_screen -= SPRITE_SIZE/2;
            flip = FLIPH;
        }
        
        uint8_t i = ((gb.frameCount/5) % 2) == 0;
        
        gb.display.setColor(BLACK);
        gb.display.drawBitmap(x_screen, y_screen, sprite[i], NOROT, flip);
    } else {
        if (dead < 10 || gb.frameCount % 2) {
            gb.display.fillRect(x_screen, y_screen + 4, SPRITE_SIZE, 2);
        }
    }
    
}

void Enemy::reverse() {
    facing *= -1;
}

void Enemy::die() {
    eng.playSFX(S_KILL);
    dead = 1;
}

void Enemy::collideWith(Actor* other) {
    switch (other->type) {
        case T_ENEMY:
            reverse();
        break;
    }
}