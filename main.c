/*
 * main.c
 * 
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include "seg_config.h"


int main(int argc, char **argv)
{
	int i=0;
	test2();
	for(i=0;i<20;i++){
		system("cls");
		testWriteToSevSegPins(i);
		test2();
		printf("\n\n %d",i);
		getchar();
		//sleep(1);
	}
	//clearSegTest(seg_idx[0], seg_lens[0]);
	
	return 0;
}

/**
 * initializing mcu pins, wirining 0 to display
 * */
void test1(){
	segArduinoInit();
	arduinoWriteToSevSegPins(numlut[0]);
}

/**
 * Print seven segment test emulator buffer
 * */
void test2(){
	printf("%s", sev_seg_buff);
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


