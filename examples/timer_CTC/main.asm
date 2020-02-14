
obj/main.elf:     file format elf32-avr


Disassembly of section .text:

00000000 <__vectors>:
__vectors():
   0:	0c 94 72 00 	jmp	0xe4	; 0xe4 <__ctors_end>
   4:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
   8:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
   c:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  10:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  14:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  18:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  1c:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  20:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  24:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  28:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  2c:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  30:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  34:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  38:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  3c:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  40:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  44:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  48:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  4c:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  50:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  54:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  58:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  5c:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  60:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  64:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  68:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  6c:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  70:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  74:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  78:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  7c:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  80:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  84:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  88:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  8c:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  90:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  94:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  98:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  9c:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  a0:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  a4:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  a8:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  ac:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  b0:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  b4:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  b8:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  bc:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  c0:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  c4:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  c8:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  cc:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  d0:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  d4:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  d8:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  dc:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  e0:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>

000000e4 <__ctors_end>:
__trampolines_start():
  e4:	11 24       	eor	r1, r1
  e6:	1f be       	out	0x3f, r1	; 63
  e8:	cf ef       	ldi	r28, 0xFF	; 255
  ea:	d1 e2       	ldi	r29, 0x21	; 33
  ec:	de bf       	out	0x3e, r29	; 62
  ee:	cd bf       	out	0x3d, r28	; 61
  f0:	00 e0       	ldi	r16, 0x00	; 0
  f2:	0c bf       	out	0x3c, r16	; 60
  f4:	0e 94 80 00 	call	0x100	; 0x100 <main>
  f8:	0c 94 96 00 	jmp	0x12c	; 0x12c <_exit>

000000fc <__bad_interrupt>:
__vector_38():
  fc:	0c 94 00 00 	jmp	0	; 0x0 <__vectors>

00000100 <main>:
main():
/home/duys/AVR/avr_vscode_template/examples/16bit_timer/src/main.c:21
#define BAUD 250
#define PRESCALER 1
#define TIMER_COMP (unsigned int)(((1.0 / (float)BAUD / PRESCALER) / (1.0 / (float)F_CPU)) - 1)

int main(void) {
	SETBIT(DDRB, PB7);	 // set output LED
 100:	27 9a       	sbi	0x04, 7	; 4
/home/duys/AVR/avr_vscode_template/examples/16bit_timer/src/main.c:22
	SETBIT(TCCR1B, CS10);  // set timer to use F_CPU; no prescaler
 102:	80 91 81 00 	lds	r24, 0x0081	; 0x800081 <__TEXT_REGION_LENGTH__+0x700081>
 106:	81 60       	ori	r24, 0x01	; 1
 108:	80 93 81 00 	sts	0x0081, r24	; 0x800081 <__TEXT_REGION_LENGTH__+0x700081>
/home/duys/AVR/avr_vscode_template/examples/16bit_timer/src/main.c:23
	C_SETBIT(OUTPUT_LED);
 10c:	2f 9a       	sbi	0x05, 7	; 5
/home/duys/AVR/avr_vscode_template/examples/16bit_timer/src/main.c:28
	unsigned int x = TIMER_COMP;
	x++;

	for (;;) {
		if (TCNT1 >= TIMER_COMP) {
 10e:	80 91 84 00 	lds	r24, 0x0084	; 0x800084 <__TEXT_REGION_LENGTH__+0x700084>
 112:	90 91 85 00 	lds	r25, 0x0085	; 0x800085 <__TEXT_REGION_LENGTH__+0x700085>
 116:	8f 3f       	cpi	r24, 0xFF	; 255
 118:	99 4f       	sbci	r25, 0xF9	; 249
 11a:	c8 f3       	brcs	.-14     	; 0x10e <main+0xe>
/home/duys/AVR/avr_vscode_template/examples/16bit_timer/src/main.c:29
			C_FLIPBIT(OUTPUT_LED);  // toggle pin on/off
 11c:	85 b1       	in	r24, 0x05	; 5
 11e:	80 58       	subi	r24, 0x80	; 128
 120:	85 b9       	out	0x05, r24	; 5
/home/duys/AVR/avr_vscode_template/examples/16bit_timer/src/main.c:30
			TCNT1 = 0;				// reset timer
 122:	10 92 85 00 	sts	0x0085, r1	; 0x800085 <__TEXT_REGION_LENGTH__+0x700085>
 126:	10 92 84 00 	sts	0x0084, r1	; 0x800084 <__TEXT_REGION_LENGTH__+0x700084>
 12a:	f1 cf       	rjmp	.-30     	; 0x10e <main+0xe>

0000012c <_exit>:
exit():
/home/jenkins/workspace/avr-gcc-staging/label/debian7-x86_64/gcc-build/avr/avr6/libgcc/../../../../gcc/libgcc/config/avr/lib1funcs.S:2278
 12c:	f8 94       	cli

0000012e <__stop_program>:
__stop_program():
/home/jenkins/workspace/avr-gcc-staging/label/debian7-x86_64/gcc-build/avr/avr6/libgcc/../../../../gcc/libgcc/config/avr/lib1funcs.S:2280
 12e:	ff cf       	rjmp	.-2      	; 0x12e <__stop_program>
