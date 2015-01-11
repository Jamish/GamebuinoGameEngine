#include "Engine.h"
#include "EnemyChomp.h"

const byte sprite[][8] PROGMEM = 
{
    {8,6,0xFC,0xD4,0xFC,0xA8,0x80,0xFC,},
    {8,6,0x0,0xFC,0xD4,0xFC,0xA8,0xFC,},
};

// EnemyChomp::EnemyChomp() : Enemy() {

// }

void EnemyChomp::update() {
    float fric = 1;
    if (!dead) {
        if (vx == 0 && ((gb.frameCount/5) % 2)) {
            vx = facing * 3.0;
        }
    
        //Don't fall off edges!
        if (!air && !(eng.solidCollisionAtPosition(x + vx + (w * facing), y+1, w, h))) {
            reverse();
        }
    }
        
    Enemy::update();

    //Max fall speed
    if (vy > 2.6) {
        vy = 2.6;
    }
    if (vx != 0) {
        vx += vx > 0 ? -fric : fric;
    }
}

void EnemyChomp::draw(int x_screen, int y_screen) {
    if (dead == 0) {
        //draw a white "outline"
        gb.display.setColor(WHITE);
        gb.display.fillRect(x_screen, y_screen+1, SPRITE_SIZE, SPRITE_SIZE-1);

        uint8_t flip = NOFLIP;
        if (facing == -1) {
            x_screen -= SPRITE_SIZE/2;
            flip = FLIPH;
        }
        
        uint8_t i = !((gb.frameCount/5) % 2);
        
        gb.display.setColor(BLACK);
        gb.display.drawBitmap(x_screen, y_screen, sprite[i], NOROT, flip);
    }
    
    Enemy::draw(x_screen, y_screen);
}