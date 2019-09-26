#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct row {
	int pos;
	int width;
};
typedef struct row Row;

struct nodo {
	Row *row;
	struct nodo *sgt;
	struct nodo *ant;
};
typedef struct nodo Nodo;

int cmpfunc (const void * a, const void * b) {
   return ( (*(Row*)a).width - (*(Row*)b).width );
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);getchar();
	Nodo* lista = NULL;

	Row rows[n];
	for (int i = 0; i < n; ++i) {
		rows[i].pos = i+1;
		scanf("%d", &(rows[i].width));getchar();
	}
	qsort(rows, n, sizeof(Row), cmpfunc);

	for (int i = n-1; i >= 0; --i) {
		Nodo* aux = (Nodo*)malloc(sizeof(Nodo));
		aux->row = &(rows[i]);
		aux->sgt = lista;
		aux->ant = NULL;
		if(lista != NULL) {
			lista->ant = aux;
		}
		lista = aux;
	}

	Nodo* first_free = lista;
	Nodo* last_occup = lista;

	char p;
	for (int i = 0; i < 2*n; ++i) {
		p = getchar();
		if (p == '0') {
			printf("%d ", first_free->row->pos);
			last_occup = first_free;
			first_free = first_free->sgt;
		} else {
			printf("%d ", last_occup->row->pos);
			if (last_occup->ant != NULL) {
				last_occup->ant->sgt = last_occup->sgt;
			}
			if (last_occup->sgt != NULL) {
				last_occup->sgt->ant = last_occup->ant;
			}
			last_occup = last_occup->ant;
		}
	}

	return 0;
}
