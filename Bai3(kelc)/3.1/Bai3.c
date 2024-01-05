//TRẦN HUY HOÀNG K61 ĐẠI HỌC VINH 
//MSSV 205752021610030
#include <REGX52.H>
#define LED P3 //dinh nghia chan P3=LED

char so[]={0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};		// day 0-9

void main()
{
	LED=so[8];
}
