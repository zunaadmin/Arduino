#include <pcf8591.h>

#define PCF8591_ADDRESS_VAL 0x90
#define baudRate            9600

pcf8591 myPcf8591;

void setup(void)
{
  myPcf8591.begin(PCF8591_ADDRESS_VAL);
  Serial.begin(baudRate);
}

void loop(void)
{
  Serial.print(myPcf8591.analogRead(0));
  Serial.write(9);
  Serial.print(myPcf8591.analogRead(1));
  Serial.write(9);
  Serial.print(myPcf8591.analogRead(2));
  Serial.write(9);
  Serial.print(myPcf8591.analogRead(3));
  Serial.write(9);
}


