void bin_img(unsigned char *ptr, int w, int h, unsigned char limiar)
{
	int i,j;	
	for(i=0;i < h ;i++){
	for(j=0;j < w ;j++){
	if( ptr[w*i+j] < limiar)
	{
		ptr[w*i+j]=0;
	}
	else
	{
		ptr[w*i+j]=255;
	}
    }
}}
