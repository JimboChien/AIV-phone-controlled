// =============================================
//  Author:        JimboChien
//  Date Created:  2020/08/21
//  Last Updated:  2021/03/11 
//  Description:   ir sensor detection distance
// =============================================
int pingPin1 = 10;
int pingPin2 = 11;
int durationR,durationL,R,L;
void setup(){
  Serial.begin(9600);
}
void loop(){
  // calculate right distance
  pinMode(pingPin1,OUTPUT);
  digitalWrite(pingPin1,LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin1,HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin1,LOW);
  pinMode(pingPin1,INPUT);
  durationR = pulseIn(pingPin1,HIGH);
  // format to cm
  R = durationR/2/29;

  // calculate left distance
  pinMode(pingPin2,OUTPUT);
  digitalWrite(pingPin2,LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin2,HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin2,LOW);
  pinMode(pingPin2,INPUT);
  durationL = pulseIn(pingPin2,HIGH);
  // format to cm
  L = durationL/2/29;
  
  // print right and left distance
  Serial.print("L: ");
  Serial.print(L);
  Serial.print("cm\t\t");
  Serial.print("R: ");
  Serial.print(R);
  Serial.println("cm");
  delay(500);
}
