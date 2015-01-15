#ifndef ENGINE_H
#define ENGINE_H

#include <Arduino.h>
#include <SPI.h>
#include <Gamebuino.h>

#include "Actor.h"
#include "Player.h"
#include "Enemy.h"
#include "EnemyChup.h"
#include "EnemyChomp.h"


//crap
extern Gamebuino gb;
extern Engine eng;

#define ACTORS 4
#define SPRITE_SIZE 6

#define T_ACTOR 0
#define T_MOVINGACTOR 1
#define T_PLAYER 2
#define T_ENEMY 3

#define S_JUMP 0
#define S_KILL 1
#define S_WALLJUMP 2
#define S_STEP 3
#define S_PLAYERDIE 4

#define BG_BLOCK 1
#define BG_FENCE 2
#define BG_TREE 3
#define BG_BLOCKTOP 4
#define BG_BLOCKCORNER 5
#define BG_TREEMIDDLE 6
#define BG_TREEBOTTOM 7


class Engine {
    public:
		Actor* actors[ACTORS];
        Player player;
        Enemy enemies[8];
        
        void begin();
		void update();
        void moveCamera(int x, int y);
        
        uint8_t tileAtPosition(int16_t x, int16_t y);
        bool solidCollisionAtPosition(int16_t x, int16_t y, int16_t w, int16_t h);
        void addActor(Actor* actor);
        void removeActor(uint8_t id);
        void playSFX(uint8_t number);
        Engine();

    private:
        int camera_x, camera_y;
};

#endif