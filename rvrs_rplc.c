//rev the word and replace it.

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main(int argc,char **argv)
{
FILE *fp;
int i,j,l;

char ch,s[20],ss[20];

if(argc!=3)
{
printf("argument misssing.\nUsage: ./a.out fname string.\n");
return;
}

fp=fopen(argv[1],"r+");

if(fp==0)
{
printf("file is not present.\n");
return;
}

strcpy(s,argv[2]);
l=strlen(s);

for(i=0,j=l-1;i<j;i++,j--)
{
ch=s[i];
s[i]=s[j];
s[j]=ch;
}
while(fscanf(fp,"%s",ss)!=-1)
{
	if(strcmp(argv[2],ss)==0)
	{
	fseek(fp,-l,SEEK_CUR);
	fprintf(fp,"%s",s);
	}
}
}
