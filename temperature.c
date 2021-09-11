#include <18f452.h>
#device ADC = 10
#fuses XT,NOWDT
#use delay(clock = 4000000)
#DEFINE USE_PORTB_LCD true
#include <lcd.c> 



void main (){
int16 voltaje;
float temp; 


lcd_init();

    
inicio:
setup_adc_ports(AN0_AN1_VSS_VREF);
setup_adc(ADC_CLOCK_INTERNAL);
set_adc_channel(0);
delay_us(50);
voltaje = read_adc();
temp=voltaje/6.8;

output_c(voltaje);

lcd_gotoxy(1,1);
lcd_putc("Adqui. Data ECCI");
lcd_gotoxy(2,2);
printf(LCD_PUTC ,"temp = %g\n\r",temp);
lcd_gotoxy(15,2);
lcd_putc(-33);

delay_ms(200);
goto inicio; 


    
 
}

