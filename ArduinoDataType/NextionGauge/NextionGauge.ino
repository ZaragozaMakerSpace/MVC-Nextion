#include "Nextion.h"

NexGauge z0 = NexGauge(2 , 3 , "z0");

int old_value ;
int threshold = 5;

void setup() {
  nexInit();

  dbSerial.println("Debug OK");
  
}

void loop() {

  int n = analogRead(A0);
  n = map(n,0,1023,0,180);
  
  if ( abs(old_value - n) > threshold){
    old_value = n;
    z0.setValue( old_value ) ;
  }
}
