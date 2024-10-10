#include <Servo.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

int pos0 = 102;
int pos180 = 512;

void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(50);

  delay(3000);
  iP();
  delay(2000);

  for(int i=1; i<=3;i++)
  {
    moveForward();
    delay(1000);  
  }
  iP();
  delay(2000);
  downUp();
  delay(2000);
  stretch();
  delay(2000);
  rightLeftUpDown();
  delay(2000);
  rightLeftKick();
  delay(2000);
  iP();
  delay(2000); 

//  moveForward();
//  rightUp();
//  leftUp();
//  rightUpDown();
//  leftUpDown();
//  rightLeftUpDown();
//  rightKick();
//  leftKick();
//  rightLeftKick();
//  stretch();
//  downUp();
}
String str;
void loop() 
{
       
}
void setServo(int servo, int angle) 
{
  int duty;
//  duty = map(angle, 0, 180, pos0, pos180); //(angle, minAgl, maxAgl, min_Given_Angle, max_Given_Angle)

  duty = map(angle, 0, 180, pos0, pos180); 
  
  pwm.setPWM(servo, 0, duty); // (pin,0,duty)...^
}

//initalizing...

void iP() 
{
  //left
  setServo(0, 98);
  setServo(1, 50);
  setServo(2, 55);
  setServo(3, 115);
  setServo(4, 96);

  //right
  setServo(5, 95);
  setServo(6, 135);
  setServo(7, 10);
  setServo(8, 70);
  setServo(9, 92);
}

void moveForward()
{
  
  //on the left
  for(int i=84; i<=123 ;i++)
  {
    setServo(0,i);
    delay(50);  
  }
  delay(1000);
  for(int i=95; i<=104 ;i++)
  {
    setServo(5,i);
    delay(50);  
  }
  delay(250);
  for(int i = 123; i>=95; i--)
  {
    setServo(0, i);
    delay(40); 
  }
  delay(1000);
  
  for(int i=125; i>=103; i--)
  {
    setServo(3, i);
    delay(40); 
  }
  delay(250);

  for(int i = 50; i>=45; i--)
  {
    setServo(1, i);
    delay(60); 
  }
  
  for(int i = 70; i>=60; i--)
  {
    setServo(8, i);
    delay(40); 
  }
  delay(500);
  for(int i = 135; i>=125; i--)
  {
    setServo(6, i);
    delay(60); 
  }

  for(int i = 95; i>=84; i--)
  {
    setServo(0, i);
    delay(40); 
  }
  
  //on the right 
  for(int i=104; i>= 57;i--)
  {
    setServo(5, i);
    delay(40);  
  }
  delay(1000);
  
  for(int i=57; i<= 95;i++)
  {
    setServo(5, i);
    delay(40);  
  }
  for(int i = 125; i<=135; i++)
  {
    setServo(6, i);
    delay(60); 
  }
  for(int i = 60; i<=70; i++)
  {
    setServo(8, i);
    delay(40); 
  }

  for(int i = 45; i<=50; i++)
  {
    setServo(1, i);
    delay(60); 
  }
  delay(1000);
  for(int i=103; i<=125; i++)
  {
    setServo(3, i);
    delay(40); 
  }
  delay(1000);
}

void rightUp()
{
  for(int i=98; i<=127 ;i++)
  {
    setServo(0,i);
    delay(50);  
  }
  delay(1000);
  for(int i = 95; i<=105; i++)
  {
    setServo(5, i);
    delay(40); 
  }
  delay(1000);

  for(int i = 90; i>=25; i--)
  {
    setServo(9, i);
    delay(40); 
  }
  delay(1000);
}

void rightDown()
{
  for(int i = 25; i<=90; i++)
  {
    setServo(9, i);
    delay(30); 
  }
  delay(1000);

  for(int i=125; i>=98 ;i--)
  {
    setServo(0,i);
    delay(40);  
  }
  delay(1000);

  for(int i = 104; i>=95; i--)
  {
    setServo(5, i);
    delay(60); 
  }
  delay(1000);
}

void leftUp()
{
  for(int i=95; i>=62 ;i--)
  {
    setServo(5,i);
    delay(50);  
  }
  delay(1000);
  for(int i = 100; i>=84; i--)
  {
    setServo(0, i);
    delay(40); 
  }
  delay(1000);

  for(int i = 98; i<=157; i++)
  {
    setServo(4, i);
    delay(40); 
  }
  delay(1000);
}

void leftDown()
{
  for(int i = 157; i>=100; i--)
  {
    setServo(4, i);
    delay(40); 
  }
  delay(1000);
  for(int i = 60; i<=95; i++)
  {
    setServo(5, i);
    delay(40); 
  }
  delay(1000);
  for(int i=85; i<=100;i++)
  {
    setServo(0,i);
    delay(50);  
  }
  delay(1000);
}

void rightUpDown()
{
  rightUp();
  rightDown();
}

void leftUpDown()
{
  leftUp();
  leftDown();
}

void rightLeftUpDown()
{
  rightUpDown();
  leftUpDown();
}

void rightKick()
{
  rightUp();

  //kicking...
  for(int i = 55; i<=120; i++)
  {
    setServo(2, i);
    delay(10); 
  }
  delay(500);  
  for(int i = 115; i>=75; i--)
  {
    setServo(3, i);
    delay(30); 
  }
  delay(1000);
  for(int i = 136; i<=137; i++)
  {
    setServo(6, i);
    delay(100); 
  }
  delay(1000);
  for(int i = 120; i>=80; i--)
  {
    setServo(2, i);
    delay(20); 
  }
  delay(1000);

  //back...
  for(int i = 80; i<=120; i++)
  {
    setServo(2, i);
    delay(30); 
  }
  delay(1000);
  for(int i = 137; i>=136; i--)
  {
    setServo(6, i);
    delay(100); 
  }
  delay(1000);

  for(int i = 75; i<=115; i++)
  {
    setServo(3, i);
    delay(35); 
  }
  delay(1000);

  for(int i = 120; i>=55; i--)
  {
    setServo(2, i);
    delay(10); 
  }
  delay(1000);

  //right down
  rightDown();
}

void leftKick()
{
  leftUp();
//  kicking...
  for(int i = 10; i<=80; i++)
  {
    setServo(7, i);
    delay(25); 
  }

  delay(500);  
  for(int i = 70; i<=100; i++)
  {
    setServo(8, i);
    delay(30); 
  }
  delay(1000);
  for(int i = 49; i>=48; i--)
  {
    setServo(1, i);
    delay(100); 
  }
  delay(1000);
  
  for(int i = 80; i>=6; i--)
  {
    setServo(7, i);
    delay(20); 
  }
  delay(1000);

  //back...
  for(int i = 6; i<=80; i++)
  {
    setServo(7, i);
    delay(30); 
  }
  delay(1000);
  for(int i = 48; i<=49; i++)
  {
    setServo(1, i);
    delay(100); 
  }
  delay(1000);

  for(int i = 100; i>=70; i--)
  {
    setServo(8, i);
    delay(35); 
  }
  delay(1000);

  for(int i = 80; i>=10; i--)
  {
    setServo(7, i);
    delay(25); 
  }
  delay(1000);

  //right down
  leftDown();
}

void rightLeftKick()
{
  rightKick();
  leftKick();
}

void stretch()
{
  for(int i=0; i<=30; i++)
  {
    setServo(9,90-i);  //decreasing
    setServo(4,i+98);
    setServo(0,i+95);
    setServo(5,95-i); //dcreasing
    delay(50);
  }
  delay(2000);
  for(int i=30; i>=0; i--)
  {
    setServo(9,90-i);  //decreasing
    setServo(4,i+98);
    setServo(0,i+93);
    setServo(5,95-i); //dcreasing    
    delay(50);
  }
  delay(1000);
}

void downUp()
{
  for(int i=0; i<=125; i++)
  {
    if(i<=80)
    {
      setServo(1,46+i);
      setServo(6,136-i);
    } 
    if(i==30)
    {
      for(int i = 0; i<=10; i++)
      {
        setServo(3,115+i);
        setServo(8,70-i);   
        delay(50);
      }   
    }
    if(i<=120)
    {
      setServo(2,55+i);
    }
    setServo(7,10+i);
    delay(50);
  }
  for(int i=0; i<=60; i++)
  {
    setServo(3,125-i);
    setServo(8,60+i);
    delay(50);
  }
  delay(2000);
  //back...
  for(int i=60; i>0; i--)
  {
    setServo(3,125-i);
    setServo(8,60+i);
    delay(50);
  }
  for(int i=125; i>0; i--)
  {
    if(i<=80)
    {
      setServo(1,46+i);
      setServo(6,136-i);
    }
    if(i==30)
    {
      for(int i = 0; i<=10; i++)
      {
        setServo(3,125+i);
        setServo(8,60-i);   
        delay(50);
      }
    } 
    if(i<=120)
    {
      setServo(2,55+i);
    }
    setServo(7,10+i);
    delay(50);
  }
  for(int i=0; i<=20; i++)
  {
    setServo(3,135-i);
    setServo(8,50+i);
    delay(50);
  }
  delay(1000);
}
