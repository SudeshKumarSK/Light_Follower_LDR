#include<avr/io.h>
#include<util/delay.h>
void init_adc()
{
ADCSRA=ADCSRA|0b00000001<<ADEN;
ADCSRA=ADCSRA|0b00000001<<ADPS2;
ADMUX=ADMUX|0b00000001<<REFS0;
}
unsigned int read_adc(int p)
{
ADMUX&=0b11111000;
ADMUX=ADMUX|p;
ADCSRA=ADCSRA|(0b00000001<<ADSC);
while((ADCSRA&(0b00000001<<ADIF))==0);
ADCSRA=ADCSRA|(0b00000001<<ADIF);
return(ADC);
}
void main()
{
DDRB=0b11111111;
init_adc();
_delay_ms(50);
unsigned int q;
unsigned int p;
while(1)
{
p=read_adc(1);
q=read_adc(0);
if(p<819&&q<950)
PORTB=0b00001010;
if(p>819&&q<950)
PORTB=0b00000110;
if(p<819&&q>950)
PORTB=0b00001001;
if(p>819&&q>950)
PORTB=0b00000000;
}
}
