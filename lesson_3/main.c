void delay(){
  for (int i=0;i<1000000;i++);
}
  int main(){
  //Turn on the block of Port-f 
 *((unsigned int *)0x400fe608U)=0x20U;
  unsigned int *PIN_DIR;
  //setting the pin direction to be digital output (all 3 pin LED RGB) BY setting the bits 1,2 and 3 at the address 0x40025000 to 1
  PIN_DIR = (unsigned int *)0x40025400U;
 // *PIN_DIR = *PIN_DIR + 0xeU;
  *PIN_DIR |= 0x0EU;
  //Seeting the function of the pins as digital output (all 3 pin LED RGB) BY setting the bits 1,2 and 3 at the address 0x4002551c to 1
  unsigned int *PIN_FNC; 
  PIN_FNC = (unsigned int *)0x4002551cU;
  *PIN_FNC |= 0x0EU;
  
  //control the led
  
  unsigned int* LED_PIN;
  LED_PIN = (unsigned int *)0x400253fcU;
  

  
  while (1){
    
  
     //RED on/off
     *LED_PIN |= 0x02U;
     delay();
     *LED_PIN = 0x0U;
     delay();
      
      
      //Bleu on/off
    *LED_PIN |= 0x04U;
     delay();
     *LED_PIN = 0x0U;
     delay();
      
     *LED_PIN  |= 0x08U;
     delay();
     *LED_PIN = 0x0U;
     delay();

  }
 
  
  
   
    
  return 0;
}
