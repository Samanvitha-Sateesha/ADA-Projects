#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAX = 1024;

int fnHorspool(char string[], char pattern[],int []);
void fnGenShiftTable(char *,int []);

int main(void)
{
	char text[MAX];
	char pattern1[MAX];
	char pattern2[MAX];
	int shiftTable[MAX];
	int n=1000, m, i;
	
	FILE *f1, *f2;
	
	f1 = fopen("horspool_bc.txt", "a");
	f2 = fopen("horspool_wc.txt", "a");
	
	printf("Enter length of pattern: ");
	scanf("%d", &m);
	
	for(i=0; i<n; i++)
		text[i] = '1';
	
	for(i=0; i<m; i++)
		pattern1[i] = '0';
	
	pattern2[0] = '0';
	for(i=0; i<m; i++)
		pattern2[i] = '1';
	
	text[n] = pattern1[m] = pattern2[m] = '\0';
	
	fnGenShiftTable(pattern1,shiftTable);
	fprintf(f1, "%d %d\n", m, fnHorspool(text,pattern1,shiftTable));
	
	fnGenShiftTable(pattern2,shiftTable);
	fprintf(f2, "%d %d\n", m, fnHorspool(text,pattern2,shiftTable));
	
	fclose(f1);
	fclose(f2);
	
	return 0;
}

void fnGenShiftTable(char p[], int t[])
{
	int m, i, j;

	m = strlen(p);

	for(i=0; i<MAX; i++)
		t[i]=m;
	
	for(j=0; j<m-1; j++)
		t[p[j]] = m-1-j;
}

int fnHorspool(char s[],char p[],int t[])
{
	int i, n, m, k, count=0;

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
			return count;
		else
			i = i+t[s[i]];
	}

	return count;
}
