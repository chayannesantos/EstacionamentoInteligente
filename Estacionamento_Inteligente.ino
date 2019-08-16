#include <LedRGB.h>
#include <LDR.h>
#include <Servo.h>

#define LDRServo A3
#define LDR1 A2
#define LDR2 A1
#define LDR3 A0
#define LED1R 6
#define LED1G 7
#define LED2R 8
#define LED2G 9
#define LED3R 10
#define LED3G 11
#define SERVO1 5

const String VAGA1 ="\"VAGA1\":";
const String VAGA2 ="\"VAGA2\":";
const String VAGA3 ="\"VAGA3\":";
const String QUANT ="\"QUANT\":";
const String CANCELA ="\"CANCELA\":";

int onthetop=0; 
int passed=0;
int quant=0;
unsigned long tempo=0;
int entrada=0;
int status_cancela=0;

LDR ldr1(LDR1);
LDR ldr2(LDR2);
LDR ldr3(LDR3);

LedRGB led1(LED1R,LED1G);
LedRGB led2(LED2R,LED2G);
LedRGB led3(LED3R,LED3G);

Servo s1;
LDR ldr4(LDRServo);

void cancelaIn(){
  if(quant<3 and s1.read()==0){
    s1.write(90); //Abre a Cancela
    tempo=millis();
    entrada=1;
  }
}

void cancelaOut(){
  if(quant>0 and s1.read()==0){
    s1.write(90);
    tempo=millis();
  }
}

String JSON_VAGAS(){
  return "{" +
              VAGA1 + String(ldr1.ocupado()) + "," +
              VAGA2 + String(ldr2.ocupado()) + "," +
              VAGA3 + String(ldr3.ocupado()) + "," +
              QUANT + String(quant)          + "," +
         "}";
}

String JSON_CANCELA() {
  if(s1.read()==90) {
    status_cancela=1;
  } else {
    status_cancela=0;
  }
  return "{" +
              CANCELA + String(status_cancela) +
         "}";
}

void acessoCancela(String comando){
  
  if(comando.startsWith("{") and comando.endsWith("}")){

    if(comando.indexOf(CANCELA +" +")>0){
      cancelaIn();
    }
    if(comando.indexOf(CANCELA +" -")>0){
      cancelaOut();
    }     
  }
}

void setup() { 
Serial.begin(115200);
s1.attach(SERVO1); //Inicia o pino do servo
s1.write(0); //Inicia a Cancela como Fechada
}

void loop() {
  if(ldr1.ocupado()) {
    led1.red();
  } else {
    led1.green();  
  }

  if(ldr2.ocupado()) {
    led2.red();
  } else {
    led2.green();  
  }

  if(ldr3.ocupado()) {
    led3.red();
  } else {
    led3.green();  
  }

  if(analogRead(LDRServo)<=120 and s1.read()==90){
      onthetop=1; //O carro esta em cima do sensor
      passed=0;
  } else {
    passed=1; // O carro já passou
  }

  if(onthetop==1 and passed==1){ //Se o carro já passou fecha a Cancela
    delay(1000);
    if(entrada==1){
      quant++;
    } else {
      quant--;
    }
    entrada=0;
    s1.write(0);
    onthetop=0; // Reseta as variaveis
    passed=0;
  }

  if(tempo!=0 and millis()-tempo>=6000 and s1.read()==90 and onthetop==0) { //Apertou mas não passou
    s1.write(0);
  }

  if(Serial.available()>0){
    String comando = Serial.readString();
    acessoCancela(comando);
  }
  Serial.println(JSON_VAGAS());
  Serial.println(JSON_CANCELA());
  
  delay(10);
}
