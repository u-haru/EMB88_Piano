#include <avr/io.h>
#include <avr/wdt.h>
#include <avr/interrupt.h>
#include <stdlib.h>

#define vol 255
#define tc 5
#define spd 30

#ifndef o2a
	#define o2a 255
#endif

unsigned char notes[tc];
unsigned char note=0;
unsigned char noise = 0;


ISR(TIMER1_COMPA_vect){
	for(int i = 1;i<tc;i++){
		if(notes[(note+i)%tc]!=0){
			note=(note+i)%tc;
			break;
		}
	}
	if(notes[note] < 10 && notes[note])noise = rand()%(notes[note]*10)+(notes[note]*18);
	else noise = 0;
}

ISR(TIMER2_OVF_vect){
	static unsigned char cnt = 0;

	if(cnt++>=notes[note]&&!noise){
		cnt=0;
		OCR2B=0;
	}else if(cnt>=noise&&noise){
		cnt=0;
		OCR2B=0;
	}else{
		PORTB=notes[note];
		if(!noise)
		OCR2B=notes[note]?vol:0;
		else
		OCR2B=noise?vol:0;
	}
}

const uint8_t notemap[] = {254, 239, 226, 213, 201, 190, 179, 169, 160, 151, 142, 134, 127, 119, 113, 106, 100, 95, 89, 84, 80, 75, 71, 67, 63, 59, 56, 53, 50, 47, 44, 42, 40, 37, 35, 33, 31, 29, 28, 26, 25, 23, 22, 21, 19, 18, 17, 16, 15, 14, 14, 13, 12, 11, 11, 9, 8, 7, 6, 5, 4, 3, 2, 1};
int main(void){
	DDRB = 0xFF;
	DDRC = 0x0F;
	DDRD = 0xFE;
	
	PORTB = 0x00;
	PORTD = 0x00;
	PORTC = 0x30;//ここゼロにしてるとスイッチ反応しない。
	
	TCCR2A= 0x23;
	TCCR2B= 0x09;
	OCR2B = 0;
	TIMSK2= 1;
	
	TCCR1A= 0x00;
	TCCR1B= 0x0D;
	OCR1A = 7811/spd;//一秒にspd回割り込み// 8000000/1024-1/spd
	TIMSK1= 0;
	OCR2A=o2a;
	
	srand(10);//noise

	UBRR0 = 500000/38400-1;//serial
	UCSR0A= 0;
	UCSR0C= 6;
	UCSR0B= 0x18;

	for(int i = 0;i<tc;i++){
		notes[i]=0;
	}
	TIMSK1= 0x2;
	sei();//割り込み有効化
	while(1){
		wdt_reset();
		if((~PINC >> 4)&1){
			// TIMSK1= 0x0;
			for(int i = 0;i<tc;i++) notes[i]=0;
		}else
		if((~PINC >> 4)>>1&1){
			TIMSK1= 0x2;
			PORTB=0xaa;
		}
		
		if(UCSR0A&0x80){
			char data = UDR0&0xFF;
			if(data&0x80){//Note ON
				for(int i = 0;i<tc;i++){
					if(!notes[i]){
						notes[i]=notemap[data&0x7F];
						break;
					}
				}
			}else{//Note OFF
				for(int i = 0;i<tc;i++){
					if(notes[i]==notemap[data&0x7F])notes[i]=0;
				}
			}
			PORTB=data&0x7F;
		}
	}
	return 0;
}