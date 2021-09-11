#include <18f452.h>
#use delay(clock=4000000)
#fuses xt,noprotect,nowdt
#byte trisa=0x85
#byte porta=0x05
#byte trisb=0x86
#byte portb=0x06

int conteo=0;
void main (){
    
inicio:

if (input_state(pin_d0)==1) {conteo=0;delay_ms(500);;goto sierra;}
else

if (input_state(pin_d1)==1) {conteo=0;delay_ms(500);goto triangulo;}
else
conteo=0;
output_b(conteo);

goto inicio;

sierra:
conteo ++;
output_b(conteo);
delay_us(60);
if (input_state(pin_d0)==0) {;goto inicio;}
else
goto sierra;

triangulo:

conteo++;
delay_us(60);
output_b(conteo);
if (conteo== 255) {goto desendente;}
else
if (input_state(pin_d1)==0) {;goto inicio;}
else   
goto triangulo;  

desendente:
conteo--;
delay_us(60);
output_b(conteo);
if(conteo==0) {goto triangulo;}
else
if (input_state(pin_d1)==0) {;goto inicio;}
else

goto desendente;    
}


