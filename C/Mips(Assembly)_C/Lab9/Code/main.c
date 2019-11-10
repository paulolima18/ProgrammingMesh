#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//
// Protótipos da função de binarização
//
void bin_img_c(unsigned char *ptr, int w, int h);
void bin_img_asm(unsigned char *ptr, int w, int h);

//
// função para ler ficheiro de imagem pgm
//
unsigned char **readpgm(char *filename,int *width,int *height)
{
    unsigned char **p;
    unsigned char *data;
    int i,j,datasize,c;
    int typeno,maxvalue;
    char dumchar;
    FILE *fp;
    
    //fprintf(stderr,"readpgm: opening %s\n",filename);
    
    fp=fopen(filename,"rb"); /* 2nd parameter must be equal to "rb" in Windows! */
    if(!fp) {
	fprintf(stderr,"readpgm: error opening file\n");
	exit(0);
    }
    
    if(fscanf(fp,"P%d\n",&typeno)!=1) {
	fprintf(stderr,"readpgm: error reading typeno\n");
	exit(0);
    }
    
    //fprintf(stderr,"readpgm: ppm type P%d\n",typeno);
    
    while(fscanf(fp,"#%c",&dumchar)) {
	while(fscanf(fp,"%c",&dumchar),dumchar!='\n') printf("%c",dumchar);
	printf("\n");
    }
    
    if(fscanf(fp,"%d %d\n",width,height)!=2) {
	fprintf(stderr,"readpgm: error reading width,height\n");
	exit(0);
    }
    
    if(fscanf(fp,"%d",&maxvalue)!=1) {
	fprintf(stderr,"readpgm: error reading maxvalue\n");
	exit(0);
    }

/* fix 14.10.97: read newline separately to avoid skipping bytes of
   image data corresponding to form-feeds
*/
    fgetc(fp);

    //fprintf(stderr,"readpgm: w %d  h %d  mv %d\n",*width,*height,maxvalue);
    
    datasize=(*width)*(*height);
    
    switch(typeno) {

    case 5:        /*  rawbits pgm type */
	
	p=(unsigned char **)calloc((*height),sizeof(unsigned char *));
	if(!p) {
	    fprintf(stderr,"readppm: calloc error 1\n");
	    exit(0);
	}
	for(i=0;i<(*height);i++) {
	    p[i]=(unsigned char *)calloc((*width),sizeof(unsigned char));
	    if(!p[i]) {
		fprintf(stderr,"readppm: calloc error 2\n");
		exit(0);
	    }
	}
	data=(unsigned char *)calloc(datasize,sizeof(unsigned char));
	if(!data) {
	    fprintf(stderr,"readppm: calloc error 3\n");
	    exit(0);
	}
	if(fread(data,sizeof(unsigned char),datasize,fp)!=datasize) {
	    fprintf(stderr,"readppm: error reading data\n");
	    exit(0);
	}
	
	c=0;
	for(i=0;i<(*height);i++)
	    for(j=0;j<(*width);j++)
		p[i][j]=data[c++];
	
	free(data);
	break;
    default:
	fprintf(stderr,"readppm: sorry ppm type not implemented\n");
	exit(0);
    }

    fclose(fp);
    
    return p;
}

//
// função para escrever ficheiro de imagem pgm
//	
void writepgm(unsigned char **p, int width, int height, char *filename)
{
    unsigned char *data,*dp;
    int c,i,j,datasize,level;
    FILE *fp;

    if(!(fp=fopen(filename,"wb"))) { /* 2nd parameter must be equal to "rb" in Windows! */
	fprintf(stderr,"writepgm: error opening output file\n");
	exit(0);
    }
  
    fprintf(fp,"P5\n");
    
    fprintf(fp,"%d %d\n",width,height);
   
    fprintf(fp,"%d\n",255);
    
    datasize=width*height;

    
    if(!(data=(unsigned char *)calloc(sizeof(char),datasize))){
	fprintf(stderr,"writepgm: calloc error\n");
	exit(0);
    }
    
    dp=data;
    for(i=0;i<height;i++)
      for(j=0;j<width;j++){
	    *dp++=p[i][j];
      }
    if(!fwrite(data,sizeof(unsigned char),datasize,fp)) {
	fprintf(stderr,"writepgm: write error\n");
	exit(0);
    }
    
    free(data);

    fclose(fp);
}

//
// Programa de binarização de imagems pgm, que recebe o nome
// dos ficheiros pela linha de comando
//	
int main(int argc, char **argv){
  int height, width, i, j, datasize, n;
  unsigned char **imptr, *dp;
  clock_t T1,T2;

  imptr=readpgm(argv[1],&width,&height);
  
  datasize=width*height;
  if(!(dp=(unsigned char *)calloc(sizeof(char),datasize))){
	fprintf(stderr,"writepgm: calloc error\n");
	exit(0);
    }
  for (i=0;i<height;i++)
    for (j=0;j<width;j++)
      dp[i*width+j]=imptr[i][j];


 //ROTINA CRONOMETRADA
 T1=clock();
 for(n=0;n<25;n++){
	bin_img_c(dp, width, height);
//	bin_img_asm(dp, width, height);
 }
 T2=clock();
 printf("A sua rotina executou em %6.3f segundos.\n",(((double)(T2-T1))/CLOCKS_PER_SEC));

  for(i=0;i<height;i++)
      for(j=0;j<width;j++)
		  imptr[i][j]=dp[i*width+j];

  writepgm(imptr,width,height,argv[2]);
}
