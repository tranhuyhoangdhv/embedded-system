//TRẦN HUY HOÀNG K61 ĐẠI HỌC VINH 
//MSSV 205752021610030
#include <REGX52.H>
// khai báo chân

#define LED1 P1_1
#define LED2 P1_2

// khai báo bi?n
int i;
// hàm tr?
void delay(){
	TMOD = 0x01;// timer 0 che do 16 bit che do 1
	TH0 = 0x3C;
	TL0 = 0xB0;// delay50ms 65536-50000
	TR0 = 1;	// bat timer chay
	while (!TF0);
	TF0 = 0;
	TR0 = 0;
}
// hàm chính
void main(){
	LED1=1;
	LED2=1;
	while(1){
		LED1=!LED1;
		LED2=!LED2;
		for(i=0;i<19;i++) delay();
	}
}
