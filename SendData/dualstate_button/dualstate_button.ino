#include "Nextion.h"

//Dual State Button
NexDSButton bt0 = NexDSButton(3 , 3 , "bt0");

//Checkbox
NexCheckbox c0 = NexCheckbox(3 , 4 , "c0");

//Radio Check
NexRadio r0 = NexRadio(3 , 5 , "r0");

NexTouch *components[] = {
  &bt0,
  &c0,
  &r0,
  NULL
};


void setup() {
  nexInit();
  
  dbSerial.println("Debug OK");
  bt0.attachPush( push_bt0, &bt0 );
  
}

void loop() {

  nexLoop( components );
}

void push_bt0(void *ptr) 
{  
  uint32_t dual_state;
  dbSerial.print("Push ");
  bt0.getValue(&dual_state);
  if(dual_state) {
      dbSerial.println("HI! OPEN STATE");
  }else{
      dbSerial.println("HI! OFF STATE");
  }
}  



