#include <stdio.h>
#include <string.h>
#include <malloc.h>

int** matriz;

void crearMatriz(int n);
void initMatriz(int n);
int lps(char* cadena, int i, int f);
int max(int a, int b);
void freeMatriz(int n);

int main(int argc, char const *argv[])
{
	char cadena[1000];
	int t;

	scanf("%d", &t);getchar();

	int i;
	for (i = 0; i < t; ++i)
	{
		cadena[0] = '\0';
		scanf("%[^\n]", cadena); getchar();
		if (strlen(cadena)==0)
		{
			printf("%d\n", 0); continue;
		}
		crearMatriz(strlen(cadena));
		initMatriz(strlen(cadena));
		printf("%d\n", lps(cadena, 0, strlen(cadena)-1));
		freeMatriz(strlen(cadena));
	}
	return 0;
}

void crearMatriz(int n) {
	matriz = (int**)malloc(sizeof(int*) * n);
	int i;
	for(i = 0; i < n; i++)
		matriz[i] = (int*)malloc(sizeof(int) * n);
}

void freeMatriz(int n) {
	int i;
	for(i = 0; i < n; i++)
		free(matriz[i]);
	free(matriz);
}

void initMatriz(int n) {
	int i, j;
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			if (i==j)
			{
				matriz[i][j] = 1;
				continue;
			}
			matriz[i][j] = -1;
		}
	}
}

int lps(char* cadena, int i, int f) {
	if(i>f)
		return 0;
	if (matriz[i][f] != -1)
	{
		return matriz[i][f];
	}
	if(cadena[i] == cadena[f]) {
		matriz[i][f] = lps(cadena, i+1, f-1) + 2;
		return matriz[i][f];
	} else {
		matriz[i][f] = max(lps(cadena, i, f-1),lps(cadena, i+1, f));
		return matriz[i][f];
	}
}

int max(int a, int b) {
	if (a>b)
	{
		return a;
	}
	return b;
}
