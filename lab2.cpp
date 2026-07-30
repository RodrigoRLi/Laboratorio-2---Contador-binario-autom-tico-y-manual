/**********************************************
*Universidad del Valle de Guatemala
*Nombre: Rodrigo Fernando Recinos Lopez
*Fecha: 31/07/2026
*Curso: Electronica digital 2
*Laboratorio 2: Contador binario automatico y sensor capacitivo
***********************************************/
//librerias
#include <Arduino.h>
#include <Arduino.h>
#include <stdio.h>
#include <stdint.h>
#define alarma 25000

//variables y pines
int bt1 = 23;
int bt2 = 22;
int bt3 = 32;
int led1 = 33;
int led2 = 25;
int led3 = 26;
int led4 = 27;
int led5 = 4;
int led6 = 18;
int led7 = 19;
int led8 = 21;
int led9 = 13;
int comparacion = 0;
int contador = 0;
int contadorbin = 0;
int  estadoanteriorbt2 = 0;
int  estadoanteriorbt1 = 0;
int estadoAlarma =  LOW;

//instanciar timer
hw_timer_t *Timer1 = NULL;

//funciones prototipo
void configTimer(void);
void IRAM_ATTR autotimer();

void IRAM_ATTR interr();
void IRAM_ATTR interr2();

//rutinas de interrupciones
//rutina de timer
void IRAM_ATTR autotimer(){
  contador++;
  if (contador > 15){
    contador=0;
  }
}
//rutina de interrupcion aumentar
void IRAM_ATTR interr(){
  contadorbin++;
  if (contadorbin > 15){
    contadorbin = 0;
  }
}
//rutina de interrupcion decrementar
void IRAM_ATTR interr2(){
  if (contadorbin < 0) {
      contadorbin = 15;
  }
  else{
    contadorbin--;
  }
}
//funcion de sensor capacitivo
void sensor(){

    if(touchRead(bt3) < 30){  
        contador = 0;
    }

}
//comparacion entre contador automatico y contador manual
void comparar()
{
 if (contador == contadorbin){
    if (!comparacion){
      estadoAlarma = !estadoAlarma;
      digitalWrite(led9,estadoAlarma);
      contador = 0;
      comparacion = 1;
    }
  }
  else{
    comparacion = 0;
  }
 
}
//funcion de casos en binario
void binario(){
 
  
  
switch (contadorbin)
  {
  case 0:
    digitalWrite(led5,LOW);
    digitalWrite(led6,LOW);
    digitalWrite(led7,LOW);
    digitalWrite(led8,LOW);
    break;
  case 1:
    digitalWrite(led5,LOW);
    digitalWrite(led6,LOW);
    digitalWrite(led7,LOW);
    digitalWrite(led8,HIGH);
    break;
  case 2:
    digitalWrite(led5,LOW);
    digitalWrite(led6,LOW);
    digitalWrite(led7,HIGH);
    digitalWrite(led8,LOW);
    break;
  case 3:
    digitalWrite(led5,LOW);
    digitalWrite(led6,LOW);
    digitalWrite(led7,HIGH);
    digitalWrite(led8,HIGH);
    break;
  case 4:
    digitalWrite(led5,LOW);
    digitalWrite(led6,HIGH);
    digitalWrite(led7,LOW);
    digitalWrite(led8,LOW);
    break;
  case 5:
    digitalWrite(led5,LOW);
    digitalWrite(led6,HIGH);
    digitalWrite(led7,LOW);
    digitalWrite(led8,HIGH);
    break;
  case 6:
    digitalWrite(led5,LOW);
    digitalWrite(led6,HIGH);
    digitalWrite(led7,HIGH);
    digitalWrite(led8,LOW);
    break;
  case 7:
    digitalWrite(led5,LOW);
    digitalWrite(led6,HIGH);
    digitalWrite(led7,HIGH);
    digitalWrite(led8,HIGH);
    break;
  case 8:
    digitalWrite(led5,HIGH);
    digitalWrite(led6,LOW);
    digitalWrite(led7,LOW);
    digitalWrite(led8,LOW);
    break;
  case 9:
    digitalWrite(led5,HIGH);
    digitalWrite(led6,LOW);
    digitalWrite(led7,LOW);
    digitalWrite(led8,HIGH);
    break;
  case 10:
    digitalWrite(led5,HIGH);
    digitalWrite(led6,LOW);
    digitalWrite(led7,HIGH);
    digitalWrite(led8,LOW);
    break;
  case 11:
    digitalWrite(led5,HIGH);
    digitalWrite(led6,LOW);
    digitalWrite(led7,HIGH);
    digitalWrite(led8,HIGH);
    break;
  case 12:
    digitalWrite(led5,HIGH);
    digitalWrite(led6,HIGH);
    digitalWrite(led7,LOW);
    digitalWrite(led8,LOW);
    break;
  case 13:
    digitalWrite(led5,HIGH);
    digitalWrite(led6,HIGH);
    digitalWrite(led7,LOW);
    digitalWrite(led8,HIGH);
    break;
  case 14:
    digitalWrite(led5,HIGH);
    digitalWrite(led6,HIGH);
    digitalWrite(led7,HIGH);
    digitalWrite(led8,LOW);
    break;
  case 15:
    digitalWrite(led5,HIGH);
    digitalWrite(led6,HIGH);
    digitalWrite(led7,HIGH);
    digitalWrite(led8,HIGH);
    break;
  }
}
//funcion casos en binario automatico
void autobinario(){
  
  switch (contador)
  {
  case 0:
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
    break;
  case 1:
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,HIGH);
    break;
  case 2:
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,LOW);
    break;
  case 3:
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,HIGH);
    break;
  case 4:
    digitalWrite(led1,LOW);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
    break;
  case 5:
    digitalWrite(led1,LOW);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,LOW);
    digitalWrite(led4,HIGH);
    break;
  case 6:
    digitalWrite(led1,LOW);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,LOW);
    break;
  case 7:
    digitalWrite(led1,LOW);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,HIGH);
    break;
  case 8:
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
    break;
  case 9:
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,HIGH);
    break;
  case 10:
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,LOW);
    break;
  case 11:
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,HIGH);
    break;
  case 12:
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
    break;
  case 13:
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,LOW);
    digitalWrite(led4,HIGH);
    break;
  case 14:
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,LOW);
    break;
  case 15:
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,HIGH);
    break;
  }
}

//definimos variables
void setup() {
  //configuración timer contador automatico
  configTimer();
  //leds de contador binario automatico
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  //leds de contador binario
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  //leds de alarma comparativo
  pinMode(led9, OUTPUT);
  //adjuntar interrupciones
  attachInterrupt(23,&interr,RISING);
  attachInterrupt(22,&interr2,RISING);
}

void loop() {
  
  autobinario();

  binario();
  
  comparar();
  
  sensor();


}
//definir temporizador
void configTimer(void){
  Timer1 = timerBegin(0,800, true);
  timerAttachInterrupt(Timer1, &autotimer, true);
  timerAlarmWrite(Timer1,alarma,true);
  timerAlarmEnable(Timer1);
}

