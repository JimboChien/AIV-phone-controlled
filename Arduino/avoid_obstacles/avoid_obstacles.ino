// ==============================================================
//  Author:        JimboChien
//  Date Created:  2020/08/22 
//  Last Updated:  2021/03/11 
//  Description:   integrate ir and servo to auto avoid obstacles
// ==============================================================
#include<Servo.h>
Servo servoright;
Servo servoleft;
int time = 1000;

int pingPin1 = 10;
int pingPin2 = 11;
long durationR,durationL,R,L;
int dis_R,dis_L;
boolean auto_mode = false;
char state;

void setup(){
  servoright.attach(12);
  servoleft.attach(13);
  Serial.begin(9600);
}

void loop(){
  // calculate and print distance
  R = disR();
  L = disL();
  
  // print right and left distance
  Serial.print("L: ");
  Serial.print(L);
  Serial.print("cm\t\t");
  Serial.print("R: ");
  Serial.print(R);
  Serial.println("cm");
  
  // control command
  char c;
  if(Serial.available()>0) {
    c=Serial.read();
    if(c == 'A') {
      auto_mode = true;
      state = 'F';
    }
    else if(c == 'S') {
      auto_mode = false;
      state = 'S';
    }
    else {
      state = c;
    }
  }

  // auto mode
  if(auto_mode == true) {
    if(R < 30 && L < 30) {
      RIGHT();
    }
    else if(R < 30 && L > 30) {
      LEFT();
    }
    else if(R > 30&& L < 30) {
      RIGHT();
    }
    else {
      FORWORD();
    }
  }
  else {  // keep previous state
    if(state == 'F') {
      FORWORD();
    }
    else if(state == 'B') {
      BACK();
    }
    else if(state == 'R') {
      RIGHT();
    }
    else if(state == 'L') {
      LEFT();
    }
    else if(state == 'S') {
      STOP();
    }
  }
  delay(time);
}

long disR(){
  pinMode(pingPin1,OUTPUT);
  digitalWrite(pingPin1,LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin1,HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin1,LOW);
  pinMode(pingPin1,INPUT);
  durationR = pulseIn(pingPin1,HIGH);
  R = durationR/2/29;
  return R;
}

long disL(){
  pinMode(pingPin2,OUTPUT);
  digitalWrite(pingPin2,LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin2,HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin2,LOW);
  pinMode(pingPin2,INPUT);
  durationL = pulseIn(pingPin2,HIGH);
  L = durationL/2/29;
  return L;
}

void STOP(){
  servoleft.writeMicroseconds(1500);
  servoright.writeMicroseconds(1500);
}

void FORWORD(){
  servoleft.writeMicroseconds(1600);
  servoright.writeMicroseconds(1400);
}

void BACK(){
  servoleft.writeMicroseconds(1400);
  servoright.writeMicroseconds(1600);
}

void LEFT(){
  servoleft.writeMicroseconds(1460);
  servoright.writeMicroseconds(1460);
}

void RIGHT(){
  servoleft.writeMicroseconds(1540);
  servoright.writeMicroseconds(1540);
}
