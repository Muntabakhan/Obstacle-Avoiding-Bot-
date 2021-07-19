#include <AFMotor.h>

#include <NewPing.h>

#include <Servo.h>



#define TRIGGER_PIN 10

#define ECHO_PIN 13

#define MAX_DISTANCE 500

#define MAX_SPEED 190 // sets speed of DC motors

#define MAX_SPEED_OFFSET 20



NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);



AF_DCMotor leftMotor1(1, MOTOR12_1KHZ); // create motor #1 using M1 output on Motor Drive Shield, set to 1kHz PWM frequency

AF_DCMotor leftMotor2(2, MOTOR12_1KHZ); // create motor #2, using M2 output, set to 1kHz PWM frequency

AF_DCMotor rightMotor1(3, MOTOR34_1KHZ);// create motor #3, using M3 output, set to 1kHz PWM frequency

AF_DCMotor rightMotor2(4, MOTOR34_1KHZ);// create motor #4, using M4 output, set to 1kHz PWM frequency



Servo myservo;



boolean goesForward=false;

int distance = 100;

int speedSet = 0;

String motorSet = "";

float duration, reading;

int readPing() {

delay(70);

digitalWrite(TRIGGER_PIN, LOW);

delayMicroseconds(2);

digitalWrite(TRIGGER_PIN, HIGH);

delayMicroseconds(10);

digitalWrite(TRIGGER_PIN, LOW);

duration = pulseIn(ECHO_PIN, HIGH);



reading = (duration / 2) * 0.0343;

return reading;

}





void setup() {



myservo.attach(9);

myservo.write(115);

delay(2000);

distance = readPing();

delay(100);

distance = readPing();

delay(100);

distance = readPing();

delay(100);

distance = readPing();

delay(100);

}






void loop() {

int lookLeft();
int lookRight();
void moveStop() ;
void moveBackward();
void turnRight();
void turnLeft();



int distanceR = 0;

int distanceL = 0;

delay(40);

if(distance<=15)

{

moveStop();

delay(100);

{moveBackward();}//THIS IS MY ERROR AND I THINK APPLIES TO THE REST OF MY VOID FUNCTIONS AS WELL

delay(300);

moveStop();

delay(200);

distanceR = lookRight();

delay(200);

distanceL = lookLeft();

delay(200);



if(distanceR>=distanceL)

{

turnRight();

moveStop();

}else

{

turnLeft();

moveStop();

}

}else

{

moveForward();

}

distance = readPing();

}

int lookRight()

{

myservo.write(135);

delay(100);

int distance = readPing();

delay(5000);

myservo.write(84);

delay(5000);

return distance;

}






int lookLeft()

{

myservo.write(135);

delay(100);

int distance = readPing();

delay(5000);

myservo.write(84);

delay(5000);

return distance;

}






void moveStop() {

motorSet = "STOP";

leftMotor1.run(RELEASE);

leftMotor2.run(RELEASE);

rightMotor1.run(RELEASE);

rightMotor2.run(RELEASE);

}

void moveForward() {

motorSet = "FORWARD";

leftMotor1.run(FORWARD); // turn it on going forward

leftMotor2.run(FORWARD); // turn it on going forward

rightMotor1.run(FORWARD); // turn it on going forward

rightMotor2.run(FORWARD); // turn it on going forward

for (speedSet = 0; speedSet < MAX_SPEED; speedSet +=2) // slowly bring the speed up to avoid loading down the batteries too quickly

{

leftMotor1.setSpeed(MAX_SPEED);

leftMotor2.setSpeed(MAX_SPEED);

rightMotor1.setSpeed(MAX_SPEED);

rightMotor2.setSpeed(MAX_SPEED);

delay(5);

}
}



void moveBackward() {

motorSet = "BACKWARD";

leftMotor1.run(BACKWARD); // turn it on going backward

leftMotor2.run(BACKWARD); // turn it on going backward

rightMotor1.run(BACKWARD); // turn it on going backward

rightMotor2.run(BACKWARD); // turn it on going backward

for (speedSet = 0; speedSet < MAX_SPEED; speedSet +=2) // slowly bring the speed up to avoid loading down the batteries too quickly

{

leftMotor1.setSpeed(MAX_SPEED);

leftMotor2.setSpeed(MAX_SPEED);

rightMotor1.setSpeed(MAX_SPEED);

rightMotor2.setSpeed(MAX_SPEED);

delay(5);

}

}



void turnRight() {

motorSet = "RIGHT";

leftMotor1.run(FORWARD); // turn motor 1 forward

leftMotor2.run(FORWARD); // turn motor 2 forward

rightMotor1.run(BACKWARD); // turn motor 3 backward

rightMotor2.run(BACKWARD); // turn motor 4 backward

rightMotor1.setSpeed(speedSet+MAX_SPEED_OFFSET);

rightMotor2.setSpeed(speedSet+MAX_SPEED_OFFSET);

delay(1500); // run motors this way for 1500

motorSet = "FORWARD";

leftMotor1.run(FORWARD); // set both motors back to forward

leftMotor2.run(FORWARD);

rightMotor1.run(FORWARD);

rightMotor2.run(FORWARD);

}

void turnLeft() {

motorSet = "LEFT";

leftMotor1.run(BACKWARD); // turn motor 1 backward

leftMotor2.run(BACKWARD); // turn motor 2 backward

leftMotor1.setSpeed(speedSet+MAX_SPEED_OFFSET);

leftMotor2.setSpeed(speedSet+MAX_SPEED_OFFSET);

rightMotor1.run(FORWARD); // turn motor 3 forward

rightMotor2.run(FORWARD); // turn motor 4 forward

delay(1500); // run motors this way for 1500

motorSet = "FORWARD";

leftMotor1.run(FORWARD); // turn it on going forward

leftMotor2.run(FORWARD); // turn it on going forward

rightMotor1.run(FORWARD); // turn it on going forward

rightMotor2.run(FORWARD); // turn it on going forward

}
