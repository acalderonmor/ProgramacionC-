#include <18f452.h>
#device ADC = 10
#fuses XT,NOWDT
#use delay(clock = 4000000)
#byte trisc=0x87
#byte portc=0x07


void main (){

int16 voltaje;
float visualizacion, out; 



int16 voltaje1;
float visualizacion1, out1; 

    
inicio:

setup_adc_ports(AN0);   

setup_adc(ADC_CLOCK_INTERNAL);
set_adc_channel(0);
delay_us(50);

voltaje = read_adc();
visualizacion=(5.0*voltaje)/1023.0;
out= visualizacion;



set_adc_channel(1);
delay_us(50);
voltaje1 = read_adc();
visualizacion1=(5.0*voltaje1)/1023.0;
out1= visualizacion1;




if (out1>4) { OUTPUT_high(PIN_C1); OUTPUT_low(PIN_C4); OUTPUT_low(PIN_C7); OUTPUT_low(PIN_C2);goto sigue;}
else

if (out1>2) { OUTPUT_high(PIN_C4); OUTPUT_low(PIN_C1); OUTPUT_low(PIN_C7);OUTPUT_low(PIN_C2);goto sigue;}
else


if (out1<2) { OUTPUT_high(PIN_C7); OUTPUT_low(PIN_C4); OUTPUT_low(PIN_C1);OUTPUT_low(PIN_C2);goto sigue;}
else

sigue:



if (out>4) { OUTPUT_high(PIN_C5); OUTPUT_low(PIN_C4); OUTPUT_low(PIN_C3);OUTPUT_low(PIN_C2);goto inicio;}
else

if (out>2) { OUTPUT_high(PIN_C4); OUTPUT_low(PIN_C3); OUTPUT_low(PIN_C5);OUTPUT_low(PIN_C2);goto inicio;}
else


if (out<2) { OUTPUT_high(PIN_C3); OUTPUT_low(PIN_C4); OUTPUT_low(PIN_C5);OUTPUT_low(PIN_C2);goto inicio;}
else



goto inicio; 


 
}

