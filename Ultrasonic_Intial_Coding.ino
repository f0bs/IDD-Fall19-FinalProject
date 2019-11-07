
// defines pins numbers
const int trigPin1 = 7;
const int echoPin1 = 6;
const int trigPin2 = 9;
const int echoPin2 = 8;

// defines variables
long duration;
int distance;
int prev_distance;
int counter = 0;

void setup() {
pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin1, INPUT); // Sets the echoPin as an Input
pinMode(trigPin2, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin2, INPUT); // Sets the echoPin as an Input

Serial.begin(9600); // Starts the serial communication
}

void loop() {
// Clears the trigPin
digitalWrite(trigPin1, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin1, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin1, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin1, HIGH);

// Calculating the distance
distance = duration*0.034/2;


if (distance < prev_distance)
{
  counter = counter + 1;
}

prev_dist = distance;

// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
}
