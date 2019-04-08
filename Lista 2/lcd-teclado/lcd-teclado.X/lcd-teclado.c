#include <xc.h>
#define _XTAL_FREQ 8000000
#define RS LATCbits.LATC0
#define E LATCbits.LATC1
#define C_1 LATBbits.LATB0
#define C_2 LATBbits.LATB1
#define C_3 LATBbits.LATB2
#define L_1 PORTBbits.RB3
#define L_2 PORTBbits.RB4
#define L_3 PORTBbits.RB5
#define L_4 PORTBbits.RB6

void Configura_Portas();
void inicializar_display();
void envia_char_display(char dado );
void envia_char_serial(char dado);
char recebe_char_serial();
char varredura_teclado();

void main(void)
{
    Configura_Portas();
    inicializar_display();
    char dado,carac;
    int x;
    while(1)
    {
        x = PORTCbits.RC7;
        if(x == 0)
      {
            carac = recebe_char_serial();
            envia_char_display(carac);
      } 
        dado = varredura_teclado(); 
        if(dado != 'x')
        {
        envia_char_serial(dado);
        }  
    }
}

void Configura_Portas()
{
    ADCON1 = 0x0F;
    TRISD = 0b00000000;
    TRISCbits.RC0 = 0;
    TRISCbits.RC1 = 0;
    TRISCbits.RC6 = 0;
    TRISCbits.RC7 = 1;
    TRISBbits.RB0 = 0;
    TRISBbits.RB1 = 0;
    TRISBbits.RB2 = 0;
    TRISBbits.RB3 = 1;
    TRISBbits.RB4 = 1;
    TRISBbits.RB5 = 1;
    TRISBbits.RB6 = 1;
}
void inicializar_display()
{
    __delay_ms(1000);
   E = 0;
   RS = 0;
   
   LATD = 0b00110000;
   E = 1;
   E = 0;
   __delay_ms(100);
   
   LATD = 0b00001110; 
   E = 1;
   E = 0;
   __delay_ms(100);
   
   LATD = 0b00000001; 
   E = 1;
   E = 0;
   __delay_ms(1);
}
void envia_char_display(char dado )
{
    E = 0;
    RS = 1;
    LATD = dado;
    E = 1;
    E = 0;
    __delay_ms(1);
}
void envia_char_serial(char dado)
{
    LATCbits.LATC6 = 1;
    __delay_us(833);
    LATCbits.LATC6 = 0;
    __delay_us(833);
    for(int i = 0;i<8;i++)
    {
        LATCbits.LATC6 = dado;
        dado = dado>>1;
        __delay_us(833);
    }
    LATCbits.LATC6 = 1;
    __delay_us(833);
}
char recebe_char_serial()
{
 int i,x,c;
    int j = 7;
    char invertido[8];
    char dado=0;
    
    __delay_us(416); 
    __delay_us(833); 
    for(i=0;i<8;i++)
    { 
        invertido[j]=PORTCbits.RC7;
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
char varredura_teclado()
{
    C_1 = 1;
    C_2 = 0;
    C_3 = 0;
    if(L_1 == 1)
    {
        while(L_1 == 1)
        {
        }
        return '1';
    }
    else if(L_2 == 1)
    {
        while(L_2 == 1)
        {
        }
        return '4';
    }
    else if(L_3 == 1)
    {
        while(L_3 == 1)
        {
        }
        return '7';
    }
    else if(L_4 == 1)
    {
        while(L_4 == 1)
        {
        }
        return '*';
    }
    C_1 = 0;
    C_2 = 1;
    C_3 = 0;
    if(L_1 == 1)
    {
        while(L_1 == 1)
        {
        }
        return '2';
    }
    else if(L_2 == 1)
    {
        while(L_2 == 1)
        {
        }
        return '5';
    }
    else if(L_3 == 1)
    {
        while(L_3 == 1)
        {
        }
        return '8';
    }
    else if(L_4 == 1)
    {
        while(L_4 == 1)
        {
        }
        return '0';
    }
    C_1 = 0;
    C_2 = 0;
    C_3 = 1;
    if(L_1 == 1)
    {
        while(L_1 == 1)
        {
        }
        return '3';
    }
    else if(L_2 == 1)
    {
        while(L_2 == 1)
        {
        }
        return '6';
    }
    else if(L_3 == 1)
    {
        while(L_3 == 1)
        {
        }
        return '9';
    }
    else if(L_4 == 1)
    {
        while(L_4 == 1)
        {
        }
        return '#';
    }
    C_1 = 0;
    C_2 = 0;
    C_3 = 0;
    return 'x';  
}