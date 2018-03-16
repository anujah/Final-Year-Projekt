//FYP-2018 GROUP 46
/* DESCRIPTION
 *  This is the robotic hand part of our project and our goals are;
 *  1)To throw an object into the air and catch it
 *  2)To sense the hardness of the object
 *  3)Mimicking the human hand
 */
int servo[4]= {11,10,9,6};
int pressureSensor = A0;
int pressureVal;
int pot=A1;
int bla;// values that we can enter later
void mimic()
{}
void throwcatch()
{}


void setup() {
  // put your setup code here, to run once;
pinMode(11,OUTPUT);
pinMode(10,OUTPUT);
pinMode(9,OUTPUT);
pinMode(6,OUTPUT);
pinMode(13,OUTPUT);// LED red
pinMode(12,OUTPUT);// LED blue
pinMode(8,OUTPUT);// LED green
}

void loop()
{
 
  /* THE USER NEEDS TO ENTER HIS CHOICE;
   *  1) TO THROW AND CATCH A BALL
   *  2) TO DETECT THE OBJECT
   *  3) TO MIMIC THE HUMAN HAND
   */
if(analogRead(pot)>bla) // enter the value for option 3 that is mimic the hand
 { mimic(); // jump to the function of mimicking the hand
   digitalWrite(13,HIGH);
    digitalWrite(12,LOW);
     digitalWrite(8,LOW);
  
 }
else if(analogRead(pot)<bla && analogRead(pot)>bla) // enter the value for option 2 that is detect an object
 { detect(); // jump to the detection function
 digitalWrite(8,HIGH);
 digitalWrite(12,LOW);
 digitalWrite(13,LOW);
  
 }
 else
 { throwcatch(); // throw an object and catch it i.e option 1
   digitalWrite(12,HIGH);
   digitalWrite(8,LOW);
   digitalWrite(13,LOW);
   
 }
}

void detect()
{ 
  int angle;
  for (angle = 0; angle <= 180; angle += 5) 
  { for(int i=0;i<4;i++) 
   servoPulse(servo[i],angle);  // moving every 4 fingers slowly by 5 degree angle
  
   pressureVal = analogRead(pressureSensor); // reading the pressure values
   if(pressureVal>bla) // checking for the pressurevalues
    { Serial.println("object not detected");
    continue;
    }
    else if(pressureVal>bla && pressureVal<bla)
    { Serial.println("Object under controller pressure");
    continue;
    }
    else
    { Serial.println("NO more pressure can be applied");
    }
    break;
    }
   while(angle>0)  // Releasing the held object
   {
    for(int i=0;i<4;i++) 
    {servoPulse(servo[i],angle);
    }
    angle--;
   }
}
void servoPulse (int servo, int angle)
{ int pwm;
 pwm = (angle*15) + 1000;      // Convert angle to microseconds
 digitalWrite(servo, HIGH);
 delayMicroseconds(pwm);
 digitalWrite(servo, LOW);
 delay(50);                   // Refresh cycle of servo
}

