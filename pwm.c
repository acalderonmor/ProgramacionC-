#include <18f452.h>
#fuses XT,NOWDT
#use delay(clock = 4000000)
#DEFINE USE_PORTB_LCD true
#include <lcd.c> 
#byte trisa=0x85
#byte porta=0x05
#byte trisb=0x86
#byte portb=0x06
#byte trisd=0x88
#byte portd=0x08
int x,duty, dutyinicia=225;
char out,out1;
int contador=0;
float porcentaje=50;

void main (){

while(1)
{
inicio:
x=input_a();
contador=0;
if (input_state(pin_b0)==1) {contador=contador+1;porcentaje=10;goto sigue1;}
else
sigue1:
if (input_state(pin_b1)==1) {contador=contador+1;porcentaje=20;goto sigue2;}
else
sigue2:
if (input_state(pin_b2)==1) {contador=contador+1;porcentaje=30;goto sigue3;}
else
sigue3:
if (input_state(pin_b3)==1) {contador=contador+1;porcentaje=40;goto sigue4;}
else
sigue4:
if (input_state(pin_b4)==1) {contador=contador+1;porcentaje=50;goto sigue5;}
else
sigue5:
if (input_state(pin_b5)==1) {contador=contador+1;porcentaje=60;goto sigue6;}
else
sigue6:
if (input_state(pin_b6)==1) {contador=contador+1;porcentaje=70;goto sigue7;}
else
sigue7:
if (input_state(pin_b7)==1) {contador=contador+1;porcentaje=80;goto sigue8;}
else
sigue8:
if (input_state(pin_c0)==1) {contador=contador+1;porcentaje=90;goto sigue9;}
else
sigue9:
if (input_state(pin_c1)==1) {contador=contador+1;porcentaje=100;goto sigue10;}
else
if (contador>=2) { porcentaje=1;goto sigue10;}
else
goto sigue10;

sigue10:

if (x==00) {goto senal250;}
else

if (x==1) {goto senal500;}
else

if (x==2) {goto senal1000;}
else

if (x==3) {goto senal2000;}
else

senal250:
///Señal 250 HZ//
setup_timer_2(t2_div_by_16,249,1);
setup_ccp1(ccp_pwm);
out1=(249*porcentaje)/100;
set_pwm1_duty(out1);

goto inicio;

Senal500:
///Señal 500 HZ//
setup_timer_2(t2_div_by_16, 123,1);
setup_ccp1(ccp_pwm);
out1=(123*porcentaje)/100;
set_pwm1_duty(out1);

goto inicio;

senal1000:
///Señal 1000 HZ//
setup_timer_2(t2_div_by_4, 249,1);
setup_ccp1(ccp_pwm);
out1=(249*porcentaje)/100;
set_pwm1_duty(out1);

goto inicio;

senal2000:
///Señal 2000 HZ//
setup_timer_2(t2_div_by_4, 124,1);
setup_ccp1(ccp_pwm);
out1=(124*porcentaje)/100;
set_pwm1_duty(out1);

goto inicio;
}
}

