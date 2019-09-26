#include <string.h>
#include <iostream>
#include <unordered_map>

using namespace std;

typedef struct nodo_s { // OJO: estamos en C++, ver el unorder_map, este tiene tamaño variable, no usar malloc para asignaciones, usar new
	unordered_map<char, struct nodo_s*> hijos;
	bool fin;
	int ram;
} nodo;

typedef unordered_map<char, nodo*> MCN;
typedef MCN::iterator MCNit;

void insert(nodo* n, char* str, int i, int l);
void init(nodo *n);
void compute(nodo* n, int c);

long long sum;

int main() {
	int N;
	char palabra[1000001]; 
	while(scanf("%d", &N) != EOF) {
		nodo* raiz = new nodo;
		init(raiz);
		sum = 0;
		for (int i = 0; i < N; ++i) {
			getchar();
			scanf("%[^\n]", palabra);
			insert(raiz, palabra, 0, strlen(palabra));
		}
		compute(raiz, raiz->ram > 1 ? 0 : 1);
		printf("%.2f\n", ((double)sum / (double)N));
		free(raiz);
	}
	return 0;
}

void free_tree(nodo* n) {
	for(MCNit it = n->hijos.begin(); it != n->hijos.begin(); ++it) {
		free_tree(it->second);
	}
	delete n;
}

void insert(nodo* n, char* str, int i, int l) {
	if(i < l) {
		if(n->hijos.find(str[i]) == n->hijos.end()) {
			n->ram += 1;
			nodo* new_node = new nodo;
			init(new_node);
			n->hijos[str[i]] = new_node;
		}
		insert(n->hijos[str[i]], str, i + 1, l);
	} else {
		n->fin = true;
	}
}

void init(nodo *n) {
	n->fin = false;
	n->ram = 0;
	n->hijos = {};
}

void compute(nodo* n, int c) {
	if(n->fin) {
		sum += c;
	}
	if(n->fin || n->ram > 1) {
		++c;
	}
	for(MCNit it = n->hijos.begin(); it != n->hijos.end(); ++it) {
		compute(it->second, c);
	}
}
