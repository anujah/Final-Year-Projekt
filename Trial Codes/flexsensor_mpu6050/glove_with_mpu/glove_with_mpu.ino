#include <SoftwareSerial.h>
#include <Wire.h>
#include <MPU6050.h>

SoftwareSerial ESPserial(2, 4); // RX | TX

MPU6050 sensor ;
int16_t ax, ay, az ;
int16_t gx, gy, gz ;




void setup() {

  Serial.begin(115200);
  Wire.begin ( );
  //Serial.println  ( "Initializing the sensor" ); 
  sensor.initialize ( ); 
  //Serial.println (sensor.testConnection ( ) ? "Successfully Connected" : "Connection failed"); 
   delay (1000); 
  //Serial.println ( "Taking Values from the sensor" );
  delay (1000);
}

void loop() {
    sensor.getMotion6 (&ax, &ay, &az, &gx, &gy, &gz);
    ax = map (ax, -17000, 17000, 180, 0) ;
    ay = map (ay, -17000, 17000, 0, 180) ;
     az = map (az, -17000, 17000, 0, 180) ;

   if(az<130)
    { Serial.println("There is a throw");
     Serial.print("Z axis:  ");Serial.println(az);
    }
     
    delay(200);
}
