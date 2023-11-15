# include<NewPing.h>
# include<Servo.h>
Servo myservo;

# define Trig 2
# define Echo 3
# define Metal A7
# define Wet 4
int maxDistance = 10;
static int distance;
int metal;
int moisture;

NewPing sonar(Trig,Echo,maxDistance);

void METAL()
{
  metal=analogRead(Metal);
// Serial.print(" Metal Raw data: ");
// Serial.println(metal);
 delay(300);
}
void Organic()
{
 moisture=digitalRead(Wet);
// Serial.print("Organic: ");
// Serial.println(moisture);
}


void setup() {
 Serial.begin(9600);
 myservo.attach(5); //Servo Signal Pin Attached to Digital Pin 5.

}

void loop() {
distance=sonar.ping_cm();
pinMode(Wet,INPUT);
Serial.print(" Distance: ");
Serial.println(distance);
delay(300);

if(distance!=0)
{
 Serial.println("Object Detected");
 METAL();
 Organic();
  if(metal<=545&&moisture==HIGH)
  {
    Serial.println("Metal Detected");
    delay(500);
    myservo.write(0);
    delay(20);
  }
  else if(metal>545&&moisture==LOW)
  {
    Serial.println("Organic Detected");
    delay(500);
    myservo.write(70);
  }
  else
  {Serial.println("Plastic Detected");
  delay(500);
  myservo.write(180);
    }
      
  }  
}
