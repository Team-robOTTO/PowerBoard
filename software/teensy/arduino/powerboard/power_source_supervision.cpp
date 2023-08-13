/*
 * robOTTOs powerboard teensy firmware
 * power source supervision class (power_source_supervision.cpp)
 * created: 19/MAY/2021 
 */

 #include "power_source_supervision.h"

PowerSourceSupervision::PowerSourceSupervision  
    (   float threshold,
        uint8_t pin_led_red,
        uint8_t pin_led_green
    )   : m_led(pin_led_red, pin_led_green)
{
    m_state = DISCONNECTED;

    m_threshold = threshold;

    m_led.setColor(BiColorLed::RED);
    m_led.setMode(BiColorLed::ON);
}

void PowerSourceSupervision::run(float voltage)
{
    if(voltage < 1000.0f) // disconnected
    {
        m_state = DISCONNECTED;
    }
    else if(voltage > (m_threshold + 100.0f) ) // +100mV for hysteresis
    {
        m_state = CONNECTED;
    }
    else if(voltage < (m_threshold - 100.0f ))
    {
        m_state = UNDERVOLTAGE;
    }

    switch(m_state)
    {
        case DISCONNECTED:  m_led.setColor(BiColorLed::RED);
                            m_led.setMode(BiColorLed::ON);
                            break;
        case CONNECTED:     m_led.setColor(BiColorLed::GREEN);
                            m_led.setMode(BiColorLed::ON);
                            break;
        case UNDERVOLTAGE:  m_led.setColor(BiColorLed::RED);
                            m_led.setMode(BiColorLed::BLINK);
                            break;
        default:            m_led.setMode(BiColorLed::OFF);
    };
}