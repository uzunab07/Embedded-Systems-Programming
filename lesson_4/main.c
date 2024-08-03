//defining the macro to turn on PORT F
#define RCGCGPIO        (*(unsigned     int     *)0x400fe608U) //clock gatting control 
#define GPIOF_BASE      0x40025000U
#define GPIOF_DIR       (*((unsigned    int     *)(GPIOF_BASE    +       0x400U)))
#define GPIO_DEN        (*((unsigned    int     *)(GPIOF_BASE    +       0x51CU)))
#define GPIO_DATA       (*((unsigned    int     *)(GPIOF_BASE    +       0x3FCU)))

void delay(){
  for (int i=0;i<1000000;i++);
}
int main(){
  //turn on port f
  RCGCGPIO = 0x20U;
  
  //set direction to output
  GPIOF_DIR = 0x0EU;
  
  //Set the pin to be DEN Digital Enable
  
  GPIO_DEN = 0x0EU;
  
  while(1){
      //turn just the red led
    //0010-> 0x2U => RED
    GPIO_DATA = 0x2U;
    delay();
    GPIO_DATA = 0x0U;
    delay();
    
  }
  
  return 0;
}
