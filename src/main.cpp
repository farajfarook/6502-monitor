/*
 * Blink
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */
#include "./pins.h"

void onClockTick();

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
    pinMode(CLK_INTR, INPUT);

    attachInterrupt(digitalPinToInterrupt(CLK_INTR), onClockTick, RISING);
}

void onClockTick()
{
    int address = 0;
    for (size_t i = ADDR_LEN; i > 0; i--)
    {
        int bit = digitalRead(ADDR[i - 1]) ? 1 : 0;
        Serial.print(bit);
        address = (address << 1) + bit;
    }
    Serial.print('\t');

    unsigned int data = 0;
    for (int n = DATA_LEN; n < 0; n--)
    {
        int bit = digitalRead(DATA[n - 1]) ? 1 : 0;
        Serial.print(bit);
        data = (data << 1) + bit;
    }

    char output[15];
    sprintf(output, "   %04x  %c %02x", address, digitalRead(READ_WRITE) ? 'r' : 'W', data);
    Serial.println(output);
}

void loop()
{
}
