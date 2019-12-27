#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define max(x,y) ((x) >= (y)) ? (x) : (y)

int results[999][999];

void initResults(int n) {
	int i, j;
	for(i=0; i<n; i++)
		for(j=i+1; j<n; j++)
			results[i][j] = -1;
}

int lps(char* cadena, int i, int f) {
	if(i>f)
		return 0;
	if (results[i][f] != -1)
	{
		return results[i][f];
	}
	if(cadena[i] == cadena[f]) {
		results[i][f] = lps(cadena, i+1, f-1) + 2;
		return results[i][f];
	} else {
		results[i][f] = max(lps(cadena, i, f-1), lps(cadena, i+1, f));
		return results[i][f];
	}
}

int main(int argc, char const *argv[]) {
	char cadena[1000];
	
	int t;
	scanf("%d", &t);getchar();

	int i, n, j;

	for (i = 0; i < 999; ++i)
		results[i][i] = 1;

	for (i = 0; i < t; ++i) {
		cadena[0] = '\0';
		scanf("%[^\n]", cadena); getchar();
		n = strlen(cadena);

		if (n == 0) {
			printf("0\n");
			continue;
		}

		initResults(n);

		printf("%d\n", lps(cadena, 0, n-1));
	}

	return 0;
}
