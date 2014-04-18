#include <stdio.h>
#include <stdlib.h>
#include "seg_config.h"
#include "string_buffers.h"

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

void test3(){
	int i=0;
	test2();
	for(i=0;i<20;i++){
		system("cls");
		testWriteToSevSegPins(i);
		test2();
		printf("\n\n %d",i);
		//getchar();
		sleep(1);
	}
	//clearSegTest(seg_idx[0], seg_lens[0]);
}

void test4(){
	printf("%s", sev_seg_hhmmss);
}

void test5(){
	int i=0;
	for(i=0; i<100; i++)
	{
		printf("%c", sev_seg_hhmmss[i]);
	}
}

