/*
 * robOTTOs powerboard teensy firmware
 * power control class (power_control.h)
 * created: 16/MAY/2021 
 */

#pragma once

// Arduino standard
#include <Arduino.h>

// 3rd party
#include <Adafruit_MCP3008.h>

// own
//#include "bicolor_led.h"
#include "globals.h"
#include "power_source_supervision.h"

class PowerControl 
{
    public:
        PowerControl();
        void run();

        enum adc_ch
        {
            PS_12V_IN = 0,
            I2,
            I1,
            PS_24V_IN,
            PS,
            BAT2,
            BAT1
        };
        uint16_t readAdcVoltage(enum PowerControl::adc_ch ch);

        void updateAdcChannels();

        uint16_t getChannelValue(enum PowerControl::adc_ch ch);

        enum high_side_switch_ch
        {
            BASE,
            ARM
        };
        void controlHighSideSwitch(enum PowerControl::high_side_switch_ch ch, bool st);


    private:
        //BiColorLed m_ledBat1;
        //BiColorLed m_ledBat2;
        //BiColorLed m_ledExt;
        Adafruit_MCP3008 m_adc;
        PowerSourceSupervision m_bat1;
        PowerSourceSupervision m_bat2;
        PowerSourceSupervision m_ext;

        uint16_t readAdc(uint8_t channel);

        uint16_t m_valuePs;
        uint16_t m_valueBat1;
        uint16_t m_valueBat2;
        uint16_t m_valueI1;
        uint16_t m_valueI2;
};