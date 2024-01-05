//TRẦN HUY HOÀNG K61 ĐẠI HỌC VINH 
//MSSV 205752021610030
#include <REGX52.H>

void UART_Init()
{
	TMOD = 0x20;  /* Timer 1, che do 2 tu nap lai*/
	TH1 = 0xFD;  // toc do truyen 9600 baud
	SM0=0;
	SM1=1;			//uart 
	TR1 = 1; 		//cho time chay
}

void one_char(char Data)
{
	SBUF = Data;				//truyen 1 ky tu
	while (TI==0); 		//doi truyen xong
	TI = 0;  					//xoa co ti
}

void String(char *str)
{
	int i;
	for(i=0;str[i]!=0;i++) //truyen den khi het chuoi ky tu
	{
		one_char(str[i]); 
	}
} 

void main()
{
	UART_Init();  
	String("PROTEUS");  
	while(1);
}
