#include <stdio.h>
#include <malloc.h>
#include "matriz.h"

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
