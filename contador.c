#include <18f452.h>
#use delay(clock=4000000)
#fuses xt,noprotect,nowdt
#byte trisa=0x85
#byte porta=0x05

int conteo=0;


void main (){
    
inicio:

if (input_state(pin_a0)==1) {delay_ms(500); conteo++;goto imprime;}
else

if (input_state(pin_a1)==1) {delay_ms(500);conteo--;goto imprime;}
else

if (input_state(pin_a2)==1) {delay_ms(500);conteo=0;goto imprime;}
else

if (input_state(pin_a3)==1) {delay_ms(500);conteo=255;goto imprime;}
else

imprime:
output_d(conteo);
output_c(conteo);
goto inicio; 
  

 
}


