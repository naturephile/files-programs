#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int size(FILE *fp)
{
//char ch;
int c=0;
//while((ch=fgetc(fp))!=-1)
//c++;
fseek(fp,0,SEEK_END);
c=ftell(fp);
rewind(fp);
return c;
}

void main(int argc,char **argv)
{
int i,j,l,ch,c;
char *s,*ss;
FILE *fp;

if(argc!=3)
{
printf("\nargument missing.\nUsage: ./a.out filename word\n");
return;
}

fp=fopen(argv[1],"r+");

if(fp==0)
{
printf("file is not present.\n");
return;
}

c=size(fp);
s=malloc(c+1);
ss=malloc(c+1);
//printf("c=%d\n",c);
i=0;
while( (fgets(s,c,fp)) )
{
	if(strstr(s,argv[2]))
	{
		fseek(fp,-1,SEEK_CUR);	
		//	printf("\ns=%s\n",s);
		strcpy(ss,s);
		l=strlen(ss);
		//		printf("l=%d",l);
		for(j=0,i=l-1;i>=0;i--)
		{
			ss[j++]=s[i];
		}
		//		ss[j]='\n';
		//printf("\nss=%s\n",ss);
		fseek(fp,-l,SEEK_CUR);	
		fputs(ss,fp);
	}
/*	else
	{
	 printf("Word not found in entered file.\n");
	return;
	}*/
}
}
