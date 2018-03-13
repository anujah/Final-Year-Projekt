int FLEXSENSORPIN0 =A0 ;
int FLEXSENSORPIN1 =A1 ;
int FLEXSENSORPIN2 =A2 ;
int FLEXSENSORPIN3 =A3 ;

//WILL HAVE TO CHANGE ONCE ON GLOVE AS PINS WILL LIKELY CHANGE
 //the three pins of the first analog LED in the order of red, green, blue
                                //These pins must be PWM

//defined variables for each sensor according to finger

float ringReading;
float middleReading;
float indexReading;
float thumbReading;
 void setup()
 {
Serial.begin(9600);

}
 
void loop(void) {
 
  ringReading = analogRead(FLEXSENSORPIN0);
  float flexV0 =  ringReading * 5.0 / 1024.0;
  middleReading = analogRead(FLEXSENSORPIN1);
   float flexV1 =  middleReading * 5.0 / 1024.0;
  indexReading = analogRead(FLEXSENSORPIN2);
   float flexV2 =  indexReading * 5.0 / 1024.0;
  thumbReading = analogRead(FLEXSENSORPIN3);
   float flexV3 =  thumbReading * 5.0 / 1024.0;
  
  

  Serial.print("Single reading Ring "); 
  Serial.println(ringReading);
  Serial.println(flexV0);
  
  Serial.print("Single reading Middle "); 
  Serial.println(middleReading);
  Serial.println(flexV1);

  Serial.print("Single reading Index "); 
  Serial.println(indexReading);
  Serial.println(flexV2);

  Serial.print("Single reading Thumb "); 
  Serial.println(thumbReading);
Serial.println(flexV3);
  /*map 3 readings to be RBG values. The bottom and top values were taken by analyzing multiple readings to determine the best values to use.
  These values will likely be different for everyone so be sure to change them as they suit your project
  can use average() to determine the values as well*/


  delay(3000);
}

/**
 * gets a reading from an analog pin
 * @param pin the pin to read from
 * @return the reading
 */
float singleReading(int pin)
{
  float reading;
  reading = analogRead(pin);
  return reading;
}

/**
 * maps an analog reading to a value between 0-254, 254 used for demonstration purposes to show that values were 
 * being read and manipulated at all times. bottom and top values used are the average values when the sensor is bent (bottom)
 * and when it is held straight (top)
 * @param analogReading reading to be mapped
 * @param bottom the value used as the minimum value for the sensor
 * @param top the value used as the maximum value for the sensor
 * @return mapped value to be used for the RGB light
 */
/*float mapReading(float analogReading, float bottom, float top)
{
  float calibratedValue;
  if(analogReading > top)
  {
    calibratedValue = 254;
  }
  else if(analogReading < bottom)
  {
    calibratedValue = 0;
  }
  else
  {
    calibratedValue = map(analogReading, bottom,top,0,254); 
  }
  return calibratedValue;
}*/

/**
 * sets the values for the RBG LED
 * @param red the value for the red light 0-255
 * @param green the value for the green light 0-255
 * @param blue the value for the blue light 0-255
 */
/*void setLED(float red, float green, float blue)
{
   Serial.println("");
   Serial.print("Red: ");
   Serial.println(red);
   Serial.print("Green: ");
   Serial.println(green);
   Serial.print("Blue: ");
   Serial.println(blue);
   Serial.println("");
   analogWrite(ledAnalogOne[0], red);
   analogWrite(ledAnalogOne[1], green);
   analogWrite(ledAnalogOne[2], blue);
}*/

/**
 * gets and print the average values taken from the sensor as per the NUMSAMPLES variable
 */
void average()
{
  int NUMSAMPLES = 100;
  uint8_t i;
  float average;
  int samples[NUMSAMPLES];
  
    // take N samples in a row, with a slight delay
  for (i=0; i< NUMSAMPLES; i++) {
    //Change the pin according to which sensor you are calibrating
   samples[i] = analogRead(FLEXSENSORPIN0);
   delay(10);
  }

  // average all the samples out
  average = 0;
  for (i=0; i< NUMSAMPLES; i++) {
     average += samples[i];
  }
  average /= NUMSAMPLES;
 
  Serial.print("Average reading "); 
  Serial.println(average);
}
