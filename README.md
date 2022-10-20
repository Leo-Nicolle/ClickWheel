# ClickWheel

Arduino clickwheel controller with MPR121. 

I am using [Adafruit MPR121](https://learn.adafruit.com/adafruit-mpr121-12-key-capacitive-touch-sensor-breakout-tutorial), did not test with other MPR121 breakouts. 

### How to design the PCB? 

There are good articles [here](https://bryanduxbury.com/2013/12/05/designing-a-capacitive-touch-wheel-in-openscad-and-eagle/) and [there](https://www.patternagents.com/news/2013/11/24/eagle-touch-widgets-library.html)
 about how to do it. 

### Who did the job ? 
 - This code is originally from [Adafruit MPR121 Library](https://github.com/adafruit/Adafruit_MPR121)
 - Then it's been adapted to handle click wheel by [Peter A Jansen](https://github.com/PeterAJansen) to [handle click wheel](https://github.com/tricorderproject/arducordermini/tree/e6ff23335c06cd4f6410152471ade1856c504c26) 
 - I just changed a few lines here and there to make it fit my use case.

### How to use ? 
 
 ```cpp
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
 ```