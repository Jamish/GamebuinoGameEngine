#include <Engine.h>
#include <tinyFAT.h>
#include <EEPROM.h>
#include <Gamebuino.h>
#include <SPI.h>

Gamebuino gb;
Engine eng;

void setup() {
    eng.begin();
       
    Serial.begin(9600);
    
}
   
void loop() {
    eng.update();
} 
