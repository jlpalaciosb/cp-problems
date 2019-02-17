#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct nodo_s {
	struct nodo_s * hijos[26];
	int fin;
	int ram;
} nodo;

void insert(nodo* n, char* str, int i, int l);
void init(nodo *n);
void compute(nodo* n, int c);

long long sum;

int main() {
	int N;
	char palabra[1000001]; 
	while(scanf("%d", &N) != EOF) {
		nodo* raiz;
		raiz = (nodo*)malloc(sizeof(nodo));
		init(raiz);
		sum = 0;
		for (int i = 0; i < N; ++i) {
			getchar();
			scanf("%[^\n]", palabra);
			insert(raiz, palabra, 0, strlen(palabra));
		}
		compute(raiz, raiz->ram > 1 ? 0 : 1);
		printf("%.2f\n", (double)sum / (double)N);
		free(raiz);
	}
	return 0;
}

void free_tree(nodo* n) {
	for(int i = 0; i < 26; ++i) {
		if(n->hijos[i] != NULL) {
			free_tree(n->hijos[i]);
		}
	}
	free(n);
}

void insert(nodo* n, char* str, int i, int l) {
	if(i < l) {
		if(n->hijos[str[i] - 'a'] == NULL) {
			n->ram += 1;
			n->hijos[str[i] - 'a'] = (nodo*)malloc(sizeof(nodo));
			init(n->hijos[str[i] - 'a']);
		}
		insert(n->hijos[str[i] - 'a'], str, i + 1, l);
	} else {
		n->fin = 1;
	}
}

void init(nodo *n) {
	n->fin = 0;
	n->ram = 0;
	for(int i = 0; i < 26; ++i) {
		n->hijos[i] = NULL;
	}
}

void compute(nodo* n, int c) {
	if(n != NULL) {
		if(n->fin) {
			sum += c;
		}
		if(n->fin || n->ram > 1) {
			++c;
		}
		for(int i = 0; i < 26; ++i) {
			if(n->hijos[i] != NULL) {
				compute(n->hijos[i], c);
			}
		}
	}
}