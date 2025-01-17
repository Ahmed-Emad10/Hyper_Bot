#include<string.h>






/*     we have 5 sensors arranged like this...


                                                                                   [2]
                                                                                   straight
                                                                     [1]                           [3]
                                                                     Left                          Right
                                                   [0]                                                              [4]
                                                   sharpLeft                                                        sharpRight



*we read from all 5 sensors with very small delays in between readings to prevent interference on the single ADC
*in this version we implemented 5 functions for motor motion (go straight, turn sharp left, turn left, turn sharpright, turn right, start/stop)
*left motor is motor A, right motor is motor B
*/

//reading variables for sensors
int readingSharpLeft;
int readingSharpRight;
int readingLeft;
int readingRight;
int readingStraight;


//booleans used in toggles
bool startmotion;
bool buttonpress0;
bool buttonpress1;



#define enA 10                    //enable motor A
#define enB 9                   //enable motor B
#define in1 6                    //for motor A
#define in2 7                    //for motor B
#define in3 11                   //for motor B
#define in4 12                   //for motor B
#define button 4


#define sensorSharpLeft A0
#define sensorSharpRight A1
#define sensorLeft A2
#define sensorRight A3
#define sensorStraight A4




int speedP;                       //speed of motor
int pwmOutputA = 0;
int pwmOutputB = 0;



void check_button()                   //assuming the button gives 1 when pressed down
{
  buttonpress0 = buttonpress1;
  buttonpress1 = digitalRead(button);
}



void turnSharpLeft()
{
  pwmOutputA = 40;
  pwmOutputB = 0;
  analogWrite(enA, pwmOutputA); // Send PWM signal to L298N Enable pin
  analogWrite(enB, pwmOutputB); // Send PWM signal to L298N Enable pin
  delay(20);
}


void turnSharpRight()
{
  pwmOutputB = 40;
  pwmOutputA = 0;
  analogWrite(enA, pwmOutputA); // Send PWM signal to L298N Enable pin
  analogWrite(enB, pwmOutputB); // Send PWM signal to L298N Enable pin
  delay(20);
}


void turnLeft()
{
  pwmOutputA = 80;
  pwmOutputB = 30;
  analogWrite(enA, pwmOutputA); // Send PWM signal to L298N Enable pin
  analogWrite(enB, pwmOutputB); // Send PWM signal to L298N Enable pin
  delay(20);
}


void turnRight()
{
  pwmOutputB = 80;
  pwmOutputA = 30;
  analogWrite(enA, pwmOutputA); // Send PWM signal to L298N Enable pin
  analogWrite(enB, pwmOutputB); // Send PWM signal to L298N Enable pin
  delay(20);
}

void goStraight()
{
  pwmOutputB = 100;
  pwmOutputA = 100;
  analogWrite(enA, pwmOutputA); // Send PWM signal to L298N Enable pin
  analogWrite(enB, pwmOutputB); // Send PWM signal to L298N Enable pin
  delay(20);
}



void setup(){
  Serial.begin(9600);
  delay(50);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A0, INPUT);
  pinMode(A2, INPUT);
  pinMode(A1, INPUT);


  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  Serial.println("hello1");

//ASSUMING ONE DIRECTION ONLYYYYY
//IE (WHEN SHARP TURNING LEFT, WE HOLD ONE MOTOR AT SPEED 0 WHILE THE OTHER AT ANY SMALL SPEED)
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);


  startmotion = false;

  
}

//dunno about those variables but they are used for timers instead of delays
unsigned long t0 = 0;
unsigned long t1 = 0;
bool flag = false;

void loop(){
goStraight();
//this is previous code

    /*
    while((readingSharpLeft != 0) && (readingSharpRight != 0))
    {
    
        while((readingLeft != 0) && (readingRight != 0))
        {
          goStraight(); 
        }
    
      if(readingLeft == 0)
      {
        turnLeft();  
      }
      else if(readingRight == 0)
      {
        turnRight();
      }
    }
    
     if(readingSharpLeft == 0)
     {
        turnSharpLeft();
     }
     else if(readingSharpRight == 0)
     {
        turnSharpRight();
     }

      */
      

}
