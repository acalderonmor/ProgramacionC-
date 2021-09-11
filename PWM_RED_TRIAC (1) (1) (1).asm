	list p = 18F452
#include<p18F452.inc>

	CBLOCK	0x0A
	dc
	ENDC
	
			org		0x00
			goto		INICIO
			org		0x08
			goto		INTERRUPCION
			org		0x0c

INICIO
	
			rcall		CONF_PUERTOS
			rcall		BORRAR_BASURA
			rcall		CONF_TIMER0
			rcall		CONF_INT
			rcall		CONF_USART
			rcall		CARGA_INICIAL
			goto		PRINCIPAL

;-----------------------------------------------------------------------------------------------------------------------------------------
INTERRUPCION
			btfss		INTCON,1
			bra		RETORNAR
			btfss		PORTB,0
			goto		BAJO
			goto		ALTO
BAJO		
			bcf		PORTB,7			;PWM1 -> Alta
			bcf		INTCON,1		;Borrar Flag (INTERRUPCION)
			bsf		INTCON2,6		;Flanco de Subida
			bra		RETORNAR
ALTO		
			bcf		PORTB,7			;PWM1 -> Alta
			bcf		INTCON,1		;Borrar Flag (INTERRUPCION)
			bcf		INTCON2,6		;Flanco de Bajada			
			bra		RETORNAR
RETORNAR

			bsf		T0CON,7			;Encender TIMER	
			clrf		TMR0L
			retfie

;-----------------------------------------------------------------------------------------------------------------------------------------	

PRINCIPAL	
			btfsc		PIR1,5
			rcall		LEER_SERIAL	
			cpfseq		TMR0L,dc		
			bra		PRINCIPAL
			rcall		PWM
			bra 		PRINCIPAL		


;-----------------------------------------------------------------------------------------------------------------------------------------
PWM
			bcf		T0CON,7			;Apagar TIMER
			clrf		TMR0L
			bsf		PORTB,7			;Encender
			return
		
;-----------------------------------------------------------------------------------------------------------------------------------------
CONF_PUERTOS
; Esta rutina se emplea para configurar los pines del microcontrolador que se van a emplear.
; Los pines que se configuran con CERO (0) son salidas. Los pines que se configuran con UNO (1) son entradas

					;76543210
			movlw		b'00000001'
			movwf		TRISA
					;76543210
			movlw		b'00000001'	
			movwf		TRISB	
					;76543210
			movlw		b'10000000'
			movwf		TRISC
			clrf		TRISD		
			return
;-----------------------------------------------------------------------------------------------------------------------------------------
BORRAR_BASURA
; Esta rutina garantiza que los registros que se van a emplear inicien en Cero

			clrf		PORTD
			clrf		ADRESH
			clrf		ADRESL
			return
;-----------------------------------------------------------------------------------------------------------------------------------------
CONF_TIMER0
					;76543210
			movlw		b'01000100'
			movwf		T0CON
			clrf		TMR0L

			return
			
;-----------------------------------------------------------------------------------------------------------------------------------------
CONF_INT
			bsf		INTCON,4		;Interrupcion por RB0
			bsf		INTCON2,6		;Flanco de Subida
			bsf		INTCON,7
			return

;-----------------------------------------------------------------------------------------------------------------------------------------
CONF_USART		
					;76543210
			movlw		b'00100110'
			movwf		TXSTA	
					;76543210
			movlw		b'10010000'
			movwf		RCSTA
			movlw		d'25'
			movwf		SPBRG
			return	
;-----------------------------------------------------------------------------------------------------------------------------------------
LEER_SERIAL
			movf		RCREG,w
			movwf		dc
			movff		RCREG,PORTD
			bcf		PIR1,5
			return

;-----------------------------------------------------------------------------------------------------------------------------------------

CARGA_INICIAL	
			movlw		d'252'			;Valor cilco util (0-255)->(0-100%) 128->50%
			movwf		dc	
			return

			end
			