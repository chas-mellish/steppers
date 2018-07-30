const int step_pin = 5; 
const int direction_pin = 4;
int delay_time = 500;               // minimum ~50 = fastest

void setup() {
  pinMode(step_pin,OUTPUT);         // set up outputs
  pinMode(direction_pin,OUTPUT);
}
void loop() {
  digitalWrite(direction_pin,HIGH); // rotate one way
  for(int x = 0; x < 3200; x++) {   // 3200 = 1 full rotation
    digitalWrite(step_pin, HIGH); 
    delayMicroseconds(delay_time);  // pause between steps
    digitalWrite(step_pin, LOW); 
    delayMicroseconds(delay_time); 
  }
  delay(500);                       // wait 500 ms
  
  digitalWrite(direction_pin,LOW);  // rotate the other way
  for(int x = 0; x < 3200; x++) {
    digitalWrite(step_pin, HIGH);
    delayMicroseconds(delay_time);  
    digitalWrite(step_pin, LOW);
    delayMicroseconds(delay_time);
  }
  delay(500);
}
