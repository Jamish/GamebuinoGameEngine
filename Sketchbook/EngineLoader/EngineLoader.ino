#include <Engine.h>
#include <Gamebuino.h>
#include <SPI.h>

Gamebuino gb;
Engine eng;

void setup() {
    gb.begin();
    eng.begin();
       
    Serial.begin(9600);
}
   
void loop() {
    eng.update();
} 
