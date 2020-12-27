//Example for PIC18F25K80 in CCS C 
//samples array in redalert.h

#include <18F25k80.h> 
#fuses INTRC_IO, NOPROTECT, PUT, BROWNOUT, NOWDT
#use delay(clock=8000000) 

#define T2_FREQ   (8000)      // 8000Hz to 11025Hz
#define K_TMR2    (8000000/4)/(T2_FREQ) 

#include "redalert.h"


void play() 
{ 
   int16 i; 
   for(i=0; i<7794; i++) 
   { 
      set_pwm2_duty(redalert[i]);   
      delay_us(45);
   } 
} 

void main(void) 
{
setup_timer_2(T2_DIV_BY_1, K_TMR2, 1);  
setup_ccp2(CCP_PWM); 
set_pwm2_duty(0L);
while(1) 
  {   
      play();
      
      set_pwm2_duty(0L);
      delay_ms(1000);
             
  } 

}
