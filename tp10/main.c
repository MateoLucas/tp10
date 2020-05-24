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
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include "portABD.h"
#include"clean_buffer.h"
#define MSK 0xff
int main ()
{
	printf("Ingrese una tecla \n");
	int error=0,chr=0,bit=0;
	do
	{	
		printf("PORT A:");
		for (int i=7;i>=0;--i)
		{
			bit=bitGet(i,'a');
                        if(bit<0)
                        {
                            error++;
                        }
			printf("%d",bit);
		}
		printf("\n");
		chr = getchar();
		clean_buffer(500);
		if (('0'<=chr)&&(chr<='7'))
		{
			chr-='0';
			if(bitSet(chr,'a')!=0)
                        {
                            error++;
                        }
		}
		else
		{
			switch (chr)
			{
				
				case 't':
				{
					if(maskToggle(MSK,'a')!=0)
                                        {
                                            error++;
                                        }
					break;
				}
				case 'c':
				{
					if(maskOff(MSK,'a')!=0)
                                        {
                                            error++;
                                        }
					break;
				}
				case 's':
				{
					if(maskOn(MSK,'a')!=0)
                                        {
                                            error++;
                                        }
					break;
				}
				default:
				{
					if (chr!='q')
					{
						printf("Ingrese una tecla valida\n");
					}
				}
			}
		}
                if(error>0)
                {
                    printf("Se detectaron %d errores.\n",error);
                }
	}
	while (chr!='q');
	printf("Programa finalizado\n");
	return 0;
}

