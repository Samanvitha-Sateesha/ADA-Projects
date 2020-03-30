#include <stdio.h>
#include <string.h>

const int MAX = 256;
int count = 0;

int fnHorspool(char string[], char pattern[],int []);
void fnGenShiftTable(char *,int []);

int main(void)
{
	char text[MAX];
	char pattern[MAX];
    	int shiftTable[MAX];
	int found;
	puts("Enter the source string : ");
	scanf("%s", text);
	puts("Enter the pattern string : ");
	scanf("%s", pattern);
	
	fnGenShiftTable(pattern,shiftTable);
	found = fnHorspool(text,pattern,shiftTable);

	if(found==-1)
		puts("\nMatching Substring not found.\n");
	else
		printf("\nMatching Substring found at position: %d\n",found+1);
	
	printf("Basic operation count: %d\n",count);

	return 0;
}

/******************************************************************************
*Function	: fnGenShiftTable
*Description	: Function to generate the shift table
*Input parameters:
*	char p[] - pattern to be searched for
*	int t[]	- shift table containing shift values for each alphabet
*RETURNS	: no value
******************************************************************************/
void fnGenShiftTable(char p[], int t[])
{
	int m, i, j;

	m = strlen(p);

	for(i=0; i<MAX; i++)
		t[i]=m;
	
	for(j=0; j<m-1; j++)
		t[p[j]] = m-1-j;
}

/******************************************************************************
*Function	: fnHorspool
*Description	: Function to search for a matching substring for a given 
			pattern in the text
*Input parameters:
*	char s[] - text string
*	char p[] - pattern to be searched for
*	int t[]	- shift table containing shift values for each alphabet
*RETURNS	: no value
******************************************************************************/
int fnHorspool(char s[],char p[],int t[])
{
	int i, n, m, k;

	n = strlen(s);
	m = strlen(p);
	i = m-1;
	while(i<=n-1)
	{
		k = 0;
		count++;
		
		while((k<=m-1)&&(p[m-1-k]==s[i-k])) {
			k++;
			count++;
		}
		

		if (k == m)
			return i-m+1;
		else
			i = i+t[s[i]];
	}

	return -1;
}
