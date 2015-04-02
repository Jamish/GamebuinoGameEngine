#include "Engine.h"
#include "Player.h"

const byte guy[][8] PROGMEM = 
{
    {8,6, 0x78, 0x50, 0x78, 0xFC, 0x78, 0xCC,}, //standing
    {8,6,0x78,0x50,0xFC,0x78,0xF8,0xC,}, //running
    {8,6,0x78,0x50,0x78,0xFC,0x78,0x18,},
    {8,6,0x78,0x68,0x78,0x78,0x78,0x30,},
    {8,6,0x78,0x70,0x78,0xFC,0x78,0x60,},
    {8,6,0x78,0x78,0xFC,0x78,0xF8,0xC,},
    {8,6,0x78,0x70,0x78,0xFC,0x78,0x18,},
    {8,6,0x78,0x68,0x78,0x78,0x78,0x30,},
    {8,6,0x78,0x50,0x78,0xFC,0x78,0x60,}, //end running
};

const byte ani_list[][8] PROGMEM = 
{
    {1, 2, 3, 4, 5, 6, 7, 8}, //running animation
};



void Player::init(int _x, int _y) {
    MovingActor::init(_x, _y);
    
    type = T_PLAYER;
    facing = 1;
    
    ani_timer = 0;
    ani_next = gb.frameCount + ani_timer;
    ani_length = 8;
    ani_frame = 0;
    ani_current = 0; // running
}

void Player::update() {
    uint8_t left = gb.buttons.repeat(BTN_LEFT, 1);
    uint8_t right = gb.buttons.repeat(BTN_RIGHT, 1);
    uint8_t up = gb.buttons.repeat(BTN_UP, 1);
    uint8_t down = gb.buttons.repeat(BTN_DOWN, 1);
    uint8_t a = gb.buttons.repeat(BTN_A, 1);
    uint8_t b = gb.buttons.repeat(BTN_B, 1);
    uint8_t b_press = gb.buttons.pressed(BTN_B);
    uint8_t b_released = gb.buttons.released(BTN_B);
    
    
    float fric = .25;
    float speed = .2;
    float runSpeed = .28;
    
    if (a) {
        fric = .15;
    }
    
    if (air) {
        speed = .15;
        runSpeed = .15;
        fric = 0;
    }
     
    float maxSpeed = 2;
    float maxRunSpeed = 2.6;

    //Running left
    if (left) {
        if (a && !air) { //Can only "run faster" when on ground. Otherwise, being in the air is like you're not running.
            vx -= runSpeed;
            vx = vx < -maxRunSpeed ? -maxRunSpeed : vx; // limit it to max run speed
        } else {
            if (vx > -maxSpeed) { //only increase speed if you're slower than maxSpeed, not maxRunSpeed (so you decelerate from running)
                vx -= speed;
                vx = vx < -maxSpeed ? -maxSpeed : vx; // limit it to max speed 
            }
            
        }
        if (!air) {
            facing = -1;
        }
    }
    
    //Running right
    if (right) {
        if (a && !air) { //Can only "run faster" when on ground. Otherwise, being in the air is like you're not running.
            vx += runSpeed;
            vx = vx > maxRunSpeed ? maxRunSpeed : vx; // limit it to max run speed
        } else {
            if (vx < maxSpeed) { //only increase speed if you're slower than maxSpeed, not maxRunSpeed (so you decelerate from running)
                vx += speed;
                vx = vx > maxSpeed ? maxSpeed : vx; // limit it to max speed
            }
            
        }
        if (!air) {
            facing = 1;
        }
    }
    
    // When moving left, slow down if you're not holding left OR you're not holding A and you're going faster than maxSpeed (i.e., you were running and let go of A but kept holding left)
    if (vx < 0 && (!left || (!a && vx < -maxSpeed))) {
        vx += fric;
        vx = vx > 0 ? 0 : vx;
    }
    if (vx > 0 && (!right || (!a && vx > maxSpeed))) {
        vx -= fric;
        vx = vx < 0 ? 0 : vx;
    }
    
    //Jumping
    int8_t wallJumpDirection = 0;
    if (eng.solidCollisionAtPosition(x + 2, y, w, h) && (left || right)) {
        wallJumpDirection = -1; //Jump off a right wall toward the left
    }
    if (eng.solidCollisionAtPosition(x - 1, y, w, h) && (left || right)) {
        wallJumpDirection = 1; //Jump off a left wall toward the right. This one has a threshold of 1 instead of 2 because of floats always rounding down when cast to int.
    }
    
    bool canWallJump = wallJumpDirection != 0 && air && !invuln_frame; // Cannot wall jump the same frame as killing an enemy

    if (b_press && (!air || canWallJump)) {
        jump();
        if (canWallJump) {
            vx = maxSpeed * wallJumpDirection;
            facing = wallJumpDirection;
            eng.playSFX(S_WALLJUMP);
        } else {
            eng.playSFX(S_JUMP);
        }
        
    }
    
    //Gravity is magically reduced in the first half of the jump when holding B
    g = 0.60;
    if (b && air && vy < 0) {
        g = 0.20;
    }
    
    //Max fall speed
    if (vy > 2.6) {
      vy = 2.6;
    }
    
    invuln_frame = 0;
    
    MovingActor::update();
    
    // From here on out is animation related stuff
    
    if (abs(vx) > 0) {
        ani_timer = 5;
    } 
    if (abs(vx) >= 1) {
        ani_timer = 4;
    }
    if (abs(vx) >= 2) {
        ani_timer = 3;
    }
    if (abs(vx) == maxRunSpeed) {
        ani_timer = 2;
    }

    if (gb.frameCount >= ani_next) {
        ani_frame++;
        ani_frame %= ani_length;
        ani_next = gb.frameCount + ani_timer;
    }
    
    if (air || vx == 0) {
        ani_restart();
    }
    
    //DEBUGGING
    gb.display.cursorX = 0;
    gb.display.cursorY = 0;
    gb.display.print(F("("));
    gb.display.print(x);
    gb.display.print(F(","));
    gb.display.print(y);
    gb.display.println(F(")"));
    // gb.display.print(F("vx: "));
    // gb.display.println(vx);
    // gb.display.print(F("vy: "));
    // gb.display.println(vy);
    //gb.display.print(gb.getFreeRam());
}

void Player::draw(int x_screen, int y_screen) {
    //draw a white "outline"
    gb.display.setColor(WHITE);
    gb.display.fillRect(x_screen+1, y_screen+1, 4, 1); //White his eyes
    
    uint8_t flip = NOFLIP;
    if (facing == -1) {
        x_screen -= SPRITE_SIZE/2;
        flip = FLIPH;
    }
     
    
    gb.display.setColor(BLACK);
    if (vx != 0 && !air) {
        //Draw running
        uint8_t bitmap_index = pgm_read_byte(&ani_list[ani_current][ani_frame]);
        // if (bitmap_index == 1 || bitmap_index == 5) {
            // gb.sound.playTick(); // Footsteps :3
        // }
        gb.display.drawBitmap(x_screen, y_screen, guy[bitmap_index], NOROT, flip);
    } else {
        //Draw standing
        uint8_t bitmap_index = 0;
        
        //Draw jump (going up or going down)
        if (air) {
            bitmap_index = vy < 0 ? 4 : 1;
            if (abs(vy) < 0.5) {
                bitmap_index = 2;
            }
        }
        
        
        gb.display.drawBitmap(x_screen, y_screen, guy[bitmap_index], NOROT, flip);
    }
}

void Player::ani_restart() {
    ani_next = gb.frameCount + ani_timer;
    ani_frame = 0;
}

void Player::jump() {
    if (abs(vx) > 2.35) {
        vy = -3.1;
    } else if (abs(vx) > 2.4) {
        vy = -2.8;
    } else {
        vy = -2.6;
    }
    
    air = 1;
}

void Player::die() {
    eng.playSFX(S_PLAYERDIE);
    Actor::die();
}

void Player::collideWith(Actor* other) {
    switch (other->type) {
        case T_ENEMY:
            
            Enemy* o = static_cast<Enemy*>(other);
            if (!o->dead) {
                if (vy > 0) {
                    o->die();
                    jump();
                    invuln_frame = 1;
                } else if (!invuln_frame) {
                    die();
                }
            }
            break;
    }
}