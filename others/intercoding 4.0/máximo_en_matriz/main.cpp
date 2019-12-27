#include <iostream>

using namespace std;

int main() {
	int n = 3;

	int matriz[n][n];

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			cout << "Ingrese el numero:";
			cin >> matriz[i][j];
		}
	}

	int max = 0, maxf, maxc;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			if(matriz[i][j] > max) {
				max = matriz[i][j];
				maxf = i + 1;
				maxc = j + 1;
			}
		}
		cout << endl;
	}

	cout << "Numero mayor es : " << max << " y se encuentra en la fila " << maxf << " y columna " << maxc << endl;
	
	return 0;
}
