/*
 * robOTTOs powerboard teensy firmware
 * bicolor led class (bicolor_led.cpp)
 * created: 16/MAY/2021 
 */

#include "bicolor_led.h"

BiColorLed::BiColorLed()
{
    // %
}

BiColorLed::BiColorLed(uint8_t pinRed, uint8_t pinGreen)
{
    m_pinRed = pinRed;
    m_pinGreen = pinGreen;
    pinMode(m_pinRed, OUTPUT);
    pinMode(m_pinGreen, OUTPUT);
}

void BiColorLed::setColor(enum color c)
{
    m_color = c;
    run();
}

void BiColorLed::setMode(enum mode m)
{
    if(m_mode != m)
    {
        m_blinkState = 1;
        m_blinkTimer = millis();
        m_mode = m;
        run();
    }
}

void BiColorLed::run()
{
    switch(m_mode)
    {
        case BiColorLed::ON:    if(m_color == BiColorLed::RED)
                                {
                                    digitalWrite(m_pinRed, HIGH);
                                    digitalWrite(m_pinGreen, LOW);
                                }
                                else
                                {
                                    digitalWrite(m_pinRed, LOW);
                                    digitalWrite(m_pinGreen, HIGH);
                                }
                                break;
        case BiColorLed::BLINK: if( (m_blinkTimer + m_BLINK_PERIOD) < millis() )
                                {
                                   // digitalWrite(m_pinRed, HIGH);
                                    m_blinkState = !m_blinkState;
                                    m_blinkTimer = millis();
                                    if(m_color == BiColorLed::RED)
                                    {
                                        digitalWrite(m_pinRed, m_blinkState);
                                        digitalWrite(m_pinGreen, LOW);
                                    }
                                    else
                                    {
                                        digitalWrite(m_pinRed, LOW);
                                        digitalWrite(m_pinGreen, m_blinkState);
                                    }
                                }
                                break;
        default:                digitalWrite(m_pinRed, LOW);
                                digitalWrite(m_pinGreen, LOW);
    };
}