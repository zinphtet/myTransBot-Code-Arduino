#include<SoftwareSerial.h>
#include<Servo.h>
Servo Ser1;
Servo Ser2;
Servo Ser3;
Servo Ser4;
Servo Ser5;
Servo Ser6;
Servo Ser7;

  int IN1 = 2;
  int IN2 = 3;
  int EnA = 5;

  int IN3 = 4;
  int IN4 = 7;
  int EnB = 6;

  unsigned int input;

void setup() {
  Serial.begin(9600);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(EnA,OUTPUT);
  
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(EnB,OUTPUT);

  pinMode(13,OUTPUT);

  Ser1.attach(A0);
   Ser1.attach(A1);
    Ser1.attach(A2);
     Ser1.attach(A3);
      Ser1.attach(A4);
       Ser1.attach(A5);
        Ser1.attach(12);
}

void loop() {
  if (Serial.available()>0){
   input = Serial.read();
    Serial.println(input);

    if(input>=216 && input <=250){
      input = map (input,216,250,0,180);
      Ser1.write(input);
    }

else if(input>=181 && input <=215){
      input = map (input,181,215,0,180);
      Ser2.write(input);
    }

else if(input>=146 && input <=180){
      input = map (input,146,180,0,180);
      Ser3.write(input);
    }
else if(input>=111 && input <=145){
      input = map (input,111,145,0,180);
      Ser4.write(input);
    }
else if(input>=76 && input <=110){
      input = map (input,76,110,0,180);
      Ser5.write(input);
    }

else if(input>=41 && input <=75){
      input = map (input,41,75,0,180);
      Ser6.write(input);
    }
else if(input>=6 && input <=40){
      input = map (input,6,40,0,180);
      Ser1.write(input);
    }
else if(input>=1 && input <=4){
  
  RunCar();
  digitalWrite(13,HIGH);
}

    else 
{
  Stop();
  digitalWrite(13,LOW);
}

    
  }

}
void RunCar(){
  if(input ==1){
  Forward();
}

 else if(input==2){
  Back();
}
else if(input == 3){
    Left();
  }
 else if(input == 4){
    Right();
  }
  else {
    Stop();
  }

}


void Forward(){
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  analogWrite(EnA,200);

  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  analogWrite(EnB,200);
  
}

void Back(){
   digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  analogWrite(EnA,200);

  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  analogWrite(EnB,200);  
}

void Right(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  analogWrite(EnA,0);

  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  analogWrite(EnB,200);  
}
void Left(){
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  analogWrite(EnA,200);

  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
  analogWrite(EnB,0);  
}
void Stop(){
  analogWrite(EnA,0);
  analogWrite(EnB,0);
}
