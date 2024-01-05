//TRAN HUY HOANG 205752021610030
sbit LCD_RS at P2_0_bit;
sbit LCD_EN at P2_1_bit;
sbit LCD_D4 at P2_2_bit;
sbit LCD_D5 at P2_3_bit;
sbit LCD_D6 at P2_4_bit;
sbit LCD_D7 at P2_5_bit;
unsigned int cnt=0;
bit tmp;
char *text="0000" ;

void External_ISR()org 0x0003 ilevel 0 {
 EA_bit = 0;
 tmp= 1; //
 EA_bit = 1;
}

void main() {
 tmp=0;
 P0 = 0xFF;
 P3 = 0xFF;
 IE = 0x81;
 Lcd_Init();
 Lcd_Cmd(_LCD_CLEAR);
 Lcd_Cmd(_LCD_CURSOR_OFF);
 Lcd_Out(1, 1, " counter exemple : ");
 Lcd_Out(2, 1, " design tran huy hoang");
 delay_ms(2000);
 Lcd_Cmd(_LCD_CLEAR);

 while(1){
 Lcd_Out(1, 1, "number counter: ");
 // Unending loop
 if(tmp)
 {
 cnt=cnt+1;
 P0=cnt;
 if(cnt==9)
 {  
 Lcd_Cmd(_LCD_CLEAR);
 Lcd_Out(2, 1, "return to 0");
 delay_ms(200);
 cnt=0;
 Lcd_Cmd(_LCD_CLEAR);
 }
 else{
    text[0] = cnt/1000 + 48;
   text[1] = (cnt/100)%10 + 48;
   text[2] = (cnt/10)%10 + 48;
   text[3] = cnt%10 + 48;
   Lcd_Out(2, 6, text);
   delay_ms(100);
 }
 tmp=0;
 }
 }
}