#include <stdio.h>
#include <stdlib.h>
#define NRO_VERTICES 6
#define NRO_ARISTAS 10

struct arista {
	int v1;
	int v2;
	int costo;	
};
typedef struct arista Arista;
int cmp_aristas(const void *a1, const void *a2) {
	int c1 = ((Arista*)a1)->costo;
	int c2 = ((Arista*)a2)->costo;
	if(c1 < c2) return -1;
	else if(c1 > c2) return 1;
	else return 0;
}

Arista arista(int v1, int v2, int costo) {
	Arista ret;
	ret.v1 = v1; ret.v2 = v2; ret.costo = costo;
	return ret;
}

int bosque[NRO_VERTICES]; //el índice representa el vértice, el contenido representa el bosque al que pertenece el vértice

void merge(int b1, int b2) {
	for (int i = 0; i < NRO_VERTICES; ++i)
		if (bosque[i] == b2)
			bosque[i] = b1;
}

int main(int argc, char const *argv[])
{
	Arista aristas[NRO_ARISTAS];
	aristas[0] = arista(5, 0, 2);
	aristas[1] = arista(3, 4, 4);
	aristas[2] = arista(0, 2, 3);
	aristas[3] = arista(3, 1, 2);
	aristas[4] = arista(2, 3, 1);
	aristas[5] = arista(2, 4, 4);
	aristas[6] = arista(4, 1, 4);
	aristas[7] = arista(0, 1, 2);
	aristas[8] = arista(0, 3, 2);
	aristas[9] = arista(1, 2, 5);

	for (int i = 0; i < NRO_VERTICES; ++i)
		bosque[i] = i;

	qsort(aristas, NRO_ARISTAS, sizeof(Arista), cmp_aristas);

	//O(m*n), se puede mejorar
	for (int i = 0; i < NRO_ARISTAS; ++i) {
		if (bosque[aristas[i].v1] != bosque[aristas[i].v2]) {
			merge(bosque[aristas[i].v1], bosque[aristas[i].v2]);
			printf("%d %d %d\n", aristas[i].v1, aristas[i].v2, aristas[i].costo);
		}
	}
	
	return 0;
}