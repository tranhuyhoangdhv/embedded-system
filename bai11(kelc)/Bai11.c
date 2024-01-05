//TRẦN HUY HOÀNG K61 ĐẠI HỌC VINH 
//MSSV 205752021610030
#include <REGX52.H>
#define LED P1_1
int i;
void delay(){
	TMOD = 0x01;// timer 0 che do 16 bit che do 1
	TH0 = 0x3C;
	TL0 = 0xB0;// delay50ms 65536-50000
	TR0 = 1;	// bat timer chay
	while (!TF0);
	TF0 = 0;
	TR0 = 0;
}
void main(){
	LED=1;
	while(1){
		LED=!LED;
		for(i=0;i<10;i++) delay();
	}
}
