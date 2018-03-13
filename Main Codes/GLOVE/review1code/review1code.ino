  int flex0=0;
  int flex1=1;
  int flex2=2;
  int flex3=3;

  int ledpin[]={9,3,6};
  int thumb;
  int ring;
  int nndexfinger;
  int middle;

void setup() {
Serial.begin(9600);
for(int i =0;i<3;i++)
{pinMode(ledpin[i],OUTPUT);
  }

}

void loop(void) {
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

delay(10000);

}

float singlereading(int pin)
{ float reading;
reading = analogRead(pin);
return reading; 
  
  
  }
