#include "LDR.h"

LDR::LDR(int pin){
    pin1=pin;
    pinMode(pin1,INPUT);
}

bool LDR::ocupado(){
    if(analogRead(pin1)<=120){
        return true;
    } else {
        return false;
    }
}
