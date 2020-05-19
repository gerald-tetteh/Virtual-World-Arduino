/*
  Author: Gerald Addo-Tetteh
  This program calculates the distance from
  the ultrasonic sensor to an object.
*/

//intializing pins
int echo_pin = 3;
int trig_pin = 2;
float ping_time;
float distance;
float sound_speed = 343.;//meters per second

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trig_pin,OUTPUT);
  pinMode(echo_pin,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  //creates ping to determine distance
  digitalWrite(trig_pin,LOW);
  delayMicroseconds(2000);
  digitalWrite(trig_pin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin,LOW);
  delayMicroseconds(10);

  //calculates the distance
  ping_time = pulseIn(echo_pin,HIGH);
  ping_time = ping_time * (1./1000000.);
  distance = ((sound_speed * ping_time) /2.0) * 39.37;

  //prins to serial monitor
  Serial.println(distance);
  delay(200);
}
