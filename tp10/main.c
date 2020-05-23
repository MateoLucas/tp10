/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: mateo
 *
 * Created on May 19, 2020, 1:38 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "portABD.h"

/*
 * 
 */
typedef union
{
    struct portAB
    {
    uint_least8_t portA;
    uint_least8_t portB;
    }portAB;
    uint_least16_t portD;
}portABD_t;
extern portABD_t ports;

int main() 
{
    ports.portD = 0xF000;
    printf("PORTD %x\n",ports.portD);
    printf("%x\n",ports.portD);
    int a=bitSet(3,'b');
    printf("ERRORS %d\n",a);
    printf("PORTD %x\n",ports.portD);
    printf("PORTA %x\n",ports.portAB.portA);
    printf("PORTB %x\n",ports.portAB.portB);
        
   
    return (EXIT_SUCCESS);
}
