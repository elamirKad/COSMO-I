#include <dht.h>

dht DHT;

#define outputA 6
#define outputB 5


#define DHT11_PIN 7 //temp and humidity
int sensorPin = A0; //light sense
#define  INTERVAL  1200UL           // интервал между включение/выключением светодиода (1 секунда)
const int trigPin = 9;
const int echoPin = 10;
long duration;
int distance;
int sensorValue;
int aLastState;
int aState;
int counter = 0; 

const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = 1; // analog pin connected to X output
const int Y_pin = 2; // analog pin connected to Y output

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  pinMode (outputA,INPUT);
  pinMode (outputB,INPUT);
  Serial.begin(9600);
  aLastState = digitalRead(outputA);
}

void loop() {
  aState = digitalRead(outputA);
  // put your main code here, to run repeatedly:

  
  static unsigned long previousMillis = 0;        // храним время последнего переключения светодиода

  
    if(millis() - previousMillis > INTERVAL) {
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      duration = pulseIn(echoPin, HIGH);
      distance= duration*0.034/2;
      Serial.println(distance);
      
      previousMillis = millis(); 
      int chk = DHT.read11(DHT11_PIN);
      Serial.print(DHT.temperature);
      Serial.println(" C");
      Serial.println(DHT.humidity);
      
      sensorValue = analogRead(sensorPin);
      Serial.println(sensorValue);

      Serial.println(digitalRead(SW_pin));


      
      if(analogRead(X_pin) > 500 and analogRead(X_pin) < 600 and analogRead(Y_pin) > 450 and analogRead(Y_pin) < 550){
        //center
        Serial.println("5");
      }else if(analogRead(X_pin) < 100){
        //top
        Serial.println("8");
      }else if(analogRead(X_pin) > 900){
        //Bottom
        Serial.println("2");
      }else if(analogRead(Y_pin) < 100){
        //right
        Serial.println("6");
      }
      else if(analogRead(Y_pin) > 900){
        //left
        Serial.println("4");
      }else{
        Serial.println("0");
      }

      Serial.println(counter);
      
    }



    if (aState != aLastState){
      if (digitalRead(outputB) != aState) { 
       counter ++;
      } else {
       counter --;
      }
      aLastState = aState;
    }

}
