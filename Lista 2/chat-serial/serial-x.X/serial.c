#include <xc.h>
#include <stdio.h>
#include<math.h>
#define _XTAL_FREQ 8000000
 
void envia_serial_pic(char dado);
void envia_serial_terminal(char dado);
char recebe_serial_terminal();
char recebe_serial_pic();
void portas();

void main()
{
    portas();
    char dado;
    LATCbits.LATC0 = 1;
    LATAbits.LA0 = 1;
    while(1)
    {
        dado = 0;
        if (PORTAbits.RA1 == 0)
        {
            dado = recebe_serial_terminal();   
            envia_serial_pic(dado);
        }
        dado = 0;
        if (PORTCbits.RC1 == 0)
        {
            dado = recebe_serial_pic();
            envia_serial_terminal(dado);
        }
    }
}

void envia_serial_pic(char dado)
{
    LATCbits.LATC0 = 1;
    __delay_us(833);
    LATCbits.LATC0 = 0;
    __delay_us(833);
    for(int i = 0;i<8;i++)
    {
        LATCbits.LATC0 = dado;
        dado = dado >> 1;
        __delay_us(833);
    }
    LATCbits.LATC0 = 1;
    __delay_us(833);
}
void envia_serial_terminal(char dado)
{
    LATAbits.LATA0 = 1;
    __delay_us(833);
    LATAbits.LATA0 = 0;
    __delay_us(833);
    for(int i = 0;i<8;i++)
    {
        LATAbits.LATA0 = dado;
        dado = dado>>1;
        __delay_us(833);
    }
    LATAbits.LATA0 = 1;
    __delay_us(833);
}
char recebe_serial_terminal()
{
    int i,x;
    int j = 7;
    char invertido[8];
    char dado=0;
    
    __delay_us(416); 
    __delay_us(833); 
    for(i=0;i<8;i++)
    { 
        invertido[j]=PORTAbits.RA1;
        j--;
        __delay_us(810);  
    }
    for(x=0;x<8;x++)
    {
        dado = dado <<1;
        dado = dado + invertido[x]; 
    }
    return dado;
}
char recebe_serial_pic()
{
 int i,x;
    int j = 7;
    char invertido[8];
    char dado=0;
    
    __delay_us(416); 
    __delay_us(833); 
    for(i=0;i<8;i++)
    { 
        invertido[j]=PORTCbits.RC1;
        j--;
        __delay_us(810);  
    }
    for(x=0;x<8;x++)
    {
        dado = dado <<1;
        dado = dado + invertido[x];    
    }
    return dado;
}
void portas()
{
    ADCON1 = 0x0F;
    TRISCbits.TRISC0 = 0;
    TRISCbits.TRISC1 = 1;
    TRISAbits.TRISA0 = 0;
    TRISAbits.TRISA1 = 1;
}