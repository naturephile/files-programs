/// store data of < files >  in another file.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//////////////////
typedef struct rc
{
int r;
int c;
}RC;
//////////////////////////////
struct rc lengthy(FILE *fs)
{
int c=0,f=0,c1=0;
RC x;
char ch;
while( (ch=fgetc(fs))!=-1 )
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
x.r=f;
x.c=c1;
return x;
}

//////////////////////////////////////////////
void main(int argc,char **argv)
{
int i,j,k,c;
char **p,ch;
FILE *fp,*fs,*fd;
RC x;

if(argc!=2)
{
printf("\nMissing operands..\nUsage: ./a.out file\n");
return;
}

fs=fopen(argv[1],"r");

if(fs==0)
{
printf("error: asd: No such file or directory.\n");
return;
}

x=lengthy(fs);
printf("r=%d c=%d\n",x.r,x.c);
rewind(fs);

p=malloc(sizeof(char*)*x.r);
for(i=0;i<x.r;i++)
p[i]=malloc(sizeof(char)*x.c);

//fd=fopen(argv[2],"a");

i=0;
j=0;
while( (ch=fgetc(fs))!=-1 )
{
	if(ch=='<')
	{
		while((ch=fgetc(fs))!='>')
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

for(i=0;i<x.r;i++)
printf("%s\n",p[i]);

fclose(fs);
fd=fopen(argv[1],"w");
fclose(fd);
fd=fopen(argv[1],"a");

for(i=0;i<x.r;i++)
{
	if( fp=fopen(p[i],"r") )
	{
		while( (ch=fgetc(fp))!=-1 )
		fputc(ch,fd);
	}

	else
	{
	printf("err: No such file %s\n",p[i]);
	}
}
}
