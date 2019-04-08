#include <xc.h>
#define _XTAL_FREQ 8000000

void configura_portas();
void varredura_matrix();

void main() {
    configura_portas();
    while(1)
    {
        varredura_matrix();
    }
}

void configura_portas()
{
    ADCON1 = 0x0F;
    TRISD = 0b00000000;
    TRISB = 0b00000000;
    TRISC = 0b00000000;
}
void varredura_matrix()
{
    int i,j,m;
    int varredura[]=
    {
        0b00000001,
        0b00000010,
        0b00000100,
        0b00001000,
        0b00010000,
        0b00100000,
        0b01000000,
        0b10000000
    };
    int letra_A[]=
    {
        0b11111111,
        0b00000011,
        0b00000001,
        0b11001110,
        0b11001110,
        0b00000001,       
        0b00000011,
        0b11111111,
        
        0b11111111,
        0b00000011,
        0b00000001,
        0b11001110,
        0b11001110,
        0b00000001,       
        0b00000011,
        0b11111111,        
                
        0b11111111,
        0b00000011,
        0b00000001,
        0b11001110,
        0b11001110,
        0b00000001,       
        0b00000011,
        0b11111111,                
    };
    int letra_J[]=
    {
        0b11000011,
        0b10111101,
        0b01011010,
        0b01111110,
        0b01011010,
        0b01100110,
        0b10111101,
        0b11000011,
        
        0b11000011,
        0b10111101,
        0b01011010,
        0b01111110,
        0b01011010,
        0b01100110,
        0b10111101,
        0b11000011,
        
        0b11000011,
        0b10111101,
        0b01011010,
        0b01111110,
        0b01011010,
        0b01100110,
        0b10111101,
        0b11000011,
        
        
        
    
       
    };
    for(j=0;j<16;j++){
        for(m=0;m<10;m++){
            for (i=0;i<8;i++)
            {
                LATD = varredura[i];
                LATB = letra_J[i+j];
                LATC = letra_J[i+j];
                __delay_ms(1);
            } 
        }
        __delay_ms(15);
    }
}
