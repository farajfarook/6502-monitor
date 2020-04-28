#include <Arduino.h>

#define READ_WRITE PB10
#define CLK_INTR PB11

#define ADDR_LEN 16
#define DATA_LEN 8

int DATA[DATA_LEN] = {
    //D7-D4
    PA2,
    PA3,
    PA4,
    PA5,
    //D3-D0
    PA6,
    PA7,
    PB0,
    PB1,
};

int ADDR[ADDR_LEN] = {
    //A15-A12
    PA1,
    PA0,
    PC15,
    PC14,
    //A11-A8
    PB7,
    PB6,
    PB5,
    PB4,
    //A7-A4
    PB3,
    PA15,
    PA12,
    PA11,
    //A3-A0
    PB15,
    PB14,
    PB13,
    PB12,
};