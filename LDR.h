#ifndef LDR_H_INCLUDED
#define LDR_H_INCLUDED

#include <Arduino.h>

class LDR {

private:
    int pin1;

public:
    LDR(int pin);
    bool ocupado();
};





#endif // LDR_H_INCLUDED
