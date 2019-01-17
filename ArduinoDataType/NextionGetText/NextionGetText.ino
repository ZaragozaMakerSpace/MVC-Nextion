#include "Nextion.h"
#define size 7

NexVariable va0 = NexVariable(4 , 8 , "va0");

char buff[size] = {0};

void setup() {
  Serial.begin(9600);
  nexInit();
}

void loop() {
  if ( Serial.available() ){
    String data = Serial.readString();

    //Clean buffer
    memset(buff, 0, sizeof(buff));

    va0.getText( buff, size ); 
    
    dbSerial.println( buff );
    dbSerial.println( data );
    if(  String(buff) == data ){
      dbSerial.println("Get Text OK");
    }else{
      dbSerial.println("Text no OK");
    }
  }
}
