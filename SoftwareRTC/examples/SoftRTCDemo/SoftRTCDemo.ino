#include <softRtc.h>

SoftRTC myTimer;


// Interrupt Service Routine (ISR) for Timer
ISR(TIMER_ISR_VECTOR_ADDRESS)
{
myTimer.calcTime();
}


void setup()
{
  myTimer.setTime(0,0,0);
  myTimer.startTimer();
  Serial.begin(9600);
}

void loop()
{
  if(myTimer.checkFlag())
  {
    myTimer.clearFlag();
    Serial.println(myTimer.getTime(1));
  }
}
