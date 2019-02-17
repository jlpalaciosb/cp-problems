#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define max(x,y) ((x) >= (y)) ? (x) : (y)

/* Importados */
int** matriz(int m, int n) {
	int** ret;
	ret = (int**)malloc(sizeof(int*) * m);
	int i;
	for(i=0; i<m; i++)
		ret[i] = (int*)malloc(sizeof(int) * n);
	return ret;
}

void initMatriz(int** mat, int m, int n, int val) {
	int i, j;
	for(i=0; i<m; i++)
		for(j=0; j<n; j++)
			mat[i][j] = val;
}

void freeMatriz(int** mat, int m, int n) {
	int i;
	for(i=0; i<m; i++)
		free(mat[i]);
	free(mat);
}
/* Fin importados */

int lps(char* cadena, int i, int f, int** results) {
	if(i>f)
		return 0;
	if (results[i][f] != -1)
	{
		return results[i][f];
	}
	if(cadena[i] == cadena[f]) {
		results[i][f] = lps(cadena, i+1, f-1, results) + 2;
		return results[i][f];
	} else {
		results[i][f] = max(lps(cadena, i, f-1, results), lps(cadena, i+1, f, results));
		return results[i][f];
	}
}

int main(int argc, char const *argv[])
{
	char cadena[1000];
	int** results;
	
	int t;
	scanf("%d", &t);getchar();

	int i, n, j;
	for (i = 0; i < t; ++i) {
		cadena[0] = '\0';
		scanf("%[^\n]", cadena); getchar();
		n = strlen(cadena);

		if (n == 0) {
			printf("0\n");
			continue;
		}

		results = matriz(n, n);
		initMatriz(results, n, n, -1);

		for (j = 0; j < n; ++j)
			results[j][j] = 1;

		printf("%d\n", lps(cadena, 0, n-1, results));
		freeMatriz(results, n, n);
	}

	return 0;
}
