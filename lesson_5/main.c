//Normally I should use the tm4c123g header but i can't find  it
#include "TexasInstruments/lm4f120h5qr.h"


#define LED_RED (1U << 1)
#define LED_BLEU (1U << 2)
#define LED_GREEN (1U << 3)


void delay(){for (int i=0; i<1000000;i++);}

int main(){
  //Clock gating
  SYSCTL_RCGCGPIO_R |= (1U<<5);
  //setting direction to output
  GPIO_PORTF_DIR_R |= (LED_BLEU|LED_GREEN|LED_RED);
  //setting digital enable to output
  GPIO_PORTF_DEN_R |= (LED_BLEU|LED_GREEN|LED_RED);
  
  GPIO_PORTF_DATA_R |= LED_BLEU;
  while (1){
 
    GPIO_PORTF_DATA_R |= LED_RED;
    delay();
    GPIO_PORTF_DATA_R &= ~LED_RED;
    delay();
    
  }
    
    
  return 0;
}
