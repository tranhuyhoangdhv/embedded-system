#include <REGX52.H>
#include "..\lib\delay.h"
#define LED P0
#define LED1 P2_0
#define LED2 P2_1

char so[]={0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};
int dem,chuc,donvi;
int t;
	
void Delay_ms(int t){
	int x,y;
	for (x=0;x<t;x++){
		for (y=0;y<123;y++);
	}
}

void hienthi(){
	chuc=dem/10;
	donvi=dem%10;
	LED=so[chuc]; 	LED1=1; Delay_ms(10); LED1=0;
	LED=so[donvi]; LED2=1; Delay_ms(10); LED2=0;
	// quet led
}

void main(){
	EX0=1;				//cho phep ngat ngoai 0
	IT0=1;				//ngat theo suon
	EA=1;					//cho phep ngat hoat dong
	//cau hinh ngat ngoai
	while(1){
		hienthi();
	}
}

void ngat() interrupt 0{// ctrinh ngat
	dem++;
	if(dem==31){
			dem=0;
		}
}