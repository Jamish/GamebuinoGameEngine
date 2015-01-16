#include "Engine.h"
#include "Enemy.h"


const byte spr_chup[][8] PROGMEM = 
{
    {8,6,0x0,0x0,0x78,0x50,0x78,0x40,},
    {8,6,0x0,0x0,0x78,0x50,0x78,0x8,},
};

const byte spr_chomp[][8] PROGMEM = 
{
    {8,6,0xFC,0xD4,0xFC,0xA8,0x80,0xFC,},
    {8,6,0x0,0xFC,0xD4,0xFC,0xA8,0xFC,},
};

Enemy::Enemy() : MovingActor() {
}

void Enemy::init(int _x, int _y, uint8_t _enemy_type) {
    MovingActor::init(_x, _y);
    dead = 0;
    type = T_ENEMY;
    enemy_type = _enemy_type;
    facing = -1;
}

void Enemy::update_chup() {
    if (!dead) {
        vx = facing / 2.0;
    }
        
    update_base();
}

void Enemy::update_chomp() {

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
        
    update_base();

    if (vx != 0) {
        vx += vx > 0 ? -fric : fric;
    }
}

void Enemy::update_base() {
    MovingActor::update();
    
    if (dead > 0) {
        dead++;
    }
    
    if (dead >= 20) {
        Actor::die();
    }
    
    //Max fall speed
    if (vy > 2.6) {
      vy = 2.6;
    }
}

void Enemy::update() {
    if (enemy_type == T_E_CHUP) {
        update_chup();
    } else if (enemy_type == T_E_CHOMP) {
        update_chomp();
    }
}

void Enemy::draw_chup(int x_screen, int y_screen) {
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
        gb.display.drawBitmap(x_screen, y_screen, spr_chup[i], NOROT, flip);
    }
    
    draw_base(x_screen, y_screen);
}

void Enemy::draw_chomp(int x_screen, int y_screen) {
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
        gb.display.drawBitmap(x_screen, y_screen, spr_chomp[i], NOROT, flip);
    }
    
    draw_base(x_screen, y_screen);
}

void Enemy::draw_base(int x_screen, int y_screen) {
    if (dead > 0 && (dead < 10 || gb.frameCount % 2)) {
        gb.display.fillRect(x_screen, y_screen + 4, SPRITE_SIZE, 2);
    }
}

void Enemy::draw(int x_screen, int y_screen) {
    if (enemy_type == T_E_CHUP) {
        draw_chup(x_screen, y_screen);
    } else if (enemy_type == T_E_CHOMP) {
        draw_chomp(x_screen, y_screen);
    }
}

void Enemy::reverse() {
    facing *= -1;
    vx = 0;
}

void Enemy::die() {
    eng.playSFX(S_KILL);
    dead = 1;
    vx = 0;
    vy = 0;
}

void Enemy::collideWith(Actor* other) {
    switch (other->type) {
        case T_ENEMY:
            reverse();
        break;
    }
}