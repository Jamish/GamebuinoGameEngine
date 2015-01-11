#include "Engine.h"
#include "EnemyChomp.h"

const byte sprite[][8] PROGMEM = 
{
    {8,6,0x0,0x0,0x78,0x50,0x78,0x40,},
    {8,6,0x0,0x0,0x78,0x50,0x78,0x8,},
};

// EnemyChup::EnemyChup() : Enemy() {

// }

void EnemyChup::update() {
    Serial.println(F("CHUP!"));
    if (!dead) {
        vx = facing / 2.0;
    }
        
    Enemy::update();

    //Max fall speed
    if (vy > 2.6) {
      vy = 2.6;
    }    
}

void EnemyChup::draw(int x_screen, int y_screen) {
    if (dead == 0) {
        //draw a white "outline"
        gb.display.setColor(WHITE);
        gb.display.fillRect(x_screen, y_screen+1, w, h-1);

        uint8_t flip = NOFLIP;
        if (facing == -1) {
            x_screen -= SPRITE_SIZE/2;
            flip = FLIPH;
        }
        
        uint8_t i = ((gb.frameCount/5) % 2) == 0;
        
        gb.display.setColor(BLACK);
        gb.display.drawBitmap(x_screen, y_screen, sprite[i], NOROT, flip);
    }
    
    Enemy::draw(x_screen, y_screen);
}