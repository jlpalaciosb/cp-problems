#include <stdio.h>

int main() {
	char palabra[100];

	FILE* f = fopen("text.txt", "r");

	int c = 0;

	while(fscanf(f, "%s", palabra) != EOF) {
		c++;
	}
	
	printf("Hay %d palabras\n", c);

	return 0;
}
