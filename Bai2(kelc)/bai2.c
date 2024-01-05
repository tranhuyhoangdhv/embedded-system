#include <REGX52.H>
#define LED P2

char so[]={0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};

int dem=0;
	
void main(){
	EX1=1;				//cho phep ngat ngoai 1
	IT1=1;				//ngat theo suon
	EA=1;					//cho phep ngat hoat dong 
	//cau hinh ngat ngoai
	while(1){
	LED=so[dem];
	}
}

void ngat() interrupt 2{
	dem++;
	if (dem>9) dem=0;
}