#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main(int argc,char **argv)
{
int i,c;
char ch,s[50];
FILE *fp;

if(argc!=3)
{
	printf("Missing operand.\nUsage.: ./a.out file word\n");
return;
}

fp=fopen(argv[1],"r");

if(fp==0)
{
printf("File is not present.\n");
return;
}
c=0;
while(fscanf(fp,"%s",s)!=-1)
{
	if(strcmp(argv[2],s)==0)
	c++;
}

printf("\e[34m%s\e[m is \e[34m%d\e[m times present.\n",argv[2],c);
}
