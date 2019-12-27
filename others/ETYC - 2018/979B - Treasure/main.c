#include <stdio.h>
#include <string.h>

int max_beauty(char* cadena, int l, int nt);

int main(int argc, char const *argv[])
{
	int nt;
	scanf("%d", &nt); getchar();

	char cadena[100000];

	scanf("%[^\n]", cadena); getchar();
	int l = strlen(cadena);
	int b_kuro = max_beauty(cadena, l, nt);

	scanf("%[^\n]", cadena); getchar();
	int b_shiro = max_beauty(cadena, l, nt);

	scanf("%[^\n]", cadena); getchar();
	int b_katie = max_beauty(cadena, l, nt);

	char* ganador = "Kuro";
	int mayor = b_kuro;
	if (b_shiro > mayor) {
		ganador = "Shiro";
		mayor = b_shiro;
	}
	if (b_katie > mayor)
	{
		ganador = "Katie";
		mayor = b_katie;
	}

	int c=0;
	if(b_kuro == mayor) c++;
	if(b_shiro == mayor) c++;
	if(b_katie == mayor) c++;

	if(c > 1)
		printf("Draw\n");
	else
		printf("%s\n", ganador);

	return 0;
}

int max_beauty(char* cadena, int l, int nt) {
	int count[200];
	for (int i = 0; i < 200; ++i) {
		count[i] = 0;
	}
	for (int i = 0; i < l; ++i) {
		count[(int)cadena[i]]++;
	}
	int mayor = 0;
	for (int i = 0; i < 200; ++i) {
		if(count[i] > mayor) {
			mayor = count[i];
		}
	}

	if(nt == 1 && mayor == l)
		return l-1;
	
	if(mayor + nt > l)
		return l;
	else
		return mayor + nt;
}
