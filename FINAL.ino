#include <Wire.h>

#include <MPU6050.h>

#include <Servo.h>   

Servo sgx,sgy,sgy1;
          
const int flexPin = A0; 

int servo_pin1 = 9;

int servo_pin2 = 10;

int servo_pin3 = 6;

int value;

MPU6050 sensor ;

int16_t ax, ay, az ;

int16_t gx, gy, gz ;
  
void setup ( )

{ 

sgx.attach ( servo_pin1 );
sgy.attach ( servo_pin2 );
sgy1.attach ( servo_pin3 );

Wire.begin ( );

Serial.begin  (9600); 

Serial.println  ( "Initializing the sensor" ); 

sensor.initialize ( ); 

Serial.println (sensor.testConnection ( ) ? "Successfully Connected" : "Connection failed"); 

delay (1000); 

Serial.println ( "Taking Values from the sensor" );

delay (1000);

}




void loop ( ) 

{ 

sensor.getMotion6 (&ax, &ay, &az, &gx, &gy, &gz);

ax = map (ax, 17000, -17000, 180, 0) ;
ay = map (ay, -17000, 17000, 0, 180) ;

Serial.println (ax);

sgx.write (ax); 
sgy.write (ay);
value = analogRead(flexPin);         
  Serial.println(value); 
if(value < 950){
      sgy1.write(140);}

       else{ sgy1.write(0);}

/*value = analogRead(flexPin);         
  Serial.println(value);               
  value = map(value, 750,950, 180, 0);
  sgy1.write(value);
  //analogWrite(servo_pin3, value);
//`sgy1.write(ay);*/
delay (50);

}
