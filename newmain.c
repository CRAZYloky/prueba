/*
 * File:   newmain.c
 * Author: admin
 *
 * Created on 12 de abril de 2021, 07:02 PM
 */


#include <xc.h>
#define _XTAL_FREQ 80000000


 int num[10]={0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};
 int min = 0;
 int seg = 0;
 int dseg = 0;

 
 void timer0(void){
 INTCONbits.GIE = 0;  // desabilita las interuocciones globales
    T0CONbits.T0CS = 0;  //  selecion el reloj de trabajo 0 el itnerno 
    T0CONbits.PSA = 0;   // declara el presclaer si va tener o no  0 va a tner y se pone en el sigiente bit
    T0CONbits.T0PS = 0b001; // evuala el preescale de 1:4
    T0CONbits.T08BIT = 0; // determina si el timer 0 funcia a 8 o 16 bits 0= a 16 bits
    T0CONbits.TMR0ON = 1; // habilita y pone en marcha el tiemr 0 
    INTCONbits.TMR0IF = 0; // no se ha producido interupccion por desbordamiento 
    INTCONbits.TMR0IE = 1; // bit de permiso de interupccion de timer0  1 = habilitado
    INTCONbits.PEIE = 1;  // habilita interuccion perifericas con 0desabilita
    INTCONbits.GIE = 1;  //hablita las interuocciones globales
 }
int main(void) {
    ADCON1bits.PCFG=0XFF;
    TRISD = 0x00;
    PORTD = 0x00;
    TRISC = 0;
    PORTC = 0;
    timer0();
    TMR0H=(3034)>>8;
    TMR0L=3034;
    
    while (1) {
           
            
            
            if(INTCONbits.TMR0IF && INTCONbits.TMR0IE){
                
                PORTD=num[seg];
                
                
                INTCONbits.TMR0IF = 0;
            }
        }
    
    return 1;
}


void __interrupt () ISR_TIMER0(void){
    seg++;
}
