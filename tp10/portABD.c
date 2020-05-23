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
portABD_t ports;


/*****************************************************************************/
int bitSet(int n,char port)
{
    uint_least8_t mask = 0x01;
    uint_least16_t mask1 = 0x0001;
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
                mask<<=n;
                ports.portAB.portA|=mask;
                break;
            case 'b':
            case 'B':
                mask<<=n;
                ports.portAB.portB|=mask;
                break;
            case 'd':
            case 'D':           
                mask1<<=n;
                ports.portD |= mask1;
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
    uint_least8_t mask = 0xFE;
    uint_least16_t mask1 = 0xFFFE;
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
                for(int i = 1;i<n;i++)
                {
                    mask<<=n;
                    mask +=n;
                }
                ports.portAB.portA=(ports.portAB.portA|mask);
                break;
            case 'b':
            case 'B':
                for(int i = 1;i<n;i++)
                {
                    mask<<=1;
                    mask +=1;
                }
                ports.portAB.portB|=mask;
                break;
            case 'd':
            case 'D':
                for(int i = 1;i<n;i++)
                {
                    mask1<<=1;
                    mask1 +=1;
                }
                ports.portD &= mask1;
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
    uint_least8_t mask=0x01;
    uint_least16_t mask1 = 0x0001;
    int ans = 0;
    
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
                mask<<=n;
                ans = (ports.portAB.portA&mask);
                break;
            case 'b':
            case 'B':
                mask<<=n;
                ans=(ports.portAB.portB&mask);
                break;
            case 'd':
            case 'D':
                mask1<<=n;
                ans = ports.portD&mask1;
                break;
            default: 
                ans--;
            
        }
    
    }
    return ans; //ans<0 -> error | ans>0 -> encendido | ans == 0 -> apagado.
}
/******************************************************************************/
int bitToggle(int n,char port)
{
    uint_least8_t mask=0xFE;
    uint_least16_t mask1 = 0xFFFE;
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
                for(int i = 1;i<n;i++)
                {
                    mask<<=1;
                    mask +=1;
                }
                ports.portAB.portA=(ports.portAB.portA^mask);
                break;
            case 'b':
            case 'B':
                for(int i = 1;i<n;i++)
                {
                    mask<<=1;
                    mask +=1;
                }
                ports.portAB.portB^=mask;
                break;
            case 'd':
            case 'D':
                for(int i = 1;i<n;i++)
                {
                    mask1<<=1;
                    mask1+=1;
                }
                ports.portD ^= mask1;
                break;
            default: 
                ans++;
        }
    }
    return ans;
}
