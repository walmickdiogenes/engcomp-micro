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

void configura_portas();
void inicializar_display();
void envia_char_display(char dado );
int varredura_teclado();
void controle_pan_tilt(int caso);
void servo_pan_display();
void servo_tilt_display();
void comando_display( int comando);
void local_display(int local);

void main() 
{
    configura_portas();
    inicializar_display();
    servo_pan_display();
    servo_tilt_display();
    int dado = 0;
    while(1)
    {
        dado = varredura_teclado();
        controle_pan_tilt(dado);
    }
}

void configura_portas()
{
    ADCON1 = 0x0F;
    TRISD = 0b00000000;
    TRISCbits.RC0 = 0;
    TRISCbits.RC1 = 0;
    TRISCbits.RC6 = 0;
    TRISCbits.RC7 = 0;
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
   
   LATD = 0b00111000; //Funtion Set
   E = 1;
   E = 0;
   __delay_ms(100);
   
   LATD = 0b00001110; //Display on/off control
   E = 1;
   E = 0;
   __delay_ms(100);
   
   LATD = 0b00000001; //Display Clear
   E = 1;
   E = 0;
   __delay_ms(100);
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
int varredura_teclado()
{
    C_1 = 1;
    C_2 = 0;
    C_3 = 0;
    if(L_1 == 1)
    {
        while(L_1 == 1)
        {
        }
        return 1;
    }
    else if(L_2 == 1)
    {
        while(L_2 == 1)
        {
        }
        return 4;
    }
    else if(L_3 == 1)
    {
        while(L_3 == 1)
        {
        }
        return 7;
    }
    else if(L_4 == 1)
    {
        while(L_4 == 1)
        {
        }
        return 10;
    }
    C_1 = 0;
    C_2 = 1;
    C_3 = 0;
    if(L_1 == 1)
    {
        while(L_1 == 1)
        {
        }
        return 2;
    }
    else if(L_2 == 1)
    {
        while(L_2 == 1)
        {
        }
        return 5;
    }
    else if(L_3 == 1)
    {
        while(L_3 == 1)
        {
        }
        return 8;
    }
    else if(L_4 == 1)
    {
        while(L_4 == 1)
        {
        }
        return 0;
    }
    C_1 = 0;
    C_2 = 0;
    C_3 = 1;
    if(L_1 == 1)
    {
        while(L_1 == 1)
        {
        }
        return 3;
    }
    else if(L_2 == 1)
    {
        while(L_2 == 1)
        {
        }
        return 6;
    }
    else if(L_3 == 1)
    {
        while(L_3 == 1)
        {
        }
        return 9;
    }
    else if(L_4 == 1)
    {
        while(L_4 == 1)
        {
        }
        return 11;
    }
    C_1 = 0;
    C_2 = 0;
    C_3 = 0;     
}
void controle_pan_tilt(int caso)
{
    if(caso == 1)
    {
        LATCbits.LATC6 = 0;
        LATCbits.LATC6 = 1;
        __delay_us(500);
        LATCbits.LATC6 = 0;
        
        local_display(0x8D);
        envia_char_display(' ');
        local_display(0x8E);
        envia_char_display('0');
        local_display(0x8F);
        envia_char_display('0');
    }
    if(caso == 4)
    {
        LATCbits.LATC6 = 0;
        LATCbits.LATC6 = 1;
        __delay_us(1000);
        LATCbits.LATC6 = 0;
        
        local_display(0x8D);
        envia_char_display(' ');
        local_display(0x8E);
        envia_char_display('4');
        local_display(0x8F);
        envia_char_display('5');
    }
    if(caso == 7)
    {
        LATCbits.LATC6 = 0;
        LATCbits.LATC6 = 1;
        __delay_us(1500);
        LATCbits.LATC6 = 0;
        local_display(0x8D);
        envia_char_display(' ');
        local_display(0x8E);
        envia_char_display('9');
        local_display(0x8F);
        envia_char_display('0');
    }
    if(caso == 10)
    {
        LATCbits.LATC6 = 0;
        LATCbits.LATC6 = 1;
        __delay_us(2500);
        LATCbits.LATC6 = 0;
        local_display(0x8D);
        envia_char_display('1');
        local_display(0x8E);
        envia_char_display('8');
        local_display(0x8F);
        envia_char_display('0');
    }
    if(caso == 3)
    {
        LATCbits.LATC7 = 0;
        LATCbits.LATC7 = 1;
        __delay_us(500);
        LATCbits.LATC7 = 0;
        
        local_display(0xCD);
        envia_char_display(' ');
        local_display(0xCE);
        envia_char_display('0');
        local_display(0xCF);
        envia_char_display('0');
    }
    if(caso == 6)
    {
        LATCbits.LATC7 = 0;
        LATCbits.LATC7 = 1;
        __delay_us(1000);
        LATCbits.LATC7 = 0;
        
        local_display(0xCD);
        envia_char_display(' ');
        local_display(0xCE);
        envia_char_display('4');
        local_display(0xCF);
        envia_char_display('5');
    }
    if(caso == 9)
    {
        LATCbits.LATC7 = 0;
        LATCbits.LATC7 = 1;
        __delay_us(1500);
        LATCbits.LATC7 = 0;
        
        local_display(0xCD);
        envia_char_display(' ');
        local_display(0xCE);
        envia_char_display('9');
        local_display(0xCF);
        envia_char_display('0');
    }
    if(caso == 11)
    {
        LATCbits.LATC7 = 0;
        LATCbits.LATC7 = 1;
        __delay_us(2500);
        LATCbits.LATC7 = 0;
        
        local_display(0xCD);
        envia_char_display('1');
        local_display(0xCE);
        envia_char_display('8');
        local_display(0xCF);
        envia_char_display('0');
    }    
}
void servo_pan_display()
{
    local_display(0x81);
    envia_char_display('M');
    local_display(0x82);
    envia_char_display('O');
    local_display(0x83);
    envia_char_display('T');
    local_display(0x84);
    envia_char_display('O');
    local_display(0x85);
    envia_char_display('R');
    local_display(0x86);
    envia_char_display(' ');
    local_display(0x87);
    envia_char_display('P');
    local_display(0x88);
    envia_char_display('A');
    local_display(0x89);
    envia_char_display('N');
    local_display(0x8A);
    envia_char_display(' ');
    local_display(0x8B);
    envia_char_display(':');
    local_display(0x8E);
    envia_char_display('0');
    local_display(0x8F);
    envia_char_display('0');
}
void servo_tilt_display()
{
    local_display(0xC1);
    envia_char_display('M');
    local_display(0xC2);
    envia_char_display('O');
    local_display(0xC3);
    envia_char_display('T');
    local_display(0xC4);
    envia_char_display('O');
    local_display(0xC5);
    envia_char_display('R');
    local_display(0xC6);
    envia_char_display(' ');
    local_display(0xC7);
    envia_char_display('T');
    local_display(0xC8);
    envia_char_display('I');
    local_display(0xC9);
    envia_char_display('L');
    local_display(0xCA);
    envia_char_display('T');
    local_display(0xCB);
    envia_char_display(' ');
    local_display(0xCC);
    envia_char_display(':');
    local_display(0xCE);
    envia_char_display('0');
    local_display(0xCF);
    envia_char_display('0');
}
void comando_display( int comando)
{
    E = 0;
    RS = 0;
    LATD = comando;
    E = 1;
    E = 0;
}
void local_display(int local)
{
    E = 0;
    RS = 0;
    LATD = local ;
    E = 1;
    E = 0;
    __delay_ms(1);
}
