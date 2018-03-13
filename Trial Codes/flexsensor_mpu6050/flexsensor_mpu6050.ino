int flex_pin[4] = {0, 1, 2, 3};

const float VCC = 4.98; // Measured voltage of Ardunio 5V line
const float R_DIV = 10000.0; // Measured resistance of 10k resistor

float straight_resistance[4] = {5000.0, 3900.0, 5000.0, 10900.0}; // resistance when flex are straight
float bend_resistance[4] = {7600.0, 4600.0, 7000.0, 12300.0}; // resistance at 90 deg

float read_angle(int);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int ang[4]; 
  int i;


  for (i = 0; i < 4; i++)
  {
    ang[i] = read_angle(flex_pin[i]);
    Serial.println("Bend: " + String(ang[i]) + " degrees");
    Serial.println();
  }


  delay(50000);
}

float read_angle(int analog_pin)
{
  int flexADC = analogRead(analog_pin);
  Serial.println(flexADC);
  float flexV = flexADC * VCC / 1024.0;
  
  float flexR = R_DIV * (VCC / flexV - 1.0);
  
  Serial.println("Resistance: " + String(flexR) + " ohms");
  float angle = map(flexR,straight_resistance[analog_pin],bend_resistance[analog_pin], 0, 90.0);

  return angle;
}

