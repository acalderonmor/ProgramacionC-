#include <18f452.h>
#device ADC = 10
#fuses XT,NOWDT
#use delay(clock = 4000000)
#use rs232(baud=9600,parity=N,xmit=PIN_C6,rcv=PIN_C7)


CHAR VALOR1,conteo =0, conteo1=0, valor3=00, RECIBIDO;
char duty;
float valor;
int16 voltaje;



void main()
{


          inicio:
  enable_interrupts(int_rda);
          enable_interrupts(global);

if (VALOR1==1) {goto adc_int;}
else
if (VALOR1==2) {goto pwm_salida;;}
else
goto inicio;

adc_int:

 enable_interrupts(int_rda);
          enable_interrupts(global);
          
setup_adc_ports(AN0);   

setup_adc(ADC_CLOCK_INTERNAL);
set_adc_channel(0);
delay_us(50);

voltaje = read_adc();

PUTc(voltaje);
delay_ms(500);



if (VALOR1==100) {goto inicio;}
else

goto adc_int;

pwm_salida:
 enable_interrupts(int_rda);
          enable_interrupts(global);
setup_timer_2(t2_div_by_16,249,1);
setup_ccp1(ccp_pwm);
set_pwm1_duty(VALOR1);
if (VALOR1==100) {goto inicio;}
else
goto pwm_salida;

}



#INT_RDA

void serial_isr()
{
VALOR1=GETC();

PUTc(voltaje);

}
