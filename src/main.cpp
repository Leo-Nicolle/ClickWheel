#include <Arduino.h>
#include "clickwheel.h"

ClickWheel clickWheel = ClickWheel();

void setup() {
  Serial.begin(9600);

  while (!Serial) { // needed to keep leonardo/micro from starting too fast!
    delay(10);
  }
  
  Serial.println("Clickwheel test "); 
  
  // Default address is 0x5A, if tied to 3.3V its 0x5B
  // If tied to SDA its 0x5C and if SCL then 0x5D
  if (!clickWheel.begin(0x5A)) {
    Serial.println("MPR121 not found, check wiring?");
    while (1);
  }
  Serial.println("MPR121 found!");
  clickWheel.initTouchWheel(4, -20 ,1);
  delay(100);
  clickWheel.takeWheelBaseline();

}

void loop() {
  int16_t deltaWheel = clickWheel.getWheelIncrement();  
  Serial.print("deltaWheel ");
  Serial.println(deltaWheel);
  delay(100);
}
