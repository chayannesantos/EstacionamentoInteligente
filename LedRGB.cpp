#include "LedRGB.h"

LedRGB::LedRGB(int p1, int p2){

pin1=p1; //Inicializando os pinos
pin2=p2;

pinMode(pin1,OUTPUT); //defini os pinos como saida
pinMode(pin2,OUTPUT);

}

void LedRGB::green(){

digitalWrite(pin1,HIGH);
digitalWrite(pin2,LOW);

}

void LedRGB::red(){

digitalWrite(pin1,LOW); //RGB é do tipo anodo
digitalWrite(pin2,HIGH);

}

void LedRGB::apagar(){

digitalWrite(pin1,HIGH);
digitalWrite(pin2,HIGH);

}
