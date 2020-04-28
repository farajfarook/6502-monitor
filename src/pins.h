#include <Arduino.h>

#define READ_WRITE PB1
#define CLK_INTR PB11

#define ADDR_LEN 16
#define DATA_LEN 8

int DATA[DATA_LEN] = {
    //D7-D4
    PA1,
    PA2,
    PA3,
    PA4,
    //D3-D0
    PA5,
    PA6,
    PA7,
    PB0,
};

int ADDR[ADDR_LEN] = {
    //A15-A12
    PA0,
    PC15,
    PC14,
    PC13,
    //A11-A8
    PB9,
    PB8,
    PB7,
    PB6,
    //A7-A4
    PB5,
    PB4,
    PB3,
    PA15,
    //A3-A0
    PB15,
    PB14,
    PB13,
    PB12,
};