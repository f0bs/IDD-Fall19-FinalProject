#include "DHT.h"

#define DHTPIN 3     // Digital pin connected to the DHT sensor
// Feather HUZZAH ESP8266 note: use pins 3, 4, 5, 12, 13 or 14 --
// Pin 15 can work but DHT must be disconnected during program upload.

// Uncomment whatever type you're using!
//#define DHTTYPE DHT11   // DHT 11
//
//DHT dht(DHTPIN, DHTTYPE);

const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor

const int pingPin2 = 5; // Trigger Pin of Ultrasonic Sensor
const int echoPin2 = 4; // Echo Pin of Ultrasonic Sensor

long duration;

long prev_cm = 0, prev_cm2 = 0;

int counter = 0;

char inChar;  // character we will use for messages from the RPi

void setup() 
{
   Serial.begin(9600);
   pinMode(pingPin, OUTPUT);
   pinMode(echoPin, INPUT);

   pinMode(pingPin2, OUTPUT);
   pinMode(echoPin2, INPUT);

}

void loop() 
{
//   if(Serial.available()) 
//   {
//     inChar = (char)Serial.read();
//     Serial.print(inChar);
//   }
//
//   // if we get a 'H', turn the LED on, else turn it off
//   if(inChar == 'H')
//   {
//     void getDHT();
//   }
//   else if (inChar == 'L')
//   {
//     long inches, cm, inches2, cm2;
//
//     get_batsignal(pingPin, echoPin);
//     inches = microsecondsToInches(duration);
//     cm = microsecondsToCentimeters(duration);
//
//     get_batsignal(pingPin2, echoPin2);
//     inches2 = microsecondsToInches(duration);
//     cm2 = microsecondsToCentimeters(duration);
//
//
//     if (cm < prev_cm - 20)
//     {
//     while(!(cm2 < prev_cm2 - 20))
//     {
//       get_batsignal(pingPin, echoPin);
//       inches = microsecondsToInches(duration);
//       cm = microsecondsToCentimeters(duration);
//
//       get_batsignal(pingPin2, echoPin2);
//       inches2 = microsecondsToInches(duration);
//       cm2 = microsecondsToCentimeters(duration);
//
////      prev_cm = cm;
////      prev_cm2 = cm2;
//     }
//     if(cm2 < prev_cm2 - 20)
//     {
//       counter = counter - 1;
//     }
//     }
//
//     if (cm2 < prev_cm2 - 20)
//     {
//      while(!(cm < prev_cm - 20))
//     {
//       get_batsignal(pingPin, echoPin);
//       inches = microsecondsToInches(duration);
//       cm = microsecondsToCentimeters(duration);
//
//       get_batsignal(pingPin2, echoPin2);
//       inches2 = microsecondsToInches(duration);
//       cm2 = microsecondsToCentimeters(duration);
//
////      prev_cm = cm;
////      prev_cm2 = cm2;
//     }
//     if(cm < prev_cm - 20)
//     {
//       counter = counter + 1;
//     }
//     }
//
//     prev_cm = cm;
//     prev_cm2 = cm2;
//
//     Serial.print("Forward UltSonic:     ");
//     Serial.print(inches);
//     Serial.print("in, ");
//     Serial.print(cm);
//     Serial.print("cm");
//     Serial.println();
//
//     Serial.print("Backwards UltSonic:   ");
//     Serial.print(inches2);
//     Serial.print("in, ");
//     Serial.print(cm2);
//     Serial.print("cm");
//     Serial.println();
//
//     Serial.print("Counter:              ");
//     Serial.print(counter);
//     Serial.print(" people");
//     Serial.println();
//     delay(1000);
//   }
   long inches, cm, inches2, cm2;

   get_batsignal(pingPin, echoPin);
   inches = microsecondsToInches(duration);
   cm = microsecondsToCentimeters(duration);
   

   get_batsignal(pingPin2, echoPin2);
   inches2 = microsecondsToInches(duration);
   cm2 = microsecondsToCentimeters(duration);
   

   if (cm < prev_cm - 20)
   {
        while(!(cm2 < (prev_cm2 - 20)))
        {

    
              Serial.print("Previous measure before: ");
              Serial.println(prev_cm2);
    
              
              get_batsignal(pingPin2, echoPin2);
              inches2 = microsecondsToInches(duration);
              cm2 = microsecondsToCentimeters(duration);
        
              Serial.print("Backwards UltSonic In Loop:   ");
              Serial.print(inches2);
              Serial.print("in, ");
              Serial.print(cm2);
              Serial.print("cm");
              Serial.println();
              delay(1000);
    
              Serial.print("Previous measure after: ");
              Serial.println(prev_cm2);
        }

        Serial.println("Exited the While LOOOOOP");
        
        counter = counter - 1;

  }
  else if (cm2 < prev_cm2 - 20)
  {
     while(!(cm < prev_cm - 20))
     {
       get_batsignal(pingPin, echoPin);
       inches = microsecondsToInches(duration);
       cm = microsecondsToCentimeters(duration);

       Serial.print("Forward UltSonic In Loop:     ");
       Serial.print(inches);
       Serial.print("in, ");
       Serial.print(cm);
       Serial.print("cm");
       Serial.println();
       delay(1000);


     }
     counter = counter + 1;

   }

   prev_cm = cm;
   prev_cm2 = cm2;


   
   Serial.print("Forward UltSonic:     ");
   Serial.print(inches);
   Serial.print("in, ");
   Serial.print(cm);
   Serial.print("cm");
   Serial.println();

   Serial.print("Backwards UltSonic:   ");
   Serial.print(inches2);
   Serial.print("in, ");
   Serial.print(cm2);
   Serial.print("cm");
   Serial.println();

   Serial.print("Counter:              ");
   Serial.print(counter);
   Serial.print(" people");
   Serial.println();
   delay(2000);
}

long microsecondsToInches(long microseconds) 
{
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) 
{
   return microseconds / 29 / 2;
}


void get_batsignal(int trigPin, int echoPin)
{
   digitalWrite(trigPin, LOW);
   delayMicroseconds(2);
   digitalWrite(trigPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
}

//void getDHT()
//{
//  // Wait a few seconds between measurements.
//  delay(1000);
//
//  // Reading temperature or humidity takes about 250 milliseconds!
//  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
//  float h = dht.readHumidity();
//  // Read temperature as Celsius (the default)
//  float t = dht.readTemperature();
//  // Read temperature as Fahrenheit (isFahrenheit = true)
//  float f = dht.readTemperature(true);
//
//  // Check if any reads failed and exit early (to try again).
//  if (isnan(h) || isnan(t) || isnan(f)) {
//    Serial.println(F("Failed to read from DHT sensor!"));
//    return;
//  }
//
//  // Compute heat index in Fahrenheit (the default)
//  float hif = dht.computeHeatIndex(f, h);
//  // Compute heat index in Celsius (isFahreheit = false)
//  float hic = dht.computeHeatIndex(t, h, false);
//
//  Serial.print(F("Humidity: "));
//  Serial.print(h);
//  Serial.print(F("%  Temperature: "));
//  Serial.print(t);
//  Serial.print(F("°C "));
//  Serial.print(f);
//  Serial.print(F("°F  Heat index: "));
//  Serial.print(hic);
//  Serial.print(F("°C "));
//  Serial.print(hif);
//  Serial.println(F("°F"));
//}
