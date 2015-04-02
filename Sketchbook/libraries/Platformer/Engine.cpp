#include "Engine.h"
extern const byte font3x5[];

/*const byte world[] PROGMEM =
{
    98, 8,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0x00, 0x00, 0x00, 0x11, 0x10, 0x00, 0x00, 0x00, 0x03, 0x30, 0x30, 0x00, 0x11, 0x00, 0x11, 0x11, 0x11, 0x00, 0x01, 0x10, 0x00, 0x01, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0x01, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x00, 0x11, 0x11, 0x10, 0x00, 0x00, 0x00, 0x11, 0x10, 0x00, 0x00, 0x00, 0x33, 0x30, 0x30, 0x00, 0x00, 0x00, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x01, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00, 0x01, 0x10, 0x01, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x03, 0x11, 0x11, 0x10, 0x00, 0x00, 0x00, 0x11, 0x10, 0x30, 0x00, 0x22, 0x33, 0x32, 0x32, 0x20, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x11, 0x11, 0x11, 0x00, 0x00, 0x02, 0x32, 0x32, 0x22, 0x21, 0x10, 0x01, 
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x11, 0x11, 0x11, 0x00, 0x01, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
};*/

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

// const uint16_t melody[] PROGMEM = {0x7091,0x7889,0x8A8,0x4A8,0x8A0,0xC98,0x8A8,0x8A8,0x8AC,0x8B4,   0x7909,0x4090,0x7889,  0x8A8,0x4A8,0x8A0,0xC98,0x8B4,0x8B4,0x8AC,0x8A8,0x2C0,0x2BC,0x1CC0,0x290,0x28C,0x1C90,0x000};
// const uint16_t melody_harm[] PROGMEM = {0x7849,0x898,0x498,0x890,0xC84,0x898,0x898,0x8A0,0x1098,0x870,0x87C,0x1070,0x870,0x87C,0x890,0x898,0x498,0x890,0xC84,0x8A8,0x8A8,0x8A0,0x1098,0x290,0x28C,0x490,0x260,0x25C,0x1460,0x290,0x28C,0x490,0x000};
// const unsigned int bass[] PROGMEM = {0x7849,0x408,0x824,0x408,0x408,0x424,0x408,0x424,0x408,0x824,0x424,0x408,0x424,0x408,0x424,0x400,0x410,0x41C,0x410,0x430,0x410,0x41C,0x410,0x400,0x410,0x41C,0x400,0x430,0x400,0x410,0x41C,0x000};
// const uint16_t* patternSet[] PROGMEM = {melody, melody_harm, bass};
// const unsigned int t_melody[] PROGMEM = {0x000,0xFFFF};
// const unsigned int t_harm[] PROGMEM = {0x0001,0xFFFF};
// const unsigned int t_bass[] PROGMEM = {0x0002,2,0xFFFF};


Engine::Engine() {
    
}

void Engine::begin() {
	gb.begin();
   
	gb.titleScreen(F("Platformer"));
    gb.display.setFont(font3x5);
    
    
    loadWorld(2);
    
    
    
    // gb.sound.changePatternSet(patternSet,0);
    // gb.sound.changePatternSet(patternSet,1);
    // gb.sound.changePatternSet(patternSet,2);
    // gb.sound.command(CMD_INSTRUMENT, 0, 0, 0);
    // gb.sound.command(CMD_INSTRUMENT, 0, 0, 1);
    // gb.sound.command(CMD_INSTRUMENT, 0, 0, 2);
    // gb.sound.playTrack(t_melody, 0);
    // gb.sound.playTrack(t_harm, 1);
    // gb.sound.playTrack(t_bass, 2);
    
    
    camera_x = 0;
    camera_y = 0;
    camera_current_offset_x = 0;
    camera_current_offset_y = 0;
    
    /*
    addSignature(4, 6, T_PLAYER, 0);
    addSignature(26, 4, T_ENEMY, T_E_CHUP);
    addSignature(10, 2, T_ENEMY, T_E_CHUP_FLY);
    */
   
	/*
    
    player.init(342, 36);
	addActor(&player);
    enemies[0].init(138, 36, T_E_CHUP);
    addActor(&enemies[0]);
    
    */
    
    
    // chup.init(138, 36);
    // addActor(&chup);
    
    // chomp.init(182, 36);
    // addActor(&chomp);
    
    
    
    
    //delete &enemies[0];
    //enemies[0] = EnemyChup();
    //enemies[0].init(138, 36);
    
    //enemies[1] = new EnemyChup(132, 36);
    //enemies[2] = new EnemyChomp(182, 36);

}

void Engine::update() {
	if(gb.update()){
		
		if(gb.buttons.held(BTN_C, 15)){
		  begin();
		}
        
              
        // Update signatures
        for (uint8_t i = 0; i < SIGNATURES; i++) {
            signatures[i].update();
        }
        
        // Trigger collisions
        for (uint8_t i = 0; i < SIGNATURES; i++) {
            for (uint8_t j = 0; j < SIGNATURES; j++) {
                //Don't collide with yourself. Don't check NULL actors
                if (j == i || !signatures[i].actor || !signatures[j].actor) {
                    continue; 
                }
                Actor* a = signatures[i].actor;
                Actor* b = signatures[j].actor;
                if (gb.collideRectRect(a->x, a->y, a->w, a->h, b->x, b->y, b->w, b->h)) {
                    a->collideWith(b);
                }
            }
        }
        
        // move camera
        moveCamera();
                
        // Draw tiles
        uint8_t w = read(0);
        uint8_t h = read(1);
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
                    tileNumber = (read((2) + y * byteWidth + x / 2) & B00001111);
                } else {
                    tileNumber = (read((2) + y * byteWidth + x / 2) & B11110000) >> 4;
                }
                
                // Corners & tops
                // This seems pretty inefficient to me, but it works quick and dirty, at least.
                uint8_t flip = NOFLIP;
                if (tileNumber == BG_BLOCK) {
                    // If there is air above the tile and there's a block below the tile (or the tile is in the bottom row), then render the "top of block" images instead
                    if (tileAtPosition(x * SPRITE_SIZE, y * SPRITE_SIZE - 1) != BG_BLOCK && (tileAtPosition(x * SPRITE_SIZE, (y + 1) * SPRITE_SIZE) == BG_BLOCK || (y + 1) * SPRITE_SIZE >= LCDHEIGHT)) {
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
        for (int i = 0; i < SIGNATURES; i++) {
            Actor* a = signatures[i].actor;
            if (a) {                
                int x_screen = a->x - camera_x;
                int y_screen = a->y - camera_y;
                if(x_screen < -SPRITE_SIZE || x_screen > LCDWIDTH || y_screen < -SPRITE_SIZE || y_screen > LCDHEIGHT){
                    continue; // don't draw actors which are out of the screen
                }
                a->draw(x_screen, y_screen);
            }
        }
        
        // gb.display.setColor(WHITE);
        // gb.display.fillRect(0,12,48,6);
        gb.display.setColor(BLACK);
        gb.display.print(F("RAM: "));
        gb.display.println(gb.getFreeRam());
        gb.display.print(F("CPU: "));
        gb.display.println(gb.getCpuLoad());
        // gb.display.print(F("cy: "));
        // gb.display.println(camera_y);
        
	}
}

void Engine::loadWorld(uint8_t id) {
    gb.sound.begin();
    gb.display.clear();
    gb.display.persistence = true;
    gb.display.print(F("\n\35 Loading Level "));
    gb.display.print(id);
    gb.display.print(F("...\n  Don't touch the"));
    gb.display.print(F("\n      SD card"));
    gb.display.update();
    
    
    //Load from SD card
    uint16_t line = 0;
    SPI.setClockDivider(SPI_CLOCK_DIV128); //lower the SPI speed for better compatibility
    if (file.initFAT() == NO_ERROR && file.openFile("JAMISH.DAT", FILEMODE_TEXT_READ) == NO_ERROR) {
        Serial.println("Opening file.");
        char buffer[8];
        word result = 0;
        
        
        //while ((result != EOF) and (result != FILE_IS_EMPTY)) {
        //Skip to level
        for (int i = 0; i < (1024/8 + 256/8) * (id-1); i++) {
            result = file.readLn(buffer, 8);
        }
        
        for (int i = 0; i < 1024/8; i++) {            
            result = file.readLn(buffer, 8);
            
            if (result != EOF && result != FILE_IS_EMPTY) {
                for (byte j = 0; j < 8; j++){
                    EEPROM.write((i * 8) + j, buffer[j]);
                }
            }
            
            Serial.println(i);
        }
        
        for (uint8_t i = 0; i < 256/8; i++) {
            result = file.readLn(buffer, 8);
            
            if (result != FILE_IS_EMPTY) {
                addSignature(buffer[0], buffer[1], buffer[2], buffer[3]);
            }
        }
        
        file.closeFile();
    } else {
        Serial.println("File failure");
    }
    SPI.setClockDivider(SPI_CLOCK_DIV8); // Raise the speed back up
    
    gb.display.persistence = false;
    gb.display.update();
    
    
    
    
    
    /*
    byte progress = 0;
    byte tick = 0;
    byte percentage = 0;
    for (uint16_t i = 0; i < 1024; i++) {
        if (tick == 0) {
            progress++;
            percentage = (progress-1) * 3;
            if (percentage > 100) {
                percentage = 100;
            }
            
            gb.display.clear();
            gb.display.persistence = true;
            gb.display.print(F("\n\n\35 Loading World... \n\n         "));
            gb.display.print(percentage);
            gb.display.print(F("%"));
            gb.display.update();
        }
    
        byte val = pgm_read_byte(world + i);
        EEPROM.write(i, val);
        //Serial.print("Writing byte: ");
        //Serial.println(val);
        //EEPROM.write(i, i);
        //delayMicroseconds(3300);
        
        //Serial.println(read(i));
        
        tick++;
        if (tick > 29) {
            tick = 0;
        }
    }
    
    
    // for (uint16_t i = 0; i < 1024; i++) {
        // Serial.print(EEPROM.read(i));
        // Serial.print(", ");
    // }
    
    gb.display.persistence = false;
    gb.display.update();
    */
}

// TODO: Use the world width/height to prevent the camera from exceeding those boundaries
void Engine::moveCamera() {
    camera_anchor_x = player.x - (LCDWIDTH/2) + (SPRITE_SIZE/2);
    camera_anchor_y = 0;
    
    // if (!player.air) {
        // camera_target_x = SPRITE_SIZE * 2 * player.vx;
    // }
    camera_target_x = SPRITE_SIZE * 3 * player.facing;
    camera_target_y = 0;
    
    //int dist = abs(camera_target_x) - abs(camera_current_offset_x);
    
    if (camera_current_offset_x < camera_target_x) {
        camera_current_offset_x++;
    } else if (camera_current_offset_x > camera_target_x) {
        camera_current_offset_x--;
    }
    
    //camera_current_offset_x = (camera_current_offset_x*3 + camera_target_x)/4;
    camera_current_offset_y = 0;
    
    camera_x = camera_anchor_x + camera_current_offset_x;
    camera_y = camera_anchor_y + camera_current_offset_y;
    
    
    // Prevent the camera from moving past 0
    camera_x = camera_x < 0 ? 0 : camera_x;
    camera_y = camera_y < 0 ? 0 : camera_y;
}

// TODO: There's a lot of code duplication between this and the map drawing. Gotta clean that up.
uint8_t Engine::tileAtPosition(int16_t x, int16_t y) {
    int16_t tile_x = x / SPRITE_SIZE;
    int16_t tile_y = y / SPRITE_SIZE;
    
    uint16_t w = read(0);
    uint16_t h = read(1);
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
        tileNumber = (read((2) + tile_y * byteWidth + tile_x / 2) & B00001111);
    } else {
        tileNumber = (read((2) + tile_y * byteWidth + tile_x / 2) & B11110000) >> 4;
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


// Find a spot in the array and start managing the new signature
void Engine::addSignature(uint8_t tile_x, uint8_t tile_y, uint8_t type, uint8_t subtype) {
    for (uint8_t i = 0; i < SIGNATURES; i++) {
        if (!signatures[i].type_byte) {
            signatures[i].init(tile_x, tile_y, type, subtype);
            break;
        }
    }
}

// Deallocate memory for the actor
void Engine::removeSignature(uint8_t id) {
    signatures[id].disable();
}

Enemy* Engine::getFreeEnemy() {
    for (uint8_t i = 0; i < ENEMIES; i++) {
        if (!enemies[i].active) {
            return &enemies[i];
        }
    }
    
    return NULL;
}

byte Engine::read(uint16_t offset) {
    //return pgm_read_byte(world + offset);
    return EEPROM.read(offset);
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