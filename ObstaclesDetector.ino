/* 
@Author Abdullah Bamufleh
project name: Obstacles Detector
Description:
This project simulate the Obstacles Detector exactly that
one exist in now days cars.
last update: 2024-01-19
 */

const int buzzer  = 6; // buzzer pin number
const int trigPin = 9; // triger pin number
const int echoPin = 10; // echo pin number
const int led     = 2;  // led pin number
float distance; // define distance variable
int duration;   // define duration variable

void setup() {
  pinMode(trigPin, OUTPUT); //
  pinMode(echoPin, INPUT);    //
  pinMode(2,OUTPUT);             // assign as input or output pins
  pinMode(buzzer, OUTPUT);   //                      
  Serial.begin(9600);      //
}

void loop() {
      ObstaclesDetector();
}

// This method givs alarm of an obstacles
    void sins(int buzzer, int latency){
     tone(buzzer,1500);
      digitalWrite(led,HIGH);
       delay(latency);
        digitalWrite(led,LOW);
     }          


     // This method calculate the distance
     void CalculateDistance(){
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);

      duration = pulseIn(echoPin, HIGH);
      distance = (duration*.0343)/2;
      Serial.print("Distance: ");
      Serial.println(distance); 
      delay(500);
     } 


     // This is the whole system
     void ObstaclesDetector(){
      CalculateDistance();
      if(distance > 8 && distance < 10){
        sins(buzzer,700);
        noTone(buzzer);
     }else if(distance > 4 && distance < 8){
        sins(buzzer,300);
        noTone(buzzer);
     }else if(distance <= 4 && distance >= 0){
        tone(buzzer,1500);
        digitalWrite(led,HIGH);
     }else{
      noTone(buzzer);
      digitalWrite(led,LOW);
     }

     }
     