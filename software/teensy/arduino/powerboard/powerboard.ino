/*
 * robOTTOs powerboard teensy firmware
 * main file (powerboard.ino)
 * created: 16/MAY/2021 
 */

#include "power_control.h"

PowerControl pc;

unsigned long time;

//bool toggle;

void setup()
{
  Serial.begin(9600);

  time = millis();

 // toggle = true;
}

void loop()
{
  pc.run();

  if( (time + 1000 ) < millis() ) // every 1000ms
  {
    time = millis();
    Serial.print(pc.getChannelValue(PowerControl::PS));
    Serial.print("\t");
    Serial.print(pc.getChannelValue(PowerControl::BAT1));
    Serial.print("\t");
    Serial.print(pc.getChannelValue(PowerControl::BAT2));
    Serial.print("\t");
    Serial.print(pc.getChannelValue(PowerControl::I1));
    Serial.print("\t");
    Serial.println(pc.getChannelValue(PowerControl::I2));

    //toggle = !toggle;
    //pc.controlHighSideSwitch(PowerControl::BASE, toggle);
  }
}