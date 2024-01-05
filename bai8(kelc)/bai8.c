#include <REG51.h>

unsigned char dem = 0;

void sendCharToUART(char ch) {
    SBUF = ch;  // G?i k� t? qua UART
    while (TI == 0);  // �?i cho d?n khi k� t? du?c g?i ho�n th�nh
    TI = 0;  // �?t l?i c? truy?n d? li?u
}

void sendStringToUART(unsigned char *s) {
    while (*s) {
        sendCharToUART(*s++);  // G?i chu?i qua UART
    }
}

void ngat() interrupt 0 {
    dem++;  // Tang bi?n d?m khi c� ng?t x?y ra tr�n ch�n INT0
    if (dem == 9) {
        sendStringToUART("\b\b\b\b\b\b\b\btran huy hoang\r\n");  // Hi?n th? chu?i v� x�a s? tru?c d�
        dem = 0;  // Reset bi?n d?m v? 0
    } else {
        sendCharToUART('\b');  // Di chuy?n con tr? v? tru?c m?t v? tr�
        sendCharToUART(dem + '0');  // G?i s? l?n b?m qua UART
    }
}

void main() {
    EX0 = 1;  // B?t ng?t ngo�i INT0
    IT0 = 1;  // Ng?t khi c� c?nh xu?ng tr�n ch�n INT0
    EA = 1;   // B?t ng?t to�n c?c

    // C?u h�nh UART
    SCON = 0x50;
    TMOD = 0x20;
    TH1 = TL1 = 0xfd;
    TR1 = 1;

    while (1) {
        // Chuong tr�nh ch�nh kh�ng c?n th?c hi?n g� c?
    }
}
