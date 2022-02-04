#include <stdio.h>
#include <wiringPi.h>
#define MOIST 7 //GPIO 4 pin 7 maps to WiringPi pin number 7
int main (void)
{
  printf ("Testing raspberry pi moisture sensor\n") ;
  wiringPiSetup(); 
pinMode(MOIST, INPUT);
for(;;)
{
    if (digitalRead(MOIST))
        printf("moisture threshold not reached\n"); 
    else
        printf("moisture threshold reached \n");
    delay(2000);
}
  return 0 ;
}