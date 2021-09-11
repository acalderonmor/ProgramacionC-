#include <18f452.h>
#device ADC = 10

#use delay(clock = 4000000)
#DEFINE USE_PORTB_LCD true
#include <lcd.c> 



void main (){
int16 voltaje;
float visualizacion, out; 

int16 voltaje1;
float visualizacion1, out1; 


lcd_init();

    
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


output_c(voltaje);
output_d(voltaje1);

lcd_gotoxy(10,1);
printf(LCD_PUTC ,"X= %gv\n\r",out);

lcd_gotoxy(10,2);
printf(LCD_PUTC ,"Y= %gv\n\r",out1);


lcd_gotoxy(2,1);
printf(LCD_PUTC ,"X= %ld",voltaje);
lcd_putc("  ");
lcd_gotoxy(2,2);
printf(LCD_PUTC ,"Y= %ld",voltaje1);
lcd_putc("  ");
delay_ms(200);
goto inicio; 


    
 
}

