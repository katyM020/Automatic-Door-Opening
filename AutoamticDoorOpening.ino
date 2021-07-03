#include <LiquidCrystal.h>  //library used for lcd
#include<Servo.h>  // library used for servo motor
Servo servo;
const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int sensorPin = 8;
int obstacle;  //variable that determine the value of the sensor whether it is high or low
void setup() {
  // intilizing the size of the lcd, 16row and 2 column 
  lcd.begin(16, 2); 
   // positing the cursor to write automatic door in row zero and coloumn 0 as the index of the LCD starts from 0  
  lcd.setCursor(0,0); 
  lcd.println("*Automatic Door*");
  //this function attach means the power pin is connected/attached to which pin in the Arduino
  servo.attach(9);  
  pinMode(sensorPin, INPUT);
   // used for debugging by receiving messages and information in which state the sensor is, in serial moniter
  Serial.begin(9600);  
}

void loop() {
   //obstacle variable is equalized to the sensor, then in the if condition saying what the obstacle do if high or low
  obstacle = digitalRead(sensorPin); 
                                        
  if
  (obstacle == LOW)

  {
    Serial.println("NO movement detected!");
    //moving the cursor of the lcd to the second row
    lcd.setCursor(0,1);  
    lcd.println(" *****Closed*****");
    // the angle of the motor that it turns to
    servo .write(0);   
  }
  else
  {
    /* this delay is written for the time duration that have to be done to open the door and print the statement "movement detected". In other words if the
    the value of the sensor is high and the object is detected there will be delay 500 (0.0005 second)*/
    delay(500);
    Serial.println("Movement detected!");
    // moving the cursor of the lcd to the second row
    lcd.setCursor(0,1);  
    lcd.println(" *****Opened*****");
    //the angle of the motor that it turns to
    servo.write(120);  
  }
  delay(500);
}
