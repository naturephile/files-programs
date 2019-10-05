//
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
		if(ch=='<')
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
/////////////////////////////////////
void main(int argc,char **argv)
{
int sz,i,j,f=0;
char ch,**p,**t;
FILE *fp,*fs;
struct rc x;

if(argc!=2)
{
printf("Missing operand.\nUsage: ./a.out fname");
return;
}

fp=fopen(argv[1],"r+");

if(fp==0)
{
printf("\nFile not found.\n");
return;
}

x=lengthy(fp);
printf("r=%d c=%d\n",x.r,x.c);
rewind(fp);

//fseek(fp,0,SEEK_END);
//sz=ftell(fp);
//printf("sz=%d",sz);
//rewind(fp);

p=malloc(sizeof(char*)*x.r);
for(i=0;i<x.r;i++)
p[i]=malloc(sizeof(char)*x.c);


i=0;
j=0;
//fs=fopen(argv[2],"w");

while( (ch=fgetc(fp))!=-1 )
{
	if(ch=='<')
	{
		while( (ch=fgetc(fp))!='>')
		{
			p[i][j]=ch;
			j++;
		}

		if(ch=='>')
		{
			p[i][j]='\0';
			i++;
			j=0;

		}
	}
}

/*	if(ch=='>')
	{
	f=0;
	p[i][j]='\0';
	i++;
	j=0;
	}

	if(f==1)
	{
		
		p[i][j]=ch;
		j++;

	}
	
	if(ch=='<')
		{
			f=1;
		} */

for(i=0;i<x.r;i++)
printf("%s\n",p[i]);

} 
