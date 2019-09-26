#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#define N 5

using namespace std;

int main() {
	srand(time(NULL));
	vector<int> v(N);

	cout << "Cuantos elementos : " << N << endl;

	for(int i = 0; i < N; ++i) {
		v[i] = rand() % 100;
		cout << "Posicion " << i + 1 << " ==> " << v[i] << endl;
	}

	int e = v[rand() % N];
	cout << "Elemento a buscar = " << e << endl;

	for(int i = 0; i < N; ++i) {
		if(v[i] == e) {
			cout << "Posicion = " << i + 1 << endl;
			break;
		}
	}
	
	return 0;
}