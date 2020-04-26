#include <Arduino.h>

#define READ_WRITE PB8
#define CLK_INTR PB9

#define ADDR_LEN 16
#define DATA_LEN 8

int ADDR[ADDR_LEN] = {
    //A0-A3
    PB12,
    PB13,
    PB14,
    PB15,
    //A4-A7
    PA11,
    PA12,
    PA15,
    PB3,
    //A8-A11
    PB4,
    PB5,
    PB6,
    PB7,
    //A12-A15
    PA3,
    PA2,
    PA1,
    PA0,
};

int DATA[DATA_LEN] = {
    //D0-D3
    PB11,
    PB10,
    PB1,
    PB0,
    //D4-D7
    PA7,
    PA6,
    PA5,
    PA4,
};