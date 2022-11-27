#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  150 
#define SERVOMAX  600 
#define LEFTFRONT1 0
#define LEFTFRONT2 1
#define LEFTFRONT3 2
#define LEFTBACK1 3
#define LEFTBACK2 4
#define LEFTBACK3 5
#define RIGHTFRONT1 6
#define RIGHTFRONT2 7
#define RIGHTFRONT3 8
#define RIGHTBACK1 9
#define RIGHTBACK2 10
#define RIGHTBACK3 11
  int i=0;
  int k=0;
void setup() {
  Serial.begin(9600);
  Serial.println("16 channel Servo test!");
  pwm.begin(); 
  pwm.setPWMFreq(40); 
  
}
void standby(){
    pwm.setPWM(LEFTFRONT1, 0, angleToPulse(90) );
    pwm.setPWM(LEFTFRONT2, 0, angleToPulse(45) );
    pwm.setPWM(LEFTFRONT3, 0, angleToPulse(90) );
    pwm.setPWM(LEFTBACK1, 0, angleToPulse(90) );
    pwm.setPWM(LEFTBACK2, 0, angleToPulse(45) );
    pwm.setPWM(LEFTBACK3, 0, angleToPulse(90) );
    pwm.setPWM(RIGHTFRONT1, 0, angleToPulse(90) );
    pwm.setPWM(RIGHTFRONT2, 0, angleToPulse(135) );
    pwm.setPWM(RIGHTFRONT3, 0, angleToPulse(90) );
    pwm.setPWM(RIGHTBACK1, 0, angleToPulse(90) );
    pwm.setPWM(RIGHTBACK2, 0, angleToPulse(135) );
    pwm.setPWM(RIGHTBACK3, 0, angleToPulse(90) );
}

void trot(){
  for (i=0;  i<25; i+5){
    pwm.setPWM(LEFTFRONT2, 0, angleToPulse(45-i) );
    pwm.setPWM(RIGHTBACK2, 0, angleToPulse(135+i) );
    if (i>=25){
      pwm.setPWM(LEFTFRONT2, 0, angleToPulse(45) );
      pwm.setPWM(RIGHTBACK2, 0, angleToPulse(135) );
      k=0;
      for (k=0;  k<25; k+5){
        pwm.setPWM(LEFTBACK2, 0, angleToPulse(45-k) );
        pwm.setPWM(RIGHTFRONT2, 0, angleToPulse(135-k) );
        if (k>=25){
          pwm.setPWM(LEFTBACK2, 0, angleToPulse(45) );
          pwm.setPWM(RIGHTFRONT2, 0, angleToPulse(135) );
          i=0;
        }
      }
    }
  }
  
  
}
void loop() {
    standby();
}

/*
 * angleToPulse(int ang)
 * gets angle in degree and returns the pulse width
 * also prints the value on seial monitor
 * written by Ahmad Nejrabi for Robojax, Robojax.com
 */
int angleToPulse(int ang){
   int pulse = map(ang,0, 180, SERVOMIN,SERVOMAX);// map angle of 0 to 180 to Servo min and Servo max 
   Serial.print("Angle: ");Serial.print(ang);
   Serial.print(" pulse: ");Serial.println(pulse);
   return pulse;
}
