
int old_value ;
int threshold = 5;

void setup() {
  Serial.begin(9600);
}

void loop() {
  
    int n = analogRead(A0);
    n = map(n,0,1023,0,180);

    if ( abs(old_value - n) > threshold){
      old_value = n;

      Serial.print("z0.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
      Serial.print(  n  );  // This is the value you want to send to that object and atribute mentioned before.
      Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
      Serial.write(0xff);
      Serial.write(0xff);
    }
}

