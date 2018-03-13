/******************************************************************************
Flex_Sensor_Example.ino
Example sketch for SparkFun's flex sensors
  (https://www.sparkfun.com/products/10264)
Jim Lindblom @ SparkFun Electronics
April 28, 2016

Create a voltage divider circuit combining a flex sensor with a 47k resistor.
- The resistor should connect from A0 to GND.
- The flex sensor should connect from A0 to 3.3V
As the resistance of the flex sensor increases (meaning it's being bent), the
voltage at A0 should decrease.

Development environment specifics:
Arduino 1.6.7
******************************************************************************/
const int FLEX_PIN1 = A0; // Pin connected to voltage divider output
const int FLEX_PIN2 = A1;
// Measure the voltage at 5V and the actual resistance of your
// 47k resistor, and enter them below:
const float VCC = 4.98; // Measured voltage of Ardunio 5V line
const float R_DIV = 10000.0; // Measured resistance of 3.3k resistor

// Upload the code, then try to adjust these values to more
// accurately calculate bend degree.
const float STRAIGHT_RESISTANCE1 = 8000.0; // resistance when straight
const float BEND_RESISTANCE1 = 15000.0; // resistance at 90 deg
const float STRAIGHT_RESISTANCE2 = 8000.0; // resistance when straight
const float BEND_RESISTANCE2 = 15000.0; // resistance at 90 deg
void setup() 
{
  Serial.begin(9600);
  pinMode(FLEX_PIN1, INPUT);
  pinMode(FLEX_PIN2,INPUT);
}

void loop() 
{
  // Read the ADC, and calculate voltage and resistance from it
  int flexADC1 = analogRead(FLEX_PIN1);
  int flexADC2 = analogRead(FLEX_PIN2);
  float flexV1 = flexADC1 * VCC / 1023.0;
  float flexV2 = flexADC2 * VCC / 1023.0;
  
  float flexR1 = R_DIV * (VCC / flexV1 - 1.0);
   float flexR2 = R_DIV * (VCC / flexV2 - 1.0);
  Serial.println("Resistance: " + String(flexR1) + " ohms");
Serial.println("Resistance: " + String(flexR2) + " ohms");
  // Use the calculated resistance to estimate the sensor's
  // bend angle:
  float angle1 = map(flexR1, STRAIGHT_RESISTANCE1, BEND_RESISTANCE1,
                   0, 90.0);
  float angle2 = map(flexR2, STRAIGHT_RESISTANCE2, BEND_RESISTANCE2,
                   0, 90.0);
  Serial.println("Bend: " + String(angle1) + " degrees");
  Serial.println("Bend: " + String(angle2) + " degrees");
  Serial.println();

  delay(1000);
}

