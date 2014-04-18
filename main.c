/*
 * main.c
 * 
 * 
 */


#include <stdio.h>
#include <stdlib.h>
//#include "seg_config.h"
//#include "string_buffers.h"
#include "tests.h"

int main(int argc, char **argv)
{
	test3();
	
	return 0;
}


char charTo7seg(char num){
	char segChar=0xFF;
	if(num <= 17 && num >= 0)
		segChar=numlut[num];
	else
		segChar=numlut[SEG_ERROR];
	return segChar;
}

char wireOutPins(char segChar){
	char wiredChar=0xff;
	char i;
	for(i=0; i<8; i++){
		
	}
	return wiredChar;
}

void segArduinoInit(){
	char i;
	for(i=0; i<8; i++)
		pinMode(segWireingArduino[i], OUTPUT);
}

void arduinoWriteToSevSegPins(char charToWrite){
	char i; 
	for(i=0; i<8; i++)
		digitalWrite(segWireingArduino[7-i], (charToWrite>>i)&0x01);
}

void testWriteToSevSegPins(char charToWrite){
	char i; 
	char charToPrint;
	
	charToPrint=charTo7seg(charToWrite);
	//printf("%d", charToPrint);
	
	for(i=0; i<8; i++){
		if((charToPrint>>i)&0x01)
			clearSegTest(seg_idx[7-i], seg_lens[7-i]);
		else
			setSegTest(seg_idx[7-i], seg_lens[7-i]);
	}	
}

void testWriteToSevSegPins2(char charToWrite){
	char i; 
	char charToPrint;
	
	charToPrint=charTo7seg(charToWrite);
	//printf("%d", charToPrint);
	
	for(i=0; i<8; i++){
		if((charToPrint>>i)&0x01)
			clearSegTest(seg_idx_hhmmss[7-i], seg_lens[7-i]);
		else
			setSegTest(seg_idx_hhmmss[7-i], seg_lens[7-i]);
	}	
}


