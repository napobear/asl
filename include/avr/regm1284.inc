		ifndef	__regm1284inc
__regm1284inc	equ	1
                save
                listing off   ; no listing over this file

;****************************************************************************
;*                                                                          *
;*   AS 1.42 - File REGM1284.INC                                            *
;*                                                                          *
;*   Contains Bit & Register Definitions for ATmega1284                     *
;*                                                                          *
;****************************************************************************

;----------------------------------------------------------------------------
; Memory Limits

E2END           equ	4095
RAMSTART	equ	0x100,data
RAMEND		equ	0x40ff,data
FLASHEND	label	0x1ffff

;----------------------------------------------------------------------------
; Chip Control

MCUCR		port	0x35		; MCU Control Register
IVCE		avrbit	MCUCR,0		; Interrupt Vector Change Enable
IVSEL		avrbit	MCUCR,1		; Interrupt Vector Select

MCUSR		port	0x34		; MCU Status Register
PORF		avrbit	MCUSR,0		; Power-On Reset Occured
EXTRF		avrbit	MCUSR,1		; External Reset Occured
BORF		avrbit	MCUSR,2		; Brown Out Reset Occured
WDRF		avrbit	MCUSR,3		; watchdog Reset Occured

SMCR		port	0x33		; Sleep Mode Control Register
SE		avrbit	SMCR,0		; Sleep Mode Enable
SM0		avrbit	SMCR,1		; Sleep Mode Select
SM1		avrbit	SMCR,2
SM2		avrbit	SMCR,3

PRR0		sfr	0x64		; Power Reduction Register 0
PRADC		avrbit	PRR0,0		; Power Reduction ADC
PRUSART0	avrbit	PRR0,1		; Power Reduction USART0
PRSPI0		avrbit	PRR0,2		; Power Reduction Serial Peripheral Interface 0
PRTIM1		avrbit	PRR0,3		; Power Reduction Timer/Counter 1
PRUSART1	avrbit	PRR0,4		; Power Reduction USART1
PRTIM0		avrbit	PRR0,5		; Power Reduction Timer/Counter 0
PRTIM2		avrbit	PRR0,6		; Power Reduction Timer/Counter 2
PRTWI		avrbit	PRR0,7		; Power Reduction TWI

PRR1		sfr	0x65		; Power Reduction Register 1
PRTIM3		avrbit	PRR1,0		; Power Reduction Timer/Counter 3

OSCCAL		sfr	0x66		; Oscillator Calibration

CLKPR		sfr	0x61		; Clock Prescale Register
CLKPS0		avrbit	CLKPR,0		; Clock Prescaler Select
CLKPS1		avrbit	CLKPR,1
CLKPS2		avrbit	CLKPR,2
CLKPS3		avrbit	CLKPR,3
CLKPCE		avrbit	CLKPR,7		; Clock Prescaler Change Enable

;----------------------------------------------------------------------------
; EEPROM/Program Memory Access

		include	"avr/eem2.inc"
		include	"avr/spmcsr37.inc"

EEPM0		avrbit	EECR,4		; EEPROM Programming Mode
EEPM1		avrbit	EECR,5

SIGRD		avrbit	SIGRD,5		; Signature Row Read

;----------------------------------------------------------------------------
; JTAG

JTD		avrbit	MCUCR,7		; JTAG Disable

JTRF		avrbit	MCUSR,4		; JTAG Reset Occured

OCDR		port	0x31		; On-Chip Debug Register

;----------------------------------------------------------------------------
; GPIO

PUD		avrbit	MCUCR,4		; Pull Up Disable

PINA		port	0x00		; Port A @ 0x00 (IO) ff.
PINB		port	0x03		; Port B @ 0x03 (IO) ff.
PINC		port	0x06		; Port C @ 0x03 (IO) ff.
PIND		port    0x09		; Port D @ 0x09 (IO) ff.

PCMSK0		sfr	0x6b		; Pin Change Mask Register 0
PCMSK1		sfr	0x6c		; Pin Change Mask Register 1
PCMSK2		sfr	0x6d		; Pin Change Mask Register 2
PCMSK3		sfr	0x73		; Pin Change Mask Register 3
PCICR		sfr	0x68		; Pin Change Interrupt Control Register
PCIFR		port	0x1b		; Pin Change Interrupt Flag Register

GPIOR0		port	0x1e		; General Purpose I/O Registers
GPIOR1		port	0x2a
GPIOR2		port	0x2b

;----------------------------------------------------------------------------
; Interrupt Vectors

		enumconf 2,code
		enum     INT0_vect=2		; External Interrupt Request 0
		nextenum INT1_vect		; External Interrupt Request 1
		nextenum INT2_vect		; External Interrupt Request 2
		nextenum PCINT0_vect		; Pin Change Interrupt Request 0
		nextenum PCINT1_vect		; Pin Change Interrupt Request 1
		nextenum PCINT2_vect		; Pin Change Interrupt Request 2
		nextenum PCINT3_vect		; Pin Change Interrupt Request 3
		nextenum WDT_vect		; Watchdog Time-Out Interrupt
		nextenum TIMER2_COMPA_vect	; Timer/Counter 2 Compare Match A
		nextenum TIMER2_COMPB_vect	; Timer/Counter 2 Compare Match B
		nextenum TIMER2_OVF_vect	; Timer/Counter 2 Overflow
		nextenum TIMER1_CAPT_vect	; Timer/Counter 1 Capture Event
		nextenum TIMER1_COMPA_vect	; Timer/Counter 1 Compare Match A
		nextenum TIMER1_COMPB_vect	; Timer/Counter 1 Compare Match B
		nextenum TIMER1_OVF_vect	; Timer/Counter 1 Overflow
		nextenum TIMER0_COMPA_vect	; Timer/Counter 0 Compare Match A
		nextenum TIMER0_COMPB_vect	; Timer/Counter 0 Compare Match B
		nextenum TIMER0_OVF_vect	; Timer/Counter 0 Overflow
		nextenum SPI_STC_vect		; SPI Serial Transfer Complete
		nextenum USART0_RX_vect		; USART0 Rx Complete
		nextenum USART0_UDRE_vect	; USART0 Data Register Empty
		nextenum USART0_TX_vect		; USART0 Tx Complete
		nextenum ANALOG_COMP_vect	; Analog Comparator
		nextenum ADC_vect		; ADC Conversion Complete
		nextenum EE_READY_vect		; EEPROM Ready
		nextenum TWI_vect		; Two-Wire Serial interface
		nextenum SPM_READY_vect		; Store Program Memory Ready
		nextenum USART1_RX_vect		; USART1 Rx Complete
		nextenum USART1_UDRE_vect	; USART1 Data Register Empty
		nextenum USART1_TX_vect		; USART1 Tx Complete
		nextenum TIMER3_CAPT_vect	; Timer/Counter 3 Capture Event
		nextenum TIMER3_COMPA_vect	; Timer/Counter 3 Compare Match A
		nextenum TIMER3_COMPB_vect	; Timer/Counter 3 Compare Match B
		nextenum TIMER3_OVF_vect	; Timer/Counter 3 Overflow

;----------------------------------------------------------------------------
; External Interrupts

EICRA		sfr	0x69		; External Interrupt Control Register A
ISC00		avrbit	EICRA,0		; External Interrupt 0 Sense Control
ISC01		avrbit	EICRA,1
ISC10		avrbit	EICRA,2		; External Interrupt 1 Sense Control
ISC11		avrbit	EICRA,3
ISC20		avrbit	EICRA,4		; External Interrupt 2 Sense Control
ISC21		avrbit	EICRA,5

EIMSK		port	0x1d		; External Interrupt Mask Register
INT0		avrbit	EIMSK,0		; Enable External Interrupt 0
INT1		avrbit	EIMSK,1		; Enable External Interrupt 1
INT2		avrbit	EIMSK,2		; Enable External Interrupt 2

EIFR		port	0x1c		; External Interrupt Flag Register
INTF0		avrbit	EIFR,0		; External Interrupt 0 Occured
INTF1	        avrbit	EIFR,1		; External Interrupt 1 Occured
INTF2		avrbit	EIFR,2		; External Interrupt 2 Occured

;----------------------------------------------------------------------------
; Timers

GTCCR		port	0x23		; General Timer/Counter Control Register
PSRSYNC		avrbit	GTCCR,0		; Prescaler Reset
TSM		avrbit	GTCCR,7		; Timer/Counter Synchronization Mode

TCCR0A		port	0x24		; Timer/Counter 0 Control Register A
WGM00		avrbit	TCCR0A,0	; Timer/Counter 0 Waveform Generation Mode
WGM01		avrbit	TCCR0A,1
COM0B0		avrbit	TCCR0A,4	; Timer/Counter 0 Compare Mode B
COM0B1		avrbit	TCCR0A,5
COM0A0		avrbit	TCCR0A,6	; Timer/Counter 0 Compare Mode A
COM0A1		avrbit	TCCR0A,7
TCCR0B		port	0x25		; Timer/Counter 0 Control Register B
CS00		avrbit	TCCR0B,0	; Timer/Counter 0 Clock Select
CS01		avrbit	TCCR0B,1
CS02		avrbit	TCCR0B,2
WGM02		avrbit	TCCR0B,3
FOC0B		avrbit	TCCR0B,6	; Timer/Counter 0 Force Output Compare Match B
FOC0A		avrbit	TCCR0B,7	; Timer/Counter 0 Force Output Compare Match A
TCNT0		port	0x26		; Timer/Counter 0 Value
OCR0A		port	0x27		; Timer/Counter 0 Output Compare Value A
OCR0B		port	0x28		; Timer/Counter 0 Output Compare Value B

TCCR1A		sfr	0x80		; Timer/Counter 1 Control Register A
WGM10		avrbit	TCCR1A,0	; Timer/Counter 1 Waveform Generation Mode
WGM11		avrbit	TCCR1A,1
COM1B0		avrbit	TCCR1A,4	; Timer/Counter 1 Compare Mode B
COM1B1		avrbit	TCCR1A,5
COM1A0		avrbit	TCCR1A,6	; Timer/Counter 1 Compare Mode A
COM1A1		avrbit	TCCR1A,7
TCCR1B		sfr	0x81		; Timer/Counter 1 Control Register B
CS10		avrbit	TCCR1B,0	; Timer/Counter 1 Prescaler Setting
CS11		avrbit	TCCR1B,1
CS12		avrbit	TCCR1B,2
WGM12		avrbit	TCCR1B,3
WGM13		avrbit	TCCR1B,4
ICES1		avrbit	TCCR1B,6	; Timer/Counter 1 Capture Slope Selection
ICNC1		avrbit	TCCR1B,7	; Timer/Counter 1 Capture Noise Filter
TCCR1C		sfr	0x82		; Timer/Counter 1 Control Register C
FOC1B		avrbit	TCCR1C,6	; Timer/Counter 1 Force Output Compare B
FOC1A		avrbit	TCCR1C,7	; Timer/Counter 1 Force Output Compare A
TCNT1L		sfr	0x84		; Timer/Counter 1 Value LSB
TCNT1H		sfr	0x85		; Timer/Counter 1 Value MSB
OCR1AL		sfr	0x88		; Timer/Counter 1 Output Compare Value A LSB
OCR1AH		sfr	0x89		; Timer/Counter 1 Output Compare Value A MSB
OCR1BL		sfr	0x8a		; Timer/Counter 1 Output Compare Value B LSB
OCR1BH		sfr	0x8b		; Timer/Counter 1 Output Compare Value B MSB
ICR1L		sfr	0x86		; Timer/Counter 1 Input Capture Value LSB
ICR1H		sfr	0x87		; Timer/Counter 1 Input Capture Value MSB

TCCR2A		sfr	0xb0		; Timer/Counter 2 Control Register A
WGM20		avrbit	TCCR2A,0	; Timer/Counter 2 Waveform Generation Mode
WGM21		avrbit	TCCR2A,1
COM2B0		avrbit	TCCR2A,4	; Timer/Counter 2 Compare Mode B
COM2B1		avrbit	TCCR2A,5
COM2A0		avrbit	TCCR2A,6	; Timer/Counter 2 Compare Mode A
COM2A1		avrbit	TCCR2A,7
TCCR2B		sfr	0xb1		; Timer/Counter 2 Control Register B
CS20		avrbit	TCCR2B,0	; Timer/Counter 2 Prescaler Setting
CS21		avrbit	TCCR2B,1
CS22		avrbit	TCCR2B,2
WGM22		avrbit	TCCR2B,3
FOC2B		avrbit	TCCR2B,6	; Timer/Counter 2 Force Output Compare B
FOC2A		avrbit	TCCR2B,7	; Timer/Counter 2 Force Output Compare A
TCNT2		sfr	0xb2		; Timer/Counter 2 Value
OCR2A		sfr	0xb3		; Timer/Counter 2 Output Compare Value A
OCR2B		sfr	0xb4		; Timer/Counter 2 Output Compare Value B

TCCR3A		sfr	0x90		; Timer/Counter 3 Control Register A
WGM30		avrbit	TCCR3A,0	; Timer/Counter 3 Waveform Generation Mode
WGM31		avrbit	TCCR3A,1
COM3B0		avrbit	TCCR3A,4	; Timer/Counter 3 Compare Mode B
COM3B1		avrbit	TCCR3A,5
COM3A0		avrbit	TCCR3A,6	; Timer/Counter 3 Compare Mode A
COM3A1		avrbit	TCCR3A,7
TCCR3B		sfr	0x91		; Timer/Counter 3 Control Register B
CS30		avrbit	TCCR3B,0	; Timer/Counter 3 Prescaler Setting
CS31		avrbit	TCCR3B,1
CS32		avrbit	TCCR3B,2
WGM32		avrbit	TCCR3B,3
WGM33		avrbit	TCCR3B,4
ICES3		avrbit	TCCR3B,6	; Timer/Counter 3 Capture Slope Selection
ICNC3		avrbit	TCCR3B,7	; Timer/Counter 3 Capture Noise Filter
TCCR3C		sfr	0x92		; Timer/Counter 3 Control Register C
FOC3B		avrbit	TCCR3C,6	; Timer/Counter 3 Force Output Compare B
FOC3A		avrbit	TCCR3C,7	; Timer/Counter 3 Force Output Compare A
TCNT3L		sfr	0x94		; Timer/Counter 3 Value LSB
TCNT3H		sfr	0x95		; Timer/Counter 3 Value MSB
OCR3AL		sfr	0x98		; Timer/Counter 3 Output Compare Value A LSB
OCR3AH		sfr	0x99		; Timer/Counter 3 Output Compare Value A MSB
OCR3BL		sfr	0x9a		; Timer/Counter 3 Output Compare Value B LSB
OCR3BH		sfr	0x9b		; Timer/Counter 3 Output Compare Value B MSB
ICR3L		sfr	0x96		; Timer/Counter 3 Input Capture Value LSB
ICR3H		sfr	0x97		; Timer/Counter 3 Input Capture Value MSB

TIMSK0		sfr	0x6e		; Timer/Counter 0 Interrupt Mask Register
TOIE0		avrbit	TIMSK0,0	; Timer/Counter 0 Overflow Interrupt Enable
OCIE0A		avrbit	TIMSK0,1	; Timer/Counter 0 Output Compare Interrupt Enable A
OCIE0B		avrbit	TIMSK0,2	; Timer/Counter 0 Output Compare Interrupt Enable B
TIMSK1		sfr	0x6f		; Timer/Counter 1 Interrupt Mask Register
TOIE1		avrbit	TIMSK1,0	; Timer/Counter 1 Overflow Interrupt Enable
OCIE1A		avrbit	TIMSK1,1	; Timer/Counter 1 Output Compare Interrupt Enable A
OCIE1B		avrbit	TIMSK1,2	; Timer/Counter 1 Output Compare Interrupt Enable B
ICIE1		avrbit	TIMSK1,5	; Timer/Counter 1 Input Capture Enable
TIMSK2		sfr	0x70		; Timer/Counter 2 Interrupt Mask Register
TOIE2		avrbit	TIMSK2,0	; Timer/Counter 2 Overflow Interrupt Enable
OCIE2A		avrbit	TIMSK2,1	; Timer/Counter 2 Output Compare Interrupt Enable A
OCIE2B		avrbit	TIMSK2,2	; Timer/Counter 2 Output Compare Interrupt Enable B
TIMSK3		sfr	0x71		; Timer/Counter 3 Interrupt Mask Register
TOIE3		avrbit	TIMSK3,0	; Timer/Counter 3 Overflow Interrupt Enable
OCIE3A		avrbit	TIMSK3,1	; Timer/Counter 3 Output Compare Interrupt Enable A
OCIE3B		avrbit	TIMSK3,2	; Timer/Counter 3 Output Compare Interrupt Enable B
ICIE3		avrbit	TIMSK3,5	; Timer/Counter 3 Input Capture Enable

TIFR0		port	0x15		; Timer/Counter 0 Interrupt Status Register
TIFR1		port	0x16		; Timer/Counter 1 Interrupt Status Register
TIFR2		port	0x17		; Timer/Counter 2 Interrupt Status Register
TIFR3		port	0x18		; Timer/Counter 3 Interrupt Status Register

ASSR		sfr	0xb6		; Asynchronous Status Register
TCR2BUB		avrbit	ASSR,0		; Timer/Counter Control Register 2 B Update Busy
TCR2AUB		avrbit	ASSR,1		; Timer/Counter Control Register 2 A Update Busy
OCR2BUB		avrbit	ASSR,2		; Output Compare Register 2 B Update Busy
OCR2AUB		avrbit	ASSR,3		; Output Compare Register 2 A Update Busy
TCN2UB		avrbit	ASSR,4		; Timer/Counter 2 Update Busy
AS2		avrbit	ASSR,5		; Asynchronous Timer/Counter 2
EXCLK		avrbit	ASSR,6		; Enable External Clock Input

;----------------------------------------------------------------------------
; Watchdog Timer

		include	"avr/wdme.inc"

;----------------------------------------------------------------------------
; USART

__USART0_SPI__	equ	1
		include	"avr/usartc0.inc"
__USART1_SPI__	equ	1
		include	"avr/usartc8.inc"

;----------------------------------------------------------------------------
; SPI

		include	"avr/spim02c.inc"

;----------------------------------------------------------------------------
; TWI

		include	"avr/twimb8.inc"

;----------------------------------------------------------------------------
; A/D Converter

		include	"avr/adcm78.inc"

MUX4		avrbit	ADMUX,4

;----------------------------------------------------------------------------
; Analog Comparator

		include "avr/acm30.inc"

		restore			; re-enable listing

		endif			; __regm1284inc
