/*
 * robOTTOs powerboard teensy firmware
 * power control class (power_control.cpp)
 * created: 16/MAY/2021 
 */

#include "power_control.h"

PowerControl::PowerControl()
: m_bat1(BAT_EMPTY, PIN_LED_BAT1_RED, PIN_LED_BAT1_GREEN) 
, m_bat2(BAT_EMPTY, PIN_LED_BAT2_RED, PIN_LED_BAT2_GREEN)
, m_ext(PS_PLUGGED_IN, PIN_LED_EXT_RED, PIN_LED_EXT_GREEN)
, m_adc()
{
    // init ADC
    m_adc.begin();

    pinMode(PIN_HIGH_SIDE_BASE, OUTPUT);
    digitalWrite(PIN_HIGH_SIDE_BASE, HIGH);
    pinMode(PIN_HIGH_SIDE_ARM, OUTPUT);
    digitalWrite(PIN_HIGH_SIDE_ARM, HIGH);
}

void PowerControl::run()
{
    updateAdcChannels();

    m_bat1.run(m_valueBat1);
    m_bat2.run(m_valueBat2);
    m_ext.run(m_valuePs);
}

uint16_t PowerControl::readAdc(uint8_t channel)
{
    return m_adc.readADC(channel);
}

uint16_t PowerControl::readAdcVoltage(enum PowerControl::adc_ch ch)
{
    //return readAdc(ch);
    float calc = (float)readAdc(ch) * (5000.0f / 1024.0f) / 1900.0f * (1900.0f + 10000.0f); // TODO: calc voltage
    // 1275
    // 10000
    // u = uges * 1275 / (1275 + 10000) 
    return (uint16_t)calc;
}

void PowerControl::updateAdcChannels()
{
    m_valuePs = readAdcVoltage(PowerControl::PS);
    m_valueBat1 = readAdcVoltage(PowerControl::BAT1);
    m_valueBat2 = readAdcVoltage(PowerControl::BAT2);
    m_valueI1 = readAdc(PowerControl::I1);
    m_valueI2 = readAdc(PowerControl::I2);

}

uint16_t PowerControl::getChannelValue(enum PowerControl::adc_ch ch)
{
    switch(ch)
    {
        case PowerControl::PS:  return m_valuePs;
                                break;
        case PowerControl::BAT1:return m_valueBat1;
                                break;
        case PowerControl::BAT2:return m_valueBat2;
                                break;
        case PowerControl::I1:  return m_valueI1;
                                break;
        case PowerControl::I2:  return m_valueI2;
                                break;
        default:                return 0;
    };
    return 0;
}

void PowerControl::controlHighSideSwitch(enum PowerControl::high_side_switch_ch ch, bool st)
{
    if(ch == PowerControl::BASE)
    {
        digitalWrite(PIN_HIGH_SIDE_BASE, st);
    }
    else if(ch == PowerControl::ARM)
    {
        digitalWrite(PIN_HIGH_SIDE_ARM, st);
    }
}