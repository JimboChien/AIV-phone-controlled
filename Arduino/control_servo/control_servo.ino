// ====================================
//  Author:        JimboChien
//  Date Created:  2020/08/21 
//  Last Updated:  2021/03/11 
//  Description:   control servo sample
// ====================================
#include<Servo.h>
Servo servoright;
Servo servoleft;
int time=2000;
void setup()
{
  servoright.attach(12);
  servoleft.attach(13);
  Serial.begin(9600);
  servoleft.writeMicroseconds(1500);
  servoright.writeMicroseconds(1500);
  Serial.println("Input:");
  Serial.println("\tF to forword");
  Serial.println("\tf to short forword");
  Serial.println("\tB to back");
  Serial.println("\tb to short back");
  Serial.println("\tR to turn right 180 degrees");
  Serial.println("\tr to turn right 90 degrees");
  Serial.println("\tL to turn left 180 degrees");
  Serial.println("\tl to turn left 90 degrees");
  Serial.println("\tE to go right");
  Serial.println("\tQ to go left");
  Serial.println("\tC to back right");
  Serial.println("\tZ to back left");
}
void loop()
{
  servoleft.writeMicroseconds(1500);
  servoright.writeMicroseconds(1500);
  
  char c;
  if(Serial.available()>0)
  {
    c=Serial.read();
    switch(c)
    {
      case 'F':  // forword
        servoleft.writeMicroseconds(1600);
        servoright.writeMicroseconds(1400);
        delay(time);
        break;
      case 'B':  // back
        servoleft.writeMicroseconds(1400);
        servoright.writeMicroseconds(1600);
        delay(time);
        break;
      case 'f':  // short forword
        servoleft.writeMicroseconds(1520);
        servoright.writeMicroseconds(1480);
        delay(time);
        break;
      case 'b':  // short back
        servoleft.writeMicroseconds(1480);
        servoright.writeMicroseconds(1520);
        delay(time);
        break;
      case 'r':  // turn right 90 degrees
        servoleft.writeMicroseconds(1540);
        servoright.writeMicroseconds(1540);
        delay(time);
        break;
      case 'l':  // turn left 90 degrees
        servoleft.writeMicroseconds(1460);
        servoright.writeMicroseconds(1460);
        delay(time);
        break;
      case 'R':  // turn right 180 degrees
        servoleft.writeMicroseconds(1600);
        servoright.writeMicroseconds(1600);
        delay(time);
        break;
      case 'L':  // turn left 180 degrees
        servoleft.writeMicroseconds(1400);
        servoright.writeMicroseconds(1400);
        delay(time);
        break;
      case 'E':  // go right
        servoleft.writeMicroseconds(1700);
        servoright.writeMicroseconds(1460);
        delay(time);
        break;
      case 'Q':  // go left
        servoleft.writeMicroseconds(1540);
        servoright.writeMicroseconds(1300);
        delay(time);
        break;
      case 'C':  // back right
        servoleft.writeMicroseconds(1300);
        servoright.writeMicroseconds(1540);
        delay(time);
        break;
      case 'Z':  // back left
        servoleft.writeMicroseconds(1460);
        servoright.writeMicroseconds(1700);
        delay(time);
        break;
    }
  }
}
