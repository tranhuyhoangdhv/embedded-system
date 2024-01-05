//TRẦN HUY HOÀNG K61 ĐẠI HỌC VINH 
//MSSV 205752021610030
#include <REGX52.H>

#define B1 P1_0

#define LED P0

void Delay_ms(int t){
	int x,y;
	for (x=0;x<t;x++){
		for (y=0;y<123;y++);
	}
}

void main(){
	LED=0xFF;	//1111 1111
	while(1){
		if (B1==0){
			LED=~LED; 
			Delay_ms(1000);
		}
	}
}
