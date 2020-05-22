/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/*
 CONSIDERACIONES 
 * se indica al puerto A como 'A', al puerto B como 'B', y al puerto D como 'D'. 
 
 */
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
/*
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
static portABD_t ports;

/*****************************************************************************/
int bitSet(int n,char port)
{
    int mask,ans = 0;int * pPort;
    switch(port)
    {
        case 'A':
            (uint_least8_t*)pPort = ports.portAB.portA;
            (uint_least8_t)mask=0x1;break;
        case 'B':
            (uint_least8_t*)pPort = ports.portAB.portB;
            (uint_least8_t)mask=0x1;break;
        case 'D':
            (uint_least16_t*)pPort = ports.portD;
            (uint_least16_t)mask=0x1;break;
        default: 
            ans++;
    }
    if(sizeof(*pPort)>n)
    {
        ans++;
    }
    else
    {
        for(int i = 1;i<n;i++)
        {
        mask<<=1;
        }
        (*pPort) = (*pPort)|mask;
    }
    return ans;   
}
/******************************************************************************/
int bitClr(int n,char port)
{
    int mask,ans = 0;int * pPort;
    switch(port)
    {
        case 'a':
        case 'A':
            
            (uint_least8_t*)pPort = ports.portAB.portA;
            (uint_least8_t)mask=0xE;break;
        case 'b':
        case 'B':
            (uint_least8_t*)pPort = ports.portAB.portB;
            (uint_least8_t)mask=0xE;break;
        case 'd':
        case 'D':
            (uint_least16_t*)pPort = ports.portD;
            (uint_least16_t)mask=0xFE;break;
        default: 
            ans++-;
    }
    if(sizeof(*pPort)>n)
    {
        ans++;
    }
    else
    {
        for(int i = 1;i<n;i++)
        {
        mask<<=1;
        mask+=1;
        }
        (*pPort) = (*pPort)&mask;
    }
    return ans;   
}
/*****************************************************************************/
int bitGet(int n,char port)
{
    int mask,ans = 0;int * pPort;
    switch(port)
    {
        case 'A':
            (uint_least8_t*)pPort = ports.portAB.portA;
            (uint_least8_t)mask=0x1;break;
        case 'B':
            (uint_least8_t*)pPort = ports.portAB.portB;
            (uint_least8_t)mask=0x1;break;
        case 'D':
            (uint_least16_t*)pPort = ports.portD;
            (uint_least16_t)mask=0x1;break;
        default: 
            ans--;
    }
    if(sizeof(*pPort)>n)//me aseguro que el numero de bit este contenido en el QUE PASA SI sizeof(void*pPort) 
    {                               //puerto.
        ans--;
    }
    else
    {
        for(int i = 1;i<n;i++)//acomodo la mascara
        {
        mask<<=1;
        }
        ans = (*pPort)&mask;
    }
    return ans; //ans<0 -> error | ans>0 -> encendido | ans == 0 -> apagado.
}
/******************************************************************************/
int bitToggle(int n,char port)
{
    int mask,ans = 0;int * pPort;
    switch(port)
    {
        case 'A':
            (uint_least8_t*)pPort = ports.portAB.portA;
            (uint_least8_t)mask=0x1;break;
        case 'B':
            (uint_least8_t*)pPort = ports.portAB.portB;
            (uint_least8_t)mask=0x1;break;
        case 'D':
            (uint_least16_t*)pPort = ports.portD;
            (uint_least16_t)mask=0x1;break;
        default: 
            ans++;
    }  
    if(sizeof(*pPort)>n)
    {
        ans++;
    }
    if(ans == 0)
    {
        for(int i = 1;i<n;i++)
        {
        mask<<=1;
        }
        (*pPort)= (*pPort)^mask;
    }
    return ans;   
}
