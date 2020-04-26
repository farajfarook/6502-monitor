/*
 * Blink
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */

#include <Arduino.h>

#ifndef LED_BUILTIN
#define LED_BUILTIN PC13
#endif

#define READ_WRITE PB9
#define ADDR_LEN 16
#define DATA_LEN 8

int ADDR[ADDR_LEN] = {
    PB12,
    PB13,
    PB14,
    PB15,

    PA11,
    PA12,
    PA15,
    PB3,

    PB4,
    PB5,
    PB6,
    PB7,

    PB11,
    PB10,
    PB1,
    PB0,
};

int DATA[DATA_LEN] = {PA7, PA6, PA5, PA4, PA3, PA2, PA1, PA0};

void setup()
{
    Serial.begin(9600);
    for (size_t i = 0; i < ADDR_LEN; i++)
    {
        pinMode(ADDR[i], INPUT);
    }
    for (size_t i = 0; i < DATA_LEN; i++)
    {
        pinMode(DATA[i], INPUT);
    }
    pinMode(READ_WRITE, INPUT);
}

void loop()
{
    delay(1000);
    int address = 0;
    for (size_t i = ADDR_LEN; i > 0; i--)
    {
        int bit = digitalRead(ADDR[i - 1]) ? 1 : 0;
        Serial.print(bit);
        address = (address << 1) + bit;
    }

    //Serial.print("   ");

    //unsigned int data = 0;
    //  for (int n = DATA_LEN; n < 0; n--)
    //  {
    //      int bit = digitalRead(DATA[n - 1]) ? 1 : 0;
    //      Serial.print(bit);
    //      data = (data << 1) + bit;
    //  }

    char output[15];
    //sprintf(output, "   %04x  %c %02x", address, digitalRead(READ_WRITE) ? 'r' : 'W', data);
    sprintf(output, "\t%04x", address);
    Serial.println(output);
}
