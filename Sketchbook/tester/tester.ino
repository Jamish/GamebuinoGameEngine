#include <Gamebuino.h>
#include <SPI.h>
extern const byte font3x5[];
const byte tile[] PROGMEM = {8,6,0xFC,0x24,0xFC,0x90,0xFC,0x48,};
Gamebuino gb;


void setup() {
    gb.begin();
}
   
void loop() {
  if(gb.update()){
    gb.display.setFont(font3x5);
    gb.display.print(F("CPU: "));
    gb.display.println(gb.getCpuLoad());
    
    for (int i = 0; i < LCDWIDTH; i += 6) {
      for (int j = 5; j < LCDHEIGHT; j += 6) {
        gb.display.drawBitmap(i, j, tile, 0, 0);
      }
    }
  }
} 
