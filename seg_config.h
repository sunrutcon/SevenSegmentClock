
#include<stdio.h>

#define SEG_CHAR_MIN	0
#define SEG_CHAR_MAX	17

#define SEG_ERROR	18
#define SEG_OFF 	17
#define SEG_ON 		16

#define OUTPUT	1
#define INPUT	0

#define HIGH	1
#define LOW		0

#define CTEST


/**
 * Buffer -  seven segment to display in command prompt
 *
 * */
char sev_seg_buff[]={
	"\n 0000 " 		// 0	6
	"\n0    0" 		// 7	13
	"\n0    0" 		// 14	20
	"\n0    0" 		// 21	27
	"\n 0000 " 		// 28	34
	"\n0    0" 		// 35	41
	"\n0    0" 		// 42	48
	"\n0    0" 		// 49	55
	"\n 0000  0" 	// 56	62	64
	"\n",};	   		// 65
	
/**
 * Segment indexes
 * @deprecated
 * */
char seg_a_idx[]={2,3,4,5};
char seg_b_idx[]={13,20,27};
char seg_c_idx[]={41,48,55};
char seg_d_idx[]={58,59,60,61};
char seg_e_idx[]={36,43,50};
char seg_f_idx[]={8,15,22};
char seg_g_idx[]={30,31,32,33};
char seg_dp_idx[]={64};

/**
 * Segment buffer indexes
 * 
 * */
char seg_idx[][4]={
	{ 2, 3, 4, 5},
	{13,20,27,-1},
	{41,48,55,-1},
	{58,59,60,61},
	{36,43,50,-1},
	{ 8,15,22,-1},
	{30,31,32,33},
	{64,-1,-1,-1},
	};

/**
 * Segment lengths
 * 
 * */
char seg_lens[8]=
   //a,b,c,d,e,f,g,dp
	{4,3,3,4,3,3,4,1};

/**
 * Lookup table to convert number to 7 seg byte
 * 
 * */
static const char numlut[19] = {
	//abcdefg.
	0b00000011,	//	0
	0b10011111,	//	1
	0b00100101,	//	2
	0b00001101,	//	3
	0b10011001,	//	4
	0b01001001,	//	5
	0b01000001,	//	6
	0b00011111,	//	7
	0b00000001,	//	8
	0b00001001,	//	9

	0b00010001, //	A	10
	0b11000001,	//	b	11
	0b01100011,	//	C	12
	0b10000101,	//	d	13
	0b01100001,	//	E	14
	0b01110001,	//	F	15

	0b11111111, // off	16
	0b00000000, // on	17
	0b01101101, // error, 18, writes || lines to sev seg display
};

static const char segWireing[8]=
	// a b c d e f g .
	 { 7,6,5,4,3,2,1,0, };
	 
static const char segWireingShiftOut[8]=
	// a b c d e f g .
	 { 7,6,5,4,3,2,1,0, };
	 
static const char segWireingArduino[8]=
	// a b c d e f g .
	 { 4,5,7,8,9,3,2,6 };
	 
char charTo7seg(char num);
char wireOutPins(char segChar);
void segArduinoInit();
void arduinoWriteToSevSegPins(char charToWrite);

void testWriteToSevSegPins(char charToWrite);

/**
 * Set segment to test display
 * */
void setSegTest(char * testSeg, char arlen){
	int i;
	for(i=0; i< arlen; i++)
		sev_seg_buff[testSeg[i]]='0';
		
}

/**
 * Clear segment from display, turn off
 * */
void clearSegTest(char * testSeg, char arlen){
	int i;
	for(i=0; i< arlen; i++){
		//printf(" %d , ", testSeg[i]);
		sev_seg_buff[testSeg[i]]=' ';
		
	}
}


/**
 * Arduino functions
 * */
void digitalWrite(char pin, char pinState);
void pinMode(char pin, char mode);



void digitalWrite(char pin, char pinState){
	printf("\n Arduino pin %d set to %s \n", pin, pinState==0 ? "LOW" : "HIGH");
}

void pinMode(char pin, char mode){
	printf("\n Arduino pin %d set to %s \n", pin, mode==0 ? "INPUT" : "OUTPUT");
}

