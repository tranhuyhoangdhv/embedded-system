#include <REG51.h>

unsigned char dem = 0;

void sendCharToUART(char ch) {
    SBUF = ch;  // G?i ký t? qua UART
    while (TI == 0);  // Ð?i cho d?n khi ký t? du?c g?i hoàn thành
    TI = 0;  // Ð?t l?i c? truy?n d? li?u
}

void sendStringToUART(unsigned char *s) {
    while (*s) {
        sendCharToUART(*s++);  // G?i chu?i qua UART
    }
}

void ngat() interrupt 0 {
    dem++;  // Tang bi?n d?m khi có ng?t x?y ra trên chân INT0
    if (dem == 9) {
        sendStringToUART("\b\b\b\b\b\b\b\btran huy hoang\r\n");  // Hi?n th? chu?i và xóa s? tru?c dó
        dem = 0;  // Reset bi?n d?m v? 0
    } else {
        sendCharToUART('\b');  // Di chuy?n con tr? v? tru?c m?t v? trí
        sendCharToUART(dem + '0');  // G?i s? l?n b?m qua UART
    }
}

void main() {
    EX0 = 1;  // B?t ng?t ngoài INT0
    IT0 = 1;  // Ng?t khi có c?nh xu?ng trên chân INT0
    EA = 1;   // B?t ng?t toàn c?c

    // C?u hình UART
    SCON = 0x50;
    TMOD = 0x20;
    TH1 = TL1 = 0xfd;
    TR1 = 1;

    while (1) {
        // Chuong trình chính không c?n th?c hi?n gì c?
    }
}
