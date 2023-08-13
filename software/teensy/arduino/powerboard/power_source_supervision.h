/*
 * robOTTOs powerboard teensy firmware
 * power source supervision class (power_source_supervision.h)
 * created: 19/MAY/2021 
 */

#pragma once

// Arduino standard
#include <Arduino.h>

// own
#include "bicolor_led.h"

class PowerSourceSupervision 
{
    public:
       
        PowerSourceSupervision(float threshold, uint8_t pin_led_red, uint8_t pin_led_green);

        enum power_source_state
        {
            DISCONNECTED,
            CONNECTED,
            UNDERVOLTAGE
        };

        void run(float voltage);

    private:
        BiColorLed m_led;

        float m_threshold;
        enum power_source_state m_state;
};