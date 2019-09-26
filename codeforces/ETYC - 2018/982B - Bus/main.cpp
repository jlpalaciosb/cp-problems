#include <iostream>
#include <list>
#include <stdio.h>

using namespace std;

struct row {
	int pos;
	int width;
};
typedef struct row Row;

bool es_menor(const Row &r1, const Row &r2) {
   return r1.width < r2.width;
}

void flush() {
	char c;
	do {
		c = getchar();
	} while(c != '\n' && c != EOF);
}

int main() {
	int n;
	cin >> n; 

	list<Row> rows;

	for(int i = 1; i <= n; ++i) {
		Row r;
		r.pos = i;
		cin >> r.width;
		rows.push_back(r);
	}
	rows.sort(es_menor);

	list<Row>::iterator first_free = rows.begin();
	list<Row>::iterator last_occup;
	list<Row>::iterator aux;

	flush();

	for(int i = 0; i < 2 * n; ++i) {
		char p = getchar();
		if(p == '0') {
			cout << first_free->pos << ' ';
			last_occup = first_free;
			first_free++;
		} else {
			cout << last_occup->pos << ' ';
			aux = last_occup;
			if(last_occup != rows.begin()) {
				last_occup--;
			}
			rows.erase(aux); //eliminamos la fila llena
		}
	}

	return 0;
}
