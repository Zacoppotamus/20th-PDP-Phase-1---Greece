#include <stdio.h>
#include <stdlib.h>
#define MAX 1000000

int i, j;
FILE *fp;

unsigned char c[MAX+1];
int count[27], temp;
char charcount[27], chartemp;

int main(void)
{
	
	for (i=0; i<26; i++)
	{
		charcount[i] = (char)(i+97);
	}
	charcount[26]=' ';
	
	

	if ((fp = fopen("/Users/Zac/Desktop/C/PDP/friktoriesin.txt", "r")) == NULL)
	{
		fprintf(stderr, "Error opening file\n");
		exit(1);
	}

	while(fgets(c,MAX+1,fp))
	{
		for (i=0; c[i]!= '\0'; i++)
		{
			if (c[i]>=97 && c[i]<=122)
				count[c[i]-97]++;
			else if (c[i]==32)
				count[26]++;
				
		}
	}

	fclose(fp);

	if ((fp = fopen("/Users/Zac/Desktop/C/PDP/friktoriesout.txt", "w")) == NULL)
	{
		fprintf(stderr, "Error writing to file\n");
		exit(1);
	}

	for (j=26; j>0 ; j--)
	{
		for (i=1 ; i<=j ; i++)
		{
			if (count[i-1]<count[i])
			{
				temp=count[i-1];
				count[i-1]=count[i];
				count[i]=temp;
				chartemp=charcount[i-1];
				charcount[i-1]=charcount[i];
				charcount[i]=chartemp;
			}
		}
	}

	for (i=0;i<27;i++)
	{
		fprintf(fp,"%c, %d\n", charcount[i], count[i]);
		printf("%c, %d\n", charcount[i], count[i]);
	}

	fclose(fp);
	return 0;

}
