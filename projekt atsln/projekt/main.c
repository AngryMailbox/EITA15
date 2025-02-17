/*
 * projeckt.c
 *
 * Created: 2022-05-17 11:14:46
 * Author : ph7217jo-s
 */ 

#include <avr/io.h>
#include "true_den.h"

typedef enum { false, true } bool;


int main(void)
{
	
	bool alarmOn = false;
	int code[4] = {0, 4, 2, 1};
	//output	
	DDRD = 0xff;
	
	//init input
	// Configure PORT C bit 0     to an input
	DDRC = 
	x00;

	// Configure ADC to be left justified, use AVCC as reference, and select ADC0 as ADC input
	ADMUX = 0b01000000;

	// Enable the ADC and set the prescaler to max value (128)
	ADCSRA = 0b10000111;
   
    /* Replace with your application code */
    while (1) 
    {
		getSensorInput();
    }
}



//går ut till skärmen och visar senaste tid som larmet ringde
void displayState() {
	
}

// gets numpad input
int getKeyInput() {
		
}

// loop through and get sensor input
void getSensorInput() {
	// Start an ADC conversion by setting ADSC bit (bit 6)
	ADCSRA = ADCSRA | (1 << ADSC);
	
	// Wait until the ADSC bit has been cleared
	while(ADCSRA & (1 << ADSC));

	if(ADCH > 20)
	{
		// Turn LED on
		debugLED(false);

	}
	else
	{
		// Turn LED off
				debugLED(true);

	}
}

// set LED
void setLED(bool red, bool blue) {
}

void startSiren() {
	
}

void stopSiren() {
	
}

void debugLED(bool on) {
	if (on) {
		PORTD |= 0b01000000;
	} else {
		PORTD &= 0b10111111;
	}
}