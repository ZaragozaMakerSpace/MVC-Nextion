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
  c0.attachPush( push_c0, &c0 );
  r0.attachPush( push_r0, &r0 );
}

void loop() {

  nexLoop( components );
}

void push_bt0(void *ptr) {  
  uint32_t dual_state;
  dbSerial.print("Push ");
  bt0.getValue(&dual_state);
  if(dual_state) {
      dbSerial.println("DUAL STATE ON");
  }else{
      dbSerial.println("DUAL STATE OFF");
  }
}  

void push_c0(void *ptr) {  
  uint32_t dual_state;
  dbSerial.print("Push ");
  c0.getValue(&dual_state);
  if(dual_state) {
      dbSerial.println("CHECKBOX ON");
  }else{
      dbSerial.println("CHECKBOX OFF");
  }
}  


void push_r0(void *ptr) {  
  uint32_t dual_state;
  dbSerial.print("Push ");
  r0.getValue(&dual_state);
  if(dual_state) {
      dbSerial.println("RADIO CHECKBOX ON");
  }else{
      dbSerial.println("RADIO CHECKBOX OFF");
  }
}  



