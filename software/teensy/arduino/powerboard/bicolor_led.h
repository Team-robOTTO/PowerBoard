/*
 * robOTTOs powerboard teensy firmware
 * bicolor led class (bicolor_led.h)
 * created: 16/MAY/2021 
 */

#pragma once

#include <Arduino.h>

class BiColorLed
{
    public:
        BiColorLed();
        BiColorLed(uint8_t pinRed, uint8_t pinGreen);

        enum color
        {
            RED,
            GREEN
        };
        void setColor(enum color c);


        enum mode
        {
            OFF,
            ON,
            BLINK
        };
        void setMode(enum mode m);

        void run();

    private:
        uint8_t m_pinRed;
        uint8_t m_pinGreen;
        enum color m_color;
        enum mode m_mode;
        bool m_blinkState;
        unsigned long m_blinkTimer;

        const unsigned long m_BLINK_PERIOD = 250; // ms
};