#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int size(FILE *fp)
{
char ch;
int c;
c=0;
while((fgetc(fp))!=-1)
c++;
return c;
}
////////////////////////////////////////////////
void main(int argc,char **argv)
{
int i,c,m;
char ch;
FILE *fp;

if(argc!=3)
{
printf("Missing operand.\nUsage: ygrep pattern file\n");
return;
}

fp=fopen(argv[2],"r");

if(fp==0)
{
printf("ygrep: No such file found!!.\n");
return;
}

c=size(fp);
char s[c],ss[c];
rewind(fp);

while(fgets(s,c,fp))
{
	if(strstr(s,argv[1]))
	{
	printf("\e[1;31m%s\e[m",s); // need to work on colors.
		
	}
}
}
