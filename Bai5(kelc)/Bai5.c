//TRẦN HUY HOÀNG K61 ĐẠI HỌC VINH 
//MSSV 205752021610030
#include <REGX52.H>

#define B1 P2_0
#define B2 P2_1
#define B3 P2_2

#define LED1 P0_0
#define LED2 P0_1
#define LED3 P0_2

void main(){
	LED1=1;
	LED2=1;
	LED3=1;
	while(1){
		if (B1==0){
			while(B1==0);  // doi B1 duoc nha ra
			LED1=!LED1;
		}
		if (B2==0){
			while(B2==0);
			LED2=!LED2;
		}
		if (B3==0){
			while(B3==0);
			LED3=!LED3;
		}
	}
}
