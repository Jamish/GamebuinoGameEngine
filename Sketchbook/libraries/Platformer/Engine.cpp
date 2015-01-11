#include "Engine.h"
extern const byte font3x5[];

const byte world[] PROGMEM =
{
    98, 8,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x11, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0x00, 0x00, 0x00, 0x11, 0x10, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00, 0x11, 0x00, 0x11, 0x11, 0x11, 0x00, 0x01, 0x10, 0x00, 0x01, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0x01, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x30, 0x00, 0x00, 0x11, 0x00, 0x11, 0x11, 0x10, 0x00, 0x00, 0x00, 0x11, 0x10, 0x00, 0x00, 0x00, 0x33, 0x30, 0x30, 0x00, 0x00, 0x00, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0x00, 0x11, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00, 0x01, 0x10, 0x01, 
    0x03, 0x00, 0x00, 0x30, 0x22, 0x23, 0x22, 0x32, 0x20, 0x30, 0x11, 0x03, 0x11, 0x11, 0x10, 0x00, 0x00, 0x00, 0x11, 0x10, 0x30, 0x00, 0x22, 0x33, 0x32, 0x32, 0x20, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0x00, 0x11, 0x00, 0x00, 0x02, 0x32, 0x32, 0x22, 0x21, 0x10, 0x01, 
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0x00, 0x11, 0x00, 0x01, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
};

const byte tilemap[][8] PROGMEM = 
{
    {8,6,0xFC,0x24,0xFC,0x90,0xFC,0x48,}, // block
    {8,6,0x0,0x0,0x0,0x84,0xFC,0x84,}, // fence
    {8,6,0x30,0x68,0x9C,0xAC,0x9C,0xAC,}, //tree top / bush
    {8,6,0xFC,0x0,0x0,0x18,0xA4,0x58,}, // block top
    {8,6,0x7C,0x80,0x80,0x80,0x94,0xE8,}, // block corner
    {8,6,0x9C,0xAC,0x9C,0xAC,0x9C,0xAC,}, //tree middle
    {8,6,0x9C,0xAC,0x58,0x30,0x30,0x78,}, //tree bottom
};

const byte soundfx[][8] PROGMEM = 
{
  {0,15,59,1,2,5,7,10}, // Jump
  {0,3,70,3,2,5,7,5},// Kill
  {1,47,52,1,7,0,7,2}, // Wall jump
  {0,16,58,0,0,0,3,1},//Footstep
  {0,40,77,1,0,0,5,21},//Player Death
};
//0x8049

const uint16_t melody[] PROGMEM = {0x7091,0x7889,0x8A8,0x4A8,0x8A0,0xC98,0x8A8,0x8A8,0x8AC,0x8B4,   0x7909,0x4090,0x7889,  0x8A8,0x4A8,0x8A0,0xC98,0x8B4,0x8B4,0x8AC,0x8A8,0x2C0,0x2BC,0x1CC0,0x290,0x28C,0x1C90,0x000};
//const uint16_t melody_harm[] PROGMEM = {0x7849,0x8C8,0x4C8,0x8C0,0xCB4,0x8C8,0x8C8,0x824,0x10C8,0x8A0,0x8AC,0x10A0,0x8A0,0x8AC,0x8C0,0x8C8,0x4C8,0x8C0,0xCB4,0x8D4,0x8D4,0x81C,0x10C8,0x2C0,0x2BC,0x4C0,0x290,0x28C,0x1490,0x2C0,0x2BC,0x4C0,0x000};
const uint16_t melody_harm[] PROGMEM = {0x7849,0x898,0x498,0x890,0xC84,0x898,0x898,0x8A0,0x1098,0x870,0x87C,0x1070,0x870,0x87C,0x890,0x898,0x498,0x890,0xC84,0x8A8,0x8A8,0x8A0,0x1098,0x290,0x28C,0x490,0x260,0x25C,0x1460,0x290,0x28C,0x490,0x000};
                                              
//const uint16_t bass[] PROGMEM = {0x7849,0x438,0x854,0x438,0x438,0x424,0x438,0x424,0x438,0x854,0x454,0x438,0x454,0x438,0x424,0x430,0x440,0x44C,0x440,0x460,0x440,0x44C,0x440,0x430,0x440,0x44C,0x430,0x460,0x430,0x440,0x44C,0x000};
const unsigned int bass[] PROGMEM = {0x7849,0x408,0x824,0x408,0x408,0x424,0x408,0x424,0x408,0x824,0x424,0x408,0x424,0x408,0x424,0x400,0x410,0x41C,0x410,0x430,0x410,0x41C,0x410,0x400,0x410,0x41C,0x400,0x430,0x400,0x410,0x41C,0x000};
const uint16_t* patternSet[] PROGMEM = {melody, melody_harm, bass};
const unsigned int t_melody[] PROGMEM = {0x000,0xFFFF};
const unsigned int t_harm[] PROGMEM = {0x0001,0xFFFF};
const unsigned int t_bass[] PROGMEM = {0x0002,2,0xFFFF};


Engine::Engine() {
    //Initialize actor pointers to NULL
    for (int i = 0; i < ACTORS; i++) {
        actors[i] = NULL;
    }
}

void Engine::begin() {
	gb.begin();
    
	gb.titleScreen(F("Platformer"));
    gb.display.setFont(font3x5);
    
    gb.sound.changePatternSet(patternSet,0);
    gb.sound.changePatternSet(patternSet,1);
    gb.sound.changePatternSet(patternSet,2);
    gb.sound.command(CMD_INSTRUMENT, 0, 0, 0);
    gb.sound.command(CMD_INSTRUMENT, 0, 0, 1);
    gb.sound.command(CMD_INSTRUMENT, 0, 0, 2);
    
    //gb.sound.playTrack(t_melody, 0);
    //gb.sound.playTrack(t_harm, 1);
    //gb.sound.playTrack(t_bass, 2);
    
    
    //Delete all existing actors
    for (int i = 0; i < ACTORS; i++) {
        removeActor(i);
    }
    
    camera_x = 0;
    camera_y = 0;
   
	
	addActor(new Player(342, 36));
    //addActor(new EnemyChup(138, 36));
    //addActor(new EnemyChup(132, 36));
    //addActor(new EnemyChomp(182, 36));
}

void Engine::update() {
	if(gb.update()){
		
		if(gb.buttons.held(BTN_C, 15)){
		  begin();
		}
        
        
        // Update actors
        for (uint8_t i = 0; i < ACTORS; i++) {
            if (actors[i]) {
                actors[i]->update();
            }
        }
        
        // Trigger collisions
        for (uint8_t i = 0; i < ACTORS; i++) {
            for (uint8_t j = 0; j < ACTORS; j++) {
                //Don't collide with yourself. Don't check NULL actors
                if (j == i || !actors[i] || !actors[j]) {
                    continue; 
                }
                Actor* a = actors[i];
                Actor* b = actors[j];
                if (gb.collideRectRect(a->x, a->y, a->w, a->h, b->x, b->y, b->w, b->h)) {
                    a->collideWith(b);
                }
            }
        }
        
        // Clean up actors that were marked for deletion
        // This is so that an actor never truly deletes itself to avoid null pointer exceptions 
        // when dealing with the "other" actor in Actor::collideWith
        for (uint8_t i = 0; i < ACTORS; i++) {
            if (actors[i] && actors[i]->marked_for_deletion) {
                removeActor(i);
            }
        }
        /*
        // Draw tiles
        uint8_t w = pgm_read_byte(world);
        uint8_t h = pgm_read_byte(world + 1);
        uint16_t y, x; // Tile positions
        uint16_t ys;
        uint16_t xs;
        uint16_t byteWidth = (w + 1) >> 1;
        int16_t x_screen, y_screen;
        byte tileNumber;
        uint8_t flip, adjacent;
        for (x = 0; x < w; x++) {
            xs = x * SPRITE_SIZE;
            for (y = 0; y < h; y++) {
                ys = y * SPRITE_SIZE;
                x_screen = xs - camera_x;
                y_screen = ys - camera_y;
                
                if (x_screen < -SPRITE_SIZE || x_screen > LCDWIDTH || y_screen < -SPRITE_SIZE || y_screen > LCDHEIGHT){
                    continue; // don't draw tiles which are out of the screen
                }
                
                if (x % 2) {
                    // (world + 2): offset to get past the width and the height values
                    // + y * byteWidth: Offset to the correct row. y is the column ID, and byteWidth is the number of bytes that the map is wide (14 tiles wide at 2 tiles per byte means byteWidth is 7)
                    // + x / 2: Offset to the correct column in the row. 
                    tileNumber = (pgm_read_byte((world + 2) + y * byteWidth + x / 2) & B00001111);
                } else {
                    tileNumber = (pgm_read_byte((world + 2) + y * byteWidth + x / 2) & B11110000) >> 4;
                }
                
                // Corners & tops
                // This seems pretty inefficient to me, but it works quick and dirty, at least.
                flip = NOFLIP;
                if (tileNumber == BG_BLOCK 
                    && (tileAtPosition(xs, ys + SPRITE_SIZE) == BG_BLOCK || ys + SPRITE_SIZE >= LCDHEIGHT) //Below here is a block OR the tile is at the bottom of the screen
                    && (tileAtPosition(xs, ys - SPRITE_SIZE) != BG_BLOCK && ys - SPRITE_SIZE > 0) //Above here is air and it's not at the top of the screen
                    ) {
                    adjacent = 2;
                    if (tileAtPosition(xs - SPRITE_SIZE, ys) != BG_BLOCK) { // Check left
                        tileNumber = BG_BLOCKCORNER;
                        adjacent--;
                    }
                    if (tileAtPosition(xs + SPRITE_SIZE, ys) != BG_BLOCK){ // Check right
                        tileNumber = BG_BLOCKCORNER;
                        adjacent--;
                        flip = FLIPH;
                        x_screen -= SPRITE_SIZE/2;
                    }
                    if (adjacent == 2) {
                        tileNumber = BG_BLOCKTOP;
                    }                    
                }
                
                // Draw the proper tree segment
                if (tileNumber == BG_TREE) {
                    if (tileAtPosition(xs, ys - SPRITE_SIZE) == BG_TREE) {
                        if (tileAtPosition(xs, ys + SPRITE_SIZE) != BG_TREE) {
                            tileNumber = BG_TREEBOTTOM;
                        } else {
                            tileNumber = BG_TREEMIDDLE;
                        }
                    }
                }
                
                if (tileNumber != 0)
                {
                    gb.display.setColor(BLACK);
                    gb.display.drawBitmap(x_screen, y_screen, tilemap[tileNumber-1], NOROT, flip);
                }
            }
        }*/
        
        // Draw tiles
        uint8_t w = pgm_read_byte(world);
        uint8_t h = pgm_read_byte(world + 1);
        uint16_t y, x; // Tile positions
        uint16_t byteWidth = (w + 1) / 2;
        for (y = 0; y < h; y++) {
            for (x = 0; x < w; x++) {
                int x_screen = x * SPRITE_SIZE - camera_x;
                int y_screen = y * SPRITE_SIZE - camera_y;
                if(x_screen < -SPRITE_SIZE || x_screen > LCDWIDTH || y_screen < -SPRITE_SIZE || y_screen > LCDHEIGHT){
                    continue; // don't draw tiles which are out of the screen
                }
                
                byte tileNumber;
                if (x % 2) {
                    // (world + 2): offset to get past the width and the height values
                    // + y * byteWidth: Offset to the correct row. y is the column ID, and byteWidth is the number of bytes that the map is wide (14 tiles wide at 2 tiles per byte means byteWidth is 7)
                    // + x / 2: Offset to the correct column in the row. 
                    tileNumber = (pgm_read_byte((world + 2) + y * byteWidth + x / 2) & B00001111);
                } else {
                    tileNumber = (pgm_read_byte((world + 2) + y * byteWidth + x / 2) & B11110000) >> 4;
                }
                
                // Corners & tops
                // This seems pretty inefficient to me, but it works quick and dirty, at least.
                uint8_t flip = NOFLIP;
                if (tileNumber == BG_BLOCK) {
                    // If there is air above the tile and there's a block below the tile (or the tile is in the bottom row), then render the "top of block" images instead
                    if (tileAtPosition(x * SPRITE_SIZE, y * SPRITE_SIZE - 1) != BG_BLOCK && (tileAtPosition(x * SPRITE_SIZE, (y + 1) * SPRITE_SIZE) == BG_BLOCK || (y + 1) * SPRITE_SIZE >= LCDWIDTH)) {
                        uint8_t adjacent = 2;
                        if (tileAtPosition(x * SPRITE_SIZE - 1, y * SPRITE_SIZE) != BG_BLOCK) {
                            tileNumber = BG_BLOCKCORNER;
                            adjacent--;
                        }
                        if (tileAtPosition((x + 1) * SPRITE_SIZE, y * SPRITE_SIZE) != BG_BLOCK){
                            tileNumber = BG_BLOCKCORNER;
                            flip = FLIPH;
                            x_screen -= SPRITE_SIZE/2;
                            adjacent--;
                        }
                        if (adjacent == 2) {
                            tileNumber = BG_BLOCKTOP;
                        }
                        if (adjacent == 0)
                        {
                            tileNumber = BG_BLOCK;
                        }
                        
                    }
                }
                
                // Draw the proper tree segment
                if (tileNumber == BG_TREE) {
                    if (tileAtPosition(x * SPRITE_SIZE, (y - 1) * SPRITE_SIZE) == BG_TREE) {
                        if (tileAtPosition(x * SPRITE_SIZE, (y + 1) * SPRITE_SIZE) != BG_TREE) {
                            tileNumber = BG_TREEBOTTOM;
                        } else {
                            tileNumber = BG_TREEMIDDLE;
                        }
                    }
                }
                
                if (tileNumber != 0)
                {
                    gb.display.setColor(BLACK);
                    gb.display.drawBitmap(x_screen, y_screen, tilemap[tileNumber-1], NOROT, flip);
                }
            }
        }


        // Draw Actors
        for (int i = 0; i < ACTORS; i++) {
            if (actors[i]) {                
                int x_screen = actors[i]->x - camera_x;
                int y_screen = actors[i]->y - camera_y;
                if(x_screen < -SPRITE_SIZE || x_screen > LCDWIDTH || y_screen < -SPRITE_SIZE || y_screen > LCDHEIGHT){
                    continue; // don't draw actors which are out of the screen
                }
                actors[i]->draw(x_screen, y_screen);
            }
        }
        
        gb.display.setColor(WHITE);
        gb.display.fillRect(0,12,48,6);
        gb.display.setColor(BLACK);
        gb.display.print(F("RAM: "));
        gb.display.println(gb.getFreeRam());
        gb.display.print(F("CPU: "));
        gb.display.println(gb.getCpuLoad());
        // gb.display.print(F("cy: "));
        // gb.display.println(camera_y);
        
	}
}

// TODO: Use the world width/height to prevent the camera from exceeding those boundaries
void Engine::moveCamera(int x, int y) {
    // Prevent the camera from moving past 0
    camera_x = x < 0 ? 0 : x;
    camera_y = y < 0 ? 0 : y;
}

// TODO: There's a lot of code duplication between this and the map drawing. Gotta clean that up.
uint8_t Engine::tileAtPosition(int16_t x, int16_t y) {
    int16_t tile_x = x / SPRITE_SIZE;
    int16_t tile_y = y / SPRITE_SIZE;
    
    uint16_t w = pgm_read_byte(world);
    uint16_t h = pgm_read_byte(world + 1);
    uint16_t byteWidth = (w + 1) >> 1;
    
    // Offscreen is air
    if (tile_x < 0 || tile_x > w || tile_y < 0 || tile_y > h) {
        return 0; 
    }
     
    byte tileNumber;
    if (tile_x % 2) {
        // (world + 2): offset to get past the width and the height values
        // + y * byteWidth: Offset to the correct row. y is the column ID, and byteWidth is the number of bytes that the map is wide (14 tiles wide at 2 tiles per byte means byteWidth is 7)
        // + x / 2: Offset to the correct column in the row. 
        tileNumber = (pgm_read_byte((world + 2) + tile_y * byteWidth + tile_x / 2) & B00001111);
    } else {
        tileNumber = (pgm_read_byte((world + 2) + tile_y * byteWidth + tile_x / 2) & B11110000) >> 4;
    }
    
    return tileNumber;
     
}

bool Engine::solidCollisionAtPosition(int16_t x, int16_t y, int16_t w, int16_t h) {
    // Check the tile behind the four corners of the box. If any are touching a tile of type "1" (solid), then there's a collision. 
    // TODO: This wont work for, say, two long rectangles colliding in a "+" shape. 
    if (tileAtPosition(x, y) == BG_BLOCK) return true; //top left
    if (tileAtPosition(x + w - 1, y) == BG_BLOCK) return true; //top right
    if (tileAtPosition(x + w - 1, y + h - 1) == BG_BLOCK) return true;//bottom right
    if (tileAtPosition(x, y + h - 1) == BG_BLOCK) return true;//bottom left
    
    return false;
}


// Find a spot in the array and start managing the new actor
void Engine::addActor(Actor* actor) {
    for (uint8_t i = 0; i < ACTORS; i++) {
        if (!actors[i]) {
            actors[i] = actor;
            actor->id = i;
            break;
        }
    }
}

// Deallocate memory for the actor
void Engine::removeActor(uint8_t id) {
    delete actors[id];
    actors[id] = NULL;    
}


//Thanks to Yoda Zhang - http://www.yodasvideoarcade.com/ - //http://gamebuino.com/forum/viewtopic.php?f=17&t=1018
void Engine::playSFX(uint8_t fxno) {
    int channel = 3;
    
    gb.sound.command(0,pgm_read_byte(&soundfx[fxno][6]),0,channel); // set volume
    gb.sound.command(1,pgm_read_byte(&soundfx[fxno][0]),0,channel); // set waveform
    gb.sound.command(2,pgm_read_byte(&soundfx[fxno][5]),-pgm_read_byte(&soundfx[fxno][4]),channel); // set volume slide
    gb.sound.command(3,pgm_read_byte(&soundfx[fxno][3]),pgm_read_byte(&soundfx[fxno][2])-58,channel); // set pitch slide
    gb.sound.playNote(pgm_read_byte(&soundfx[fxno][1]),pgm_read_byte(&soundfx[fxno][7]),channel); // play note    
}