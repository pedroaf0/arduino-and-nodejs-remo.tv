// inclui bibilioteca do servomotor
#include <Servo.h> 

// define pinos dos servos
#define pinServ1 2
#define pinServ2 3
#define pinServ3 4
#define pinServ4 5

// define as portas dos potenciometros
#define pot1 A0
#define pot2 A1
#define pot3 A2
#define pot4 A3

// nomeia os servos
Servo serv1,serv2,serv3,serv4;

// cria as variavies dos angulos de cada motor
int motor1,motor2,motor3,motor4;

int m1,m2,m3 = 0;
int m4 = 50;
void setup() {

  //inicia o monitor serial
  Serial.begin(9600); 

  // atribui pinos dos servos
  serv1.attach(pinServ1);
  serv2.attach(pinServ2);
  serv3.attach(pinServ3);
  serv4.attach(pinServ4);
  
}
boolean boca = true;
void loop(){
  if (Serial.available()){  // if something has been typed and is in the Serial buffer
    char c = Serial.read(); // read 1 character from serial monitor, store it in variable c
    switch (c)
    {
       case 'q':
       if(boca){
        m1 = 115;
        boca = false;
        }else{
          m1 = 0;  
          boca = true;
          }
         
       break;
       case 'w':
       m2 += 5;
       break;
       case 's':
       m2 -= 5;
       break;
       case 'e':
       m3 += 5;
       break;
       case 'd':
       m3 -= 5;
       break;
       case 'r':
       m4 += 5;
       break;
       case 'f':
       m4 -= 5;
       break;
       case 'z':
       m1 = 0;
       m2 = 0;
       m3 = 0;
       m4 = 50;
       break;
    }
  }
  serv1.write(m1);
  serv2.write(m2);
  serv3.write(m3);
  serv4.write(m4);

 delay(100);

}