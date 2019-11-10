#include <stdio.h>
void bin_img_c(unsigned char *ptr, int w, int h)
{
	int x=0,a=100,c=0;
	int i,j;
	for(i=0;i < h ;i++)
		for(j=0;j < w ;j++)
		{
			c++;
			x = x + ptr[i*w+j];
		}
	x = x/c;
	for(i=0;i < h ;i++)
		for(j=0;j < w ;j++)
			if( ptr[w*i+j] < x )
				ptr[i*w+j]=0;
			else
				ptr[i*w+j]=255;	
}
