#include "Nextion.h"
#define size 20
NexText t0 = NexText(4 , 3 , "t0");

char buff[size] = {0};

void setup() {
  Serial.begin(9600);
  nexInit();
}

void loop() {
  if ( Serial.available() ){
    String data = Serial.readString();
    dbSerial.println(data);
    //Clean buffer
    memset(buff, 0, sizeof(buff));
    data.toCharArray(buff, data.length()+1 );
    
    t0.setText( buff ); 
  }
}
