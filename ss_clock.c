

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#define SLOW_WRITE 0
#define TIME_STAMP 0

char sev_seg_buff_3d[11][9][7]={
	{
	" 0000 ",
	"0    0",
	"0    0",
	"0    0",
	"      ",
	"0    0",
	"0    0",
	"0    0",
	" 0000 ",
	},
	{
	"      ",
	"     0",
	"     0",
	"     0",
	"      ",
	"     0",
	"     0",
	"     0",
	"      ",
	},
	{
	" 0000 ",
	"     0",
	"     0",
	"     0",
	" 0000 ",
	"0     ",
	"0     ",
	"0     ",
	" 0000 ",
	},
	{
	" 0000 ",
	"     0",
	"     0",
	"     0",
	" 0000 ",
	"     0",
	"     0",
	"     0",
	" 0000 ",
	},
	{
	"      ",
	"0    0",
	"0    0",
	"0    0",
	" 0000 ",
	"     0",
	"     0",
	"     0",
	"      ",
	},
	{
	" 0000 ",
	"0     ",
	"0     ",
	"0     ",
	" 0000 ",
	"     0",
	"     0",
	"     0",
	" 0000 ",
	},
	{
	" 0000 ",
	"0     ",
	"0     ",
	"0     ",
	" 0000 ",
	"0    0",
	"0    0",
	"0    0",
	" 0000 ",
	},
	{
	" 0000 ",
	"     0",
	"     0",
	"     0",
	"      ",
	"     0",
	"     0",
	"     0",
	"      ",
	},
	{
	" 0000 ",
	"0    0",
	"0    0",
	"0    0",
	" 0000 ",
	"0    0",
	"0    0",
	"0    0",
	" 0000 ",
	},
	{
	" 0000 ",
	"0    0",
	"0    0",
	"0    0",
	" 0000 ",
	"     0",
	"     0",
	"     0",
	" 0000 ",
	},
	{
	"  ",
	"  ",
	"00",
	"00",
	"  ",
	"00",
	"00",
	"  ",
	"  ",
	},
	};

char ts_buf[30];
char myTs[8];
char secondDigit=0;

//prototypes
void printSevenSegment(char * charsToPrint, int numOfChars);
void createTimestamp();
void runClock();
void waitForSecondDigitChange();
void initClock();
void timestampPrint();

int main(int argc, char **argv)
{
	initClock();
	runClock();
	return 0;
}

void runClock(){
	system("color 4");
	while(1){
		createTimestamp();
		printSevenSegment(myTs,sizeof(myTs));
		waitForSecondDigitChange();
		system("cls");
	}
}

void createTimestamp(){
	
	int i=0;
	time_t ltime; /* calendar time */
    ltime=time(NULL); /* get current cal time */
    sprintf(ts_buf, "%s",asctime( localtime(&ltime) ) );
    
    for(i=0;i<8;i++){
		myTs[i]=ts_buf[i+11];
	}
}

void printSevenSegment(char * charsToPrint, int numOfChars){
	int i=0;
	int j=0;
	/* loop trough lines, seven segment char have 9 lines/rows */
	for(i=0;i<9;i++){
		printf("\n");
		
		/* print i-th row of each char: concatenation of rows */
		for(j=0;j<numOfChars;j++){
			if(charsToPrint[j]>='0' && charsToPrint[j]<='9'){
				printf(" %s ", sev_seg_buff_3d[(int)(charsToPrint[j]-48)][i]);
			}else if(charsToPrint[j]==':'){
				printf(" %s ", sev_seg_buff_3d[10][i]);
			}else{
				printf(" %s ", "      ");
			}
			#if SLOW_WRITE==1
			usleep(5000);
			#endif
		}
	}
	printf("\n\n");
	#if TIME_STAMP==1
	timestampPrint();
	#endif
}

void timestampPrint(){
	printf("\n%s", ts_buf);
}

void waitForSecondDigitChange(){
	unsigned long timeToWait=400000;
	do{
		createTimestamp();
		usleep(timeToWait);
		timeToWait=timeToWait>>1;
	}while(secondDigit==myTs[7]);
	secondDigit=myTs[7];
}

void initClock(){
	createTimestamp();
	secondDigit=myTs[7];
}
