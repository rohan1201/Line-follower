#include <AFMotor.h>
#include <Servo.h>
#include <NewPing.h>
int left=26;
int right=22;
int lir;
int rir;
int trig=8;
int echo=A3;
int  distl;
int distr;
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);
Servo s;
NewPing sonar(trig, echo, 200);
void setup() 
{

  s.attach(10);s
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);
  
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  pinMode(left,INPUT);
  pinMode(right,INPUT);

  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);
}

void loop() 
{
  lir=analogRead(left);
  rir=analogRead(right);
  while((lir==LOW) && (rir==LOW))
  {
    motor1.run(BACKWARD);
    motor2.run(FORWARD);
    motor3.run(BACKWARD);
    motor4.run(FORWARD);
  }
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);

  ultra();
  
  if(distr>distl)
  {
    do
    {
    motor1.run(BACKWARD);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(FORWARD);
    } while((lir!=LOW) && (rir!=LOW));
  }
  else
  {
    do
     {
     motor1.run(RELEASE);
    motor2.run(FORWARD);
    motor3.run(BACKWARD);
    motor4.run(RELEASE);
     } while((lir!=LOW) && (rir!=LOW));
   
  }
  
  
  
}
void ultra()
{
  s.write(135);
  distl=sonar.ping_cm();
  delay(2000);
  s.write(-30);
  distr=sonar.ping_cm();
  delay(2000);

}
