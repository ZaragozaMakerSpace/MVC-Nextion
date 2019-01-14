#include "Nextion.h"

//Standard Button
NexButton b0 = NexButton(3 , 1 , "b0");
NexButton b1 = NexButton(3 , 2 , "b1");

NexTouch *components[] = {
  &b0,
  &b1,
  NULL
};

void setup() {
  nexInit();
  
  dbSerial.println("Debug OK");
  b0.attachPush( pushCallback, &b0 );
  b1.attachPop( popCallback, &b1 );
  
}

void loop() {

  nexLoop( components );
}

void pushCallback(void *ptr)  
{  
  dbSerial.println("Push ");
}  

void popCallback(void *ptr)  
{  
  dbSerial.println("Pop ");
} 

