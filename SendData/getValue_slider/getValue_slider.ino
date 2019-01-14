#include "Nextion.h"

//Slider
NexSlider h0 = NexSlider(3 , 8 , "h0");

NexTouch *components[] = {
  &h0,
  NULL
};

uint32_t old_value, new_value;

void setup() {
  nexInit();
  
  dbSerial.println("Debug OK");
  h0.attachPush( push_h0, &h0 );
  h0.attachPop( pop_h0, &h0 );

}

void loop() {

  nexLoop( components );
}

void push_h0(void *ptr) {  

  h0.getValue(&old_value);
  dbSerial.print("Old Value: ");dbSerial.println(old_value);
}  

void pop_h0(void *ptr) {  
  h0.getValue(&new_value);
  dbSerial.print("Last Value: ");dbSerial.println(new_value);
  dbSerial.print("Diff: ");dbSerial.println( int(new_value - old_value) );
}  


