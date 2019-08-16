#include <stdio.h>
#define N 4

char ALFA[5] = {'A', 'B', 'C', 'D'}; //, 'E'}; //, 'F', 'G', 'H', 'I', 'J'};

void permutar(char lista[], int n);
void shift(char lista[], int n);
void imprimir_lista();

int main(int argc, char const *argv[]) {
	permutar(ALFA, N);
	return 0;
}

void permutar(char lista[], int n) {
	if (n == 1)	{
		for (int i = 0; i < N; ++i)
			printf("%c", ALFA[i]);
		printf("\n");
	} else {
		for (int i = 0; i < n; ++i) {
			permutar(lista+1, n-1);
			shift(lista, n);
		}
	}
}

void shift(char lista[], int n) {
	char p = lista[0];
	for (int i = 0; i < n-1; ++i)
		lista[i] = lista[i+1];
	lista[n-1] = p;
}
