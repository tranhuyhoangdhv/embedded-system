#include <REGX52.H>

#define LED P0
int i;
void Delay_ms(int t){
	int x,y;
	for (x=0;x<t;x++){
		for (y=0;y<123;y++);
	}
}

void main(){
	while(1){
		LED=0xFE;	//1111 1110
		Delay_ms(1000);
		for(i=0;i=7;i++){
			LED = LED<<1; 
			LED +=1;
			Delay_ms(1000);
		}
		LED=0xFF;
		Delay_ms(1000);
	}
}