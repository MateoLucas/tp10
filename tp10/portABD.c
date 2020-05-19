/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdint.h>
typedef struct
{
    uint_least8_t b0    :1;
    uint_least8_t b1    :1;
    uint_least8_t b2    :1;
    uint_least8_t b3    :1;       
    uint_least8_t b4    :1;
    uint_least8_t b5    :1;
    uint_least8_t b6    :1;
    uint_least8_t b7    :1;
}bit8_t;

typedef struct
{
    uint_least16_t b0    :1;
    uint_least16_t b1    :1;
    uint_least16_t b2    :1;
    uint_least16_t b3    :1;       
    uint_least16_t b4    :1;
    uint_least16_t b5    :1;
    uint_least16_t b6    :1;
    uint_least16_t b7    :1;
    uint_least16_t b8    :1;
    uint_least16_t b9    :1;
    uint_least16_t b10   :1;
    uint_least16_t b11   :1;       
    uint_least16_t b12   :1;
    uint_least16_t b13   :1;
    uint_least16_t b14   :1;
    uint_least16_t b15   :1;
    
}bit16_t;

typedef union
{
    bit8_t portA;
    bit8_t portB;
    bit16_t portD;
}portABD_t;

int bitSet(int n)
{
    
}