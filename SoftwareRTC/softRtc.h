#ifndef __timer_h__
#define __timer_h__

#include <avr/io.h>
#include <avr/interrupts.h>
#include <stdio.h>

/*#define 24HOUR_MODE 0
#define 12HOUR_MODE 1*/

#define TIMER_ISR_VECTOR_ADDRESS TIMER1_OVF_vect
#define TIMER_MASK_REGISTER      TIMSK1
#define TIMER_CONTROL_A          TCCR1A 
#define TIMER_CONTROL_B          TCCR1B
#define TIMER_COUNTER_REGISTER   TCNT1

#define TIMER_CONTROL_A_VAL      0x00
#define TIMER_CONTROL_B_VAL      (1 << CS10)|(1 << CS12)

#define TIMER_MASK_SET           (1 << TOIE1)
#define TIMER_MASK_CLR           ~(1 << TOIE1)

#define TIMER_RELOAD_VALUE       49990

//#define ISR_BLOCK ISR(TIMER_ISR_VECTOR_ADDRESS) { tickStatus = true; this->SS++;if(this->SS == 60){this->SS = 0;this->MM++;if(this->MM == 60){this->MM = 0;this->HH++;if(this->HH == 24){ths->HH = 0;}}}TIMER_COUNTER_REGISTER = TIMER_RELOAD_VALUE; }

class SoftRTC
{
public:
 volatile unsigned char SS;
 volatile unsigned char MM;
 volatile unsigned char HH;
 volatile bool         tickStatus;
 void                  setTime(unsigned char ss,unsigned char mm,unsigned char hh);
 void                  begin(void);
 void                  startTimer(void);
 void                  stopTimer(void);
 void                  clearTimer(void);
 void                  clearFlag(void);
 bool                  checkFlag(void);
 void                  calcTime(void);
 char*                 getTime(unsigned char _mode); // _mode : 0 (24 hr -> hh:mm:ss) , _mode : 1 (12 hr -> hh:mm:ss:AM/PM)
};



#endif