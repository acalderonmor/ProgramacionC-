#include <18f452.h>
#use delay(clock=4000000)
#fuses xt,noprotect,nowdt
#byte trisa=0x85
#byte porta=0x05
#byte trisB=0x86
#byte portB=0x06
#byte trisD=0x88
#byte portD=0x08
int conteo=0;
LONG  X=5100,DATA1,DATA2;


void main (){
inicio:
if (input_state(pin_a0)==1) {  goto tiempo;}
else
goto inicio;


tiempo:



  OUTPUT_LOW (PIN_D2);
  delay_Us(4000);
    OUTPUT_HIGH(PIN_D2);
   delay_Us(1100);
    goto inicio;


}
