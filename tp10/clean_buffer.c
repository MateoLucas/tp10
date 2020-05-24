#include "clean_buffer.h"
#include <stdio.h>
#include <stdlib.h>

void clean_buffer (unsigned int a)
{
	int d,i;
	while (d!='\n'&&i<a)
	{
		d=getchar();
		i++;
	}
}
