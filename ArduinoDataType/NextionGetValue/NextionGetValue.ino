#include "Nextion.h"

NexButton b2 = NexButton(4 , 7 , "b2");
NexNumber n0 = NexNumber(4 , 4 , "n0");

NexTouch *components[] = {
  &b2,
  NULL
};

int32_t  velocity;

void setup() {
  nexInit();

  dbSerial.println("Debug OK");
  b2.attachPush( pushValue, &b2 );
}

void loop() {

  nexLoop( components );
  
}

void pushValue(void *ptr) 
{  
  n0.getValue( &velocity );
  dbSerial.print("Velocity:  ");
  dbSerial.println ( velocity );
}  
