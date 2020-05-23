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
#define SIZE_ERROR(n,port) ((port=='a'&&n>7)||(port=='A'&&n>7)||(port=='b'&&n>7)||(port=='B'&&n>7)||(port=='d'&&n>15)||(port=='D'&&n>15))

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
    uint_least8_t mask = 0x1;
    int ans = 0;
    for(int i = 1;i<n;i++)
    {
        mask<<=1;
    }
    if(SIZE_ERROR(n,port))
    {
        ans++;
    }
    else
    {    
        switch(port)
        {
            case 'a':
            case 'A':
                ports.portAB.portA|=mask;
                break;
            case 'b':
            case 'B':
                ports.portAB.portB|=mask;
                break;
            case 'd':
            case 'D':
            
                (uint_least16_t)mask;
                mask=0x01;
                for(int i = 1;i<n;i++)
                {
                    mask<<=1;
                }
                ports.portD |= mask;
                break;
            default: 
                ans++;
        }
    }
    return ans;   
}
/******************************************************************************/
int bitClr(int n,char port)
{
    int mask;
    int ans = 0;
    if(SIZE_ERROR(n,port))
    {
        ans++;
    }
    else
    {
        switch(port)
        {
            case 'a':
            case 'A':
                mask=0xE;
                for(int i = 1;i<n;i++)
                {
                    mask<<=1;
                    mask +=1;
                }
                ports.portAB.portA=(ports.portAB.portA|mask);
                break;
            case 'b':
            case 'B':
                mask=0xE;
                for(int i = 1;i<n;i++)
                {
                    mask<<=1;
                    mask +=1;
                }
                ports.portAB.portB|=mask;
                break;
            case 'd':
            case 'D':
            
                (uint_least16_t)mask;
                mask=0xFE;
                for(int i = 1;i<n;i++)
                {
                    mask<<=1;
                    mask +=1;
                }
                ports.portD &= mask;
                break;
            default: 
                ans++;
        }
    }
    return ans;  
}
/*****************************************************************************/
int bitGet(int n,char port)
{
    uint_least8_t mask=0x1,ans = 0;
    for(int i = 1;i<n;i++)//acomodo la mascara
    {
        mask<<=1;
    }
   
    
    if(SIZE_ERROR(n,port))//me aseguro que el numero de bit este contenido en el QUE PASA SI sizeof(void*pPort) 
    {                               //puerto.
        ans--;
    }
    else
    {
         switch(port)
        {
            case 'a':
            case 'A':
                ans = (ports.portAB.portA&mask);
                break;
            case 'b':
            case 'B':
                ans=(ports.portAB.portB&mask);
                break;
            case 'd':
            case 'D':
                (uint_least16_t)mask;
                mask=0x01;
                for(int i = 1;i<n;i++)
                {
                    mask<<=1;
                }
                ans = ports.portD&mask;
                break;
            default: 
                ans--;
            
        }
    return ans; //ans<0 -> error | ans>0 -> encendido | ans == 0 -> apagado.
    }
}
/******************************************************************************/
int bitToggle(int n,char port)
{
    int mask;
    int ans = 0;
    if(SIZE_ERROR(n,port))
    {
        ans++;
    }
    else
    {
        switch(port)
        {
            case 'a':
            case 'A':
                mask=0xE;
                for(int i = 1;i<n;i++)
                {
                    mask<<=1;
                }
                ports.portAB.portA=(ports.portAB.portA^mask);
                break;
            case 'b':
            case 'B':
                mask=0xE;
                for(int i = 1;i<n;i++)
                {
                    mask<<=1;
                }
                ports.portAB.portB^=mask;
                break;
            case 'd':
            case 'D':
            
                (uint_least16_t)mask;
                mask=0xFE;
                for(int i = 1;i<n;i++)
                {
                    mask<<=1;
                }
                ports.portD ^= mask;
                break;
            default: 
                ans++;
        }
    }
    return ans;
}
