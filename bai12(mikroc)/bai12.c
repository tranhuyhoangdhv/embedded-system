//TRẦN HUY HOÀNG K61 ĐẠI HỌC VINH 
//MSSV 205752021610030
sbit LCD_RS at P2_0_bit;
sbit LCD_EN at P2_1_bit;
sbit LCD_D4 at P2_2_bit;
sbit LCD_D5 at P2_3_bit;
sbit LCD_D6 at P2_4_bit;
sbit LCD_D7 at P2_5_bit;

unsigned int A = 0;
void main() {
  P0 = 0xFF;
  P3 = 0xFF;
  IE = 0x81;
  Lcd_Init();
  Lcd_Cmd(_LCD_CLEAR);
  Lcd_Cmd(_LCD_CURSOR_OFF);

  while(1) {
    Lcd_Out(1, 1, "A=");

    if (A < 10) {
      Lcd_Chr(1, 3, A + 48);
    } else {
      Lcd_Chr(1, 3, (A / 10) + 48);
      Lcd_Chr(1, 4, (A % 10) + 48);
    }

    delay_ms(500);

    delay_ms(500);

    A++;

    if (A == 20) {
      Lcd_Cmd(_LCD_CLEAR);
      Lcd_Out(1, 1, "TRAN HUY HOANG");
      delay_ms(2000);

      A = 0;
      Lcd_Cmd(_LCD_CLEAR);
    }
  }
}
