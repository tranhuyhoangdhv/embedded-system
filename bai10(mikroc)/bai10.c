//TRAN HUY HOANG 205752021610030
sbit LCD_RS at P2_0_bit;
sbit LCD_EN at P2_1_bit;
sbit LCD_D4 at P2_2_bit;
sbit LCD_D5 at P2_3_bit;
sbit LCD_D6 at P2_4_bit;
sbit LCD_D7 at P2_5_bit;

void main() {
 P0 = 0xFF;
 P3 = 0xFF;
 IE = 0x81;
 Lcd_Init();
 Lcd_Cmd(_LCD_CLEAR);
 Lcd_Cmd(_LCD_CURSOR_OFF);
 Lcd_Out(1, 1, " tran huy hoang");
 Lcd_Out(2, 1, " 205752021610030");
 while(1);
 }
 
