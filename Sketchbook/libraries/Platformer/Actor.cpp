#include "Engine.h"
#include "Actor.h"
Actor::Actor() {
    type = T_ACTOR;
    active = 0;
    w = SPRITE_SIZE;
    h = SPRITE_SIZE;
}

void Actor::init(int _x, int _y) {
    type = T_ACTOR;
    active = 1;
    x = _x; 
    y = _y;
    w = SPRITE_SIZE;
    h = SPRITE_SIZE;
}

void Actor::update() {

}

void Actor::draw(int x_screen, int y_screen) {

}

void Actor::collideWith(Actor* other) {

}

void Actor::die() {
    active = 0;
}