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
FLOAT  X=5100,DATA1,DATA2;


void main (){



inicio:
if (input_state(pin_a0)==1) {  goto PWM123;}
else
goto inicio;

PWM123:

setup_timer_2(t2_div_by_16, 255,8);
setup_ccp1(ccp_pwm);
set_pwm1_duty(127);


GOTO INICIO;



}
