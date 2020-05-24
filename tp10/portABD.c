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
#define SIZE_ERROR(n,port) ((port=='a'&&n>7)||(port=='A'&&n>7)||(port=='b'&&n>7)||(port=='B'&&n>7)||(port=='d'&&n>15)||(port=='D'&&n>15)||(n<0))


/*Estructura donde A y B son puertos de 8 bits cada uno y D es la union de    */
/*ambos. El puerto entero ocupa 16 bits*/
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
/*La funcion bitSet pone el bit "n" del puerto "port" en 1. Si no hubo error */
/*devuelve 0, si hubo error devuelve otra cosa. Revisa si el bit "n" es mayor*/
/*a la capacidad maxima del puerto y revisa que el puerto exista (mayuscula o*/
/*o minuscula). Recibe un int para el bit y un char para el puerto.          */
/*Ej: bitSet(0,'a'), bitSet(7,'D'). El llamado bitSet(8,'a') devuelve error  */
/*****************************************************************************/
int bitSet(int n,char port)
{
    uint_least8_t mask = 0x01;//mascara 00000001
    uint_least16_t mask1 = 0x0001;//el tamaño de las mascaras varia con el puerto
    int ans = 0;//errores en 0
  
    
    if(SIZE_ERROR(n,port))//revisa que el puerto y el bit sean coherentes
    {
        ans++;//hubo error
    }
    else
    {    
        switch(port)
        {
            case 'a':
            case 'A':
                mask<<=n;//coloca el "1" de la mascara en el bit n
                ports.portAB.portA|=mask;//OR bit a bit con la mascara
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
                ans++;//si el puerto no es ninguno de los anteriores hubo error
        }
    }
    return ans;   
}
/*****************************************************************************/
/*La funcion bitClr pone el bit "n" del puerto "port" en 0. Si no hubo error */
/*devuelve 0, si hubo error devuelve otra cosa. Revisa si el bit "n" es mayor*/
/*a la capacidad maxima del puerto y revisa que el puerto exista (mayuscula o*/
/*o minuscula). Recibe un int para el bit y un char para el puerto.          */
/*Ej: bitClr(0,'a'), bitClr(7,'D'). El llamado bitClr(8,'a') devuelve error  */
/*****************************************************************************/
int bitClr(int n,char port)
{
    uint_least8_t mask = 0xFE;//mascara 11111110
    uint_least16_t mask1 = 0xFFFE;//el tamaño de las mascaras varia con el puerto
    int ans = 0;//errores en 0
    if(SIZE_ERROR(n,port))//revisa que el puerto y el bit sean coherentes
    {
        ans++;//hubo error
    }
    else
    {
        switch(port)
        {
            case 'a':
            case 'A':
                for(int i = 1 ;i<n; i++)
                {
                    mask<<=1;//coloca el "0" de la mascara en el bit n
                    mask +=1;//como completa con 0 le agrego un uno cada vez
                }
                ports.portAB.portA&=mask;
                break;
            case 'b':
            case 'B':
                for(int i = 1;i<n;i++)
                {
                    mask<<=1;
                    mask +=1;
                }
                ports.portAB.portB&=mask;//AND bit a bit con mascara
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
/******************************************************************************/
/*La funcion bitGet devuelve el valor del bit "n".                            */
/*Si hubo error devuelve un numero negativo. Revisa si el bit "n" es mayor    */
/*a la capacidad maxima del puerto y revisa que el puerto exista (mayuscula o */
/*o minuscula). Recibe un int para el bit y un char para el puerto.           */
/*Ej: bitGet(0,'a'), bitGet(7,'D'). El llamado bitGet(8,'a') devuelve error   */
/******************************************************************************/
int bitGet(int n,char port)
{
    uint_least8_t mask=0x01;//mascara 00000001
    uint_least16_t mask1 = 0x0001;//el tamaño de las mascaras varia con el puerto
    int ans = 0;
    
    if(SIZE_ERROR(n,port))//revisa que el puerto y el bit sean coherentes 
    {                               
        ans--;//hubo error
    }
    else
    {
         switch(port)
        {
            case 'a':
            case 'A':
                mask<<=n;//acomodo el "1" en el bit "n"
                ans = (ports.portAB.portA&mask);//AND entre el puerto y la 
                break;  //mascara. Si habia un "1" en el bit-> ans = 2^n
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
    if(ans>0)
    {
        ans=1;
    }
    return ans; //ans<0 -> error | ans>0 -> encendido | ans == 0 -> apagado.
}
/******************************************************************************/
/*La funcion bitToggle invierte el valor del bit "n" del puero "port".        */
/*Si hubo error devuelve un numero distinto a 0. Revisa si el bit "n" es mayor*/
/*a la capacidad maxima del puerto y revisa que el puerto exista (mayuscula o */
/*o minuscula). Recibe un int para el bit y un char para el puerto.           */
/*Ej: bitToggle(0,'a'), bitToggle(7,'D'). El llamado bitToggle(8,'a') devuelve*/
/*error.                                                                      */
/******************************************************************************/
int bitToggle(int n,char port)
{
    uint_least8_t mask=0x01;//mascara 00000001
    uint_least16_t mask1 = 0x0001;
    int ans = 0;//errores en 0
    if(SIZE_ERROR(n,port))
    {
        ans++;//hubo error
    }
    else
    {
        switch(port)
        {
            case 'a':
            case 'A':
                mask<<=n;//acomodo el "1" en el bit "n"
                ports.portAB.portA^=mask;//Exclusive-OR entre mascara y puerto
                break;
            case 'b':
            case 'B':
                mask<<=n;
                ports.portAB.portB^=mask;
                break;
            case 'd':
            case 'D':
                mask1<<=n;
                ports.portD ^= mask1;
                break;
            default: 
                ans++;
        }
    }
    return ans;
}
/******************************************************************************/
int maskOn (uint16_t msk,char port)
{
	int ans=0;

	if ((msk>0xff)&&((port=='a')||(port=='b')||(port=='A')||(port=='B')))
	{
		++ans;
	}
	else
	{
		if ((port=='b')||(port=='B'))
		{
			msk=msk<<8;
		}
		switch (port)
		{
			case 'a':
			case 'A':
			case 'b':
			case 'B':
			case 'd':
			case 'D':
			{
				ports.portD|=msk;
				break;
			}
			default:
			{	
				++ans;
			}
		}
	}
	return ans;
}
/******************************************************************************/
int maskOff (uint16_t msk, char port)
{
	int ans=0;
	if ((msk>0xff)&&((port=='a')||(port=='b')||(port=='A')||(port=='B')))
	{
		++ans;
	}
	else
	{
		if ((port=='b')||(port=='B'))
		{
			msk=msk<<8;
		}
		msk=~msk;
		switch (port)
		{
			case 'a':
			case 'A':
			case 'b':
			case 'B':
			case 'd':
			case 'D':
			{
				ports.portD&=msk;
				break;
			}
			default:
			{	
				++ans;
			}
		}
	}
	return ans;

}
/*****************************************************************************/	
int maskToggle (uint16_t msk,char port)
{
	int ans=0;

	if ((msk>0xff)&&((port=='a')||(port=='b')||(port=='A')||(port=='B')))
	{
		++ans;
	}
	else
	{
		if ((port=='b')||(port=='B'))
		{
			msk=msk<<8;
		}
		switch (port)
		{
			case 'a':
			case 'A':
			case 'b':
			case 'B':
			case 'd':
			case 'D':
			{
				ports.portD^=msk;
				break;
			}
			default:
			{	
				++ans;
			}
		}
	}
	return ans;
}

