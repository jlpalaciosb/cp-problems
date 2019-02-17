#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

void minimo(int index, int m, int s);
void maximo(int index, int m, int s);
void initString(char* str, int n, char c);

char* result;

int main(int argc, char const *argv[])
{
	int m, s;
	scanf("%d%d", &m, &s);

	if (s == 0 || s > 9 * m)
	{
		printf("-1 -1\n");
		exit(0);
	}

	result = (char*)malloc(sizeof(char)*(m+1));
	initString(result, m, ' ');
	result[m] = '\0';

	minimo(0, m, s);

	printf("%s ", result);


	initString(result, m, ' ');
	result[m] = '\0';

	maximo(0, m, s);

	printf("%s\n", result);

	return 0;
}

void minimo(int index, int m, int s) {
	int i;
	if (index == strlen(result))
	{
		return;
	}
	for(i=index==0?1:0; i<=9; i++) {
		if(i+(m-1)*9 >= s) {
			result[index] = (char)((int)'0' + i);
			minimo(index+1, m-1, s-i);
			break;
		}
	}
}

void maximo(int index, int m, int s) {
	int i;
	if (index == strlen(result))
	{
		return;
	}
	for(i=9; i>=(index==0?1:0); i--) {
		if(i <= s) {
			result[index] = (char)((int)'0' + i);
			maximo(index+1, m-1, s-i);
			break;
		}
	}
}

void initString(char* str, int n, char c) {
	int i;
	for(i=0; i<n; i++)
		str[i] = c;
}
