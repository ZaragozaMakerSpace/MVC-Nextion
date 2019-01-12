

int pot;

void setup() {
  Serial.begin(115200);
  pinMode( A0, INPUT);

}

void loop() {
  pot = (int)(( map (analogRead(A0),0,1023,0,180  ) ));
  Serial.print( "z0.val=");
  Serial.print( pot);
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.write(0xff);
}


