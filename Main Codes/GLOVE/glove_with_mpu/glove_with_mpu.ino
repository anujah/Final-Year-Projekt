
#include <SoftwareSerial.h>
#include <Wire.h>
#include <MPU6050.h>

SoftwareSerial ESPserial(2, 4); // RX | TX

MPU6050 sensor ;
int16_t ax, ay, az ;
int16_t gx, gy, gz ;


  int flex0=0;
  int flex1=1;
  int flex2=2;
  int flex3=3;

  int ledpin[]={9,3,6,5};//5 for detecting the throw
  int thumb;
  int ring;
  int nndexfinger;
  int middle;

void setup() {

  Serial.begin(115200);
  for(int i =0;i<4;i++)
{pinMode(ledpin[i],OUTPUT);
  }
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
    //ax = map (ax, -17000, 17000, 180, 0) ;
    //ay = map (ay, -17000, 17000, 0, 180) ;
    az = map (az, -17000, 17000, 0, 180) ;

    ring=analogRead(flex0);
middle=analogRead(flex1);
nndexfinger=analogRead(flex2);
//thumb=analogRead(flex3);

Serial.println(ring);
Serial.println(middle);
Serial.println(nndexfinger);
//Serial.println(thumb);


if(ring<555 && ring>510)
 if(middle<630 && middle>610)
  if(nndexfinger<555 && nndexfinger>500)
  //if( thumb <490 &&nndexfinger >450)
{
  Serial.println( "glove is straight");
  digitalWrite(9,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(3,LOW);
}
else
{digitalWrite(9,LOW);

}

if(ring<450 && ring>300)
 if(middle<600 && middle>560)
  if(nndexfinger<400 && nndexfinger>330)
  //if( thumb <545 && nndexfinger>530)
{
  Serial.println( "THUMBS UP");
  digitalWrite(3,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(9,LOW);
}
else
{digitalWrite(3,LOW);
}

if(ring<450 && ring>350)
 if(middle<620 && middle>585)
  if(nndexfinger<550 && nndexfinger>400)
 // if( thumb <580 &&nndexfinger> 565)
{
  Serial.println( "PEACE");
  digitalWrite(6,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(3,LOW);
}
else
{digitalWrite(6,LOW);


}
  
   
if(az<130)
    { Serial.println("There is a throw");
     Serial.print("Z axis:  ");Serial.println(az);
     digitalWrite(5,HIGH);// DETECTING A THROW
    }
     
    delay(100);
}




