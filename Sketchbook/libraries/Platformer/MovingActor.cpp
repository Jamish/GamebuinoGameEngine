#include "Engine.h"
#include "MovingActor.h"


MovingActor::MovingActor(int _x, int _y) : Actor(_x, _y) {
    type = T_MOVINGACTOR;
    vx = 0;
    vy = 0;
    g = 0.60;
}

void MovingActor::update() {
    int sign = vx > 0 ? 1 : -1;
    int vx_check = vx > 0 ? ceil(vx) : floor(vx); //If x is 0 velocity is 0.25 or -0.25, we want to check at -1 or 1, not 0
    if (eng.solidCollisionAtPosition(x + vx_check, y, w, h)) {
        for (int i = 0; i <= abs(vx_check); i++) {
            int x_check = x + (sign * i);
            if (eng.solidCollisionAtPosition(x_check, y, w, h)) {
                //Found the wall. Move to previous spot.
                x = x_check - (sign * 1);
                vx = 0;
                reverse();
                break;
            }
        }
    }
    
    x += vx;
    
    sign = vy > 0 ? 1 : -1;
    int vy_check = vy > 0 ? ceil(vy) : floor(vy); //If x is 0 velocity is 0.25 or -0.25, we want to check at 0, not -1 or 1.
    if (eng.solidCollisionAtPosition(x, y + vy_check, w, h)) {
        for (int i = 1; i <= abs(vy_check); i++) {
            int y_check = y + (sign * i);
            if (eng.solidCollisionAtPosition(x, y_check, w, h)) {
                //Found the floor/ceiling. Move to previous spot.
                y = y_check - (sign * 1);
                vy = 0;
                break;
            }
        }
    }
    
    y += vy;
    
    air = !eng.solidCollisionAtPosition(x, y + 1, w, h);
        
    if (air) {
        vy += g;
    }
    
    
    Actor::update();
}


void MovingActor::draw(int x_screen, int y_screen) {
    Actor::draw(x_screen, y_screen);
}

void MovingActor::reverse() {
}