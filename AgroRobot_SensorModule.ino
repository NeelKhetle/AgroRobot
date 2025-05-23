
  
  #include<NewPing.h> 

#define TRIGGER_PIN A1        
#define ECHO_PIN A0          
#define MAX_DISTANCE 200  

int sensorPin = A5; // select the input pin for the soil moisture sensor
int sensorValue = 0; 
 
unsigned int distance = 0;
int buzzer = 12;

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  //myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);  
  pinMode(buzzer,OUTPUT);
}

void loop() 
{
  unsigned int i = 0;
  distance = sonar.ping_cm();                       //send ping, get distance in cm and store it in 'distance' variable:
Serial.print("distance");                   
Serial.println(distance);  

if((distance > 1) && (distance < 15)){            
 

      digitalWrite(buzzer,HIGH);
      delay(2);//wait for 2ms
      digitalWrite(buzzer,LOW);
      delay(2);//wait for 2ms
}
    
   sensorValue = analogRead(sensorPin);    
  Serial.print("Moisture: "); // print the moisture value to the serial monitor
Serial.println(sensorValue);
if(sensorValue<=400){
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW); 
    digitalWrite(7, LOW);
  }
  else if ((sensorValue>400) && (sensorValue <=500)){
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);

  }
  else if((sensorValue>500) && (sensorValue <=600)){
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
  }
}