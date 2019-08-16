#ifndef LEDRGB_H_INCLUDED
#define LEDRGB_H_INCLUDED

#include <Arduino.h>

class LedRGB {

private:
    int pin1, pin2; //define as variaveis que são os pinos

public:
    LedRGB(int p1, int p2); //definição do construtor// inicializa os pinos
    void green();
    void red();
    void apagar();
};


#endif // LEDRGB_H_INCLUDED
