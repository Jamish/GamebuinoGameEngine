#include "Engine.h"
#include "Enemy.h"

Enemy::Enemy() : MovingActor() {
}

void Enemy::init(int _x, int _y) {
    dead = 0;
    type = T_ENEMY;
    facing = -1;
    MovingActor::init(_x, _y);
}

void Enemy::update() {
    Serial.println(F("ENEMY!"));
    MovingActor::update();
    
    if (dead > 0) {
        dead++;
    }
    
    if (dead >= 20) {
        Actor::die();
    }
}

void Enemy::draw(int x_screen, int y_screen) {
    if (dead > 0 && (dead < 10 || gb.frameCount % 2)) {
        gb.display.fillRect(x_screen, y_screen + 4, SPRITE_SIZE, 2);
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