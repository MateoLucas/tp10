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

int main ()
{
	printf("Ingrese una tecla \n");
	int e,c,k;
	e=0;
	c=0;
	k=0;
	do
	{	
		printf("PORT A:");
		for (int i=7;i>=0;--i)
		{
			k=bitGet(i,'a');
			printf("%d",k);
		}
		printf("\n");
		c = getchar();
		clean_buffer(500);
		if (('0'<=c)&&(c<='7'))
		{
			c-='0';
			e=bitSet(c,'a');
		}
		else
		{
			switch (c)
			{
				
				case 't':
				{
					e=maskToggle(MSK,'a');
					break;
				}
				case 'c':
				{
					e=maskOff(MSK,'a');
					break;
				}
				case 's':
				{
					e=maskOn(MSK,'a');
					break;
				}
				default:
				{
					if (c!='q')
					{
						printf("Ingrese una tecla valida\n");
					}
				}
			}
		}
	}
	while (c!='q');
	printf("Programa finalizado\n");
	return 0;
}

