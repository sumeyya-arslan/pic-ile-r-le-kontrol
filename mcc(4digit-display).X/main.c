#include "mcc_generated_files/mcc.h"
#include <xc.h>
#define Dgt1 LATCbits.LATC3
#define Dgt2 LATCbits.LATC4
#define DS   LATCbits.LATC6
#define STCP LATCbits.LATC5
#define SHCP LATCbits.LATC7

#define digit1button PORTBbits.RB7
#define digit2button PORTBbits.RB6
#define digit3button PORTBbits.RB5
#define digit4button PORTBbits.RB4

#define RelayControl LATCbits.LATC2 // RC2 pinine ba?l? röle kontrolü

unsigned char Digit[10] = { 0x03, 0x9F, 0X25, 0x0D, 0x99, 0x49, 0x41, 0x1F, 0x01, 0x09 };

void writeDigit(unsigned char digit) {
    unsigned char i;
    SHCP = 0;
    STCP = 0;

    for (i = 0; i < 8; i++) {
        DS = (digit >> i) & 0x01;
        SHCP = 1;
        SHCP = 0;
    }
    STCP = 1;
}

void displayNumber(unsigned int number1) {
    unsigned char d1, d2, d3, d4;

    d1 = number1 / 1000;
    number1 %= 1000;
    d2 = number1 / 100;
    number1 %= 100;
    d3 = number1 / 10;
    d4 = number1 % 10;

    Dgt1 = 1; // a1=digit1
    Dgt2 = 1;
    writeDigit(Digit[d1]);
    __delay_ms(5);

    Dgt1 = 0; // a2=digit2
    Dgt2 = 1;
    writeDigit(Digit[d2]);
    __delay_ms(5);

    Dgt1 = 1; // a3=digit3
    Dgt2 = 0;
    writeDigit(Digit[d3]);
    __delay_ms(5);

    Dgt1 = 0; // a4=digit4
    Dgt2 = 0;
    writeDigit(Digit[d4]);
    __delay_ms(5);
}

void relay_control(unsigned char state) {
    RelayControl = state; // Röle kontrolü
}

void main(void) {
    TRISC = 0x00; // PORTC as output
    PORTC = 0x00; // Initialize PORTC to 0

    while (1) {
        if (digit1button == 1) {
            relay_control(1); // Röle aç?k
            displayNumber(1111); // 9999'u göster
            

        } else if (digit2button == 0) {
            relay_control(0); // Röle kapal?
            displayNumber(0000); // 8888'i göster
           
        }
        
    }
}



