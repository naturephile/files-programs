///sort stringlengthwise in file..
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct rc
{
int r;
int c;
};

struct rc lengthy(FILE *fp)
{
	int c=0,c1=0,f=0;
	char ch;
	struct rc r1;

	while( (ch=fgetc(fp))!=-1 )
	{
		c++;
		if(ch=='\n')
		{
			f++;
			if(c>c1)
				c1=c;
			c=0;
		}
	}
	r1.r=f;
	r1.c=c1;
	return r1;
}
//////////////////////////////////////////////
void sort(char **p,struct rc c)
{
int i,j;
char t[100];
//struct rc c; 

	for(i=0;i<c.r-1;i++)
	{
		for(j=i+1;j<c.r;j++)
		{
			if( strlen(p[i])>strlen(p[j]) )
			{
				strcpy(t,p[i]);
				strcpy(p[i],p[j]);	
				strcpy(p[j],t);	
			}	
		}
	}
/*	for(i=0;i<c.r;i++)
	{
		printf("%s",p[i]);
	}*/	

}
//////////////////////////////////////////////
void main(int argc,char **argv)
{
	int sz,i,j,n,r=0;
	char ch,**p,t[100];
	FILE *fp;
	struct rc c;

	if(argc!=2)
	{
		printf("\nOperand missing.\n");
		return;
	}

	fp=fopen(argv[1],"r");

	if(fp==0)
	{
		printf("File is missing.\n");
		return;
	}

	c=lengthy(fp);
//	printf("r=%d\nc=%d\n",c.r,c.c);

	rewind(fp);

	fseek(fp,0,SEEK_END);
	sz=ftell(fp);
//	printf("wsize=%d\n",sz);

//	t=malloc(sizeof(char *)*c.c);

	p=malloc(sizeof(char *)*c.r);
	for(j=0;j<c.r;j++)
	{
		p[j]=malloc(sizeof(char)*c.c);
	}

	rewind(fp);
	
	char **q=p;
//	i=0;
//	while( fgets(p[i],c.c+1,fp) )
	while( fgets(*q,sz,fp) )
	{
//	i++;
	q++;
	}
/*
	for(i=0;i<c.r;i++)
		fgets(p[i],c.c+1,fp);*/

	for(i=0;i<c.r;i++)
	{
		printf("%s",p[i]);
	}	
/////////////////////////////////////////////////
printf("\n\n");
	
	sort(p,c);
	
////////////////////////////////////////////////
fp=fopen(argv[1],"w");

for(j=0;j<c.r;j++)
fputs(p[j],fp);

//while( fgets(*q,sz,fp) )
//fputs(*p,fp);
}
