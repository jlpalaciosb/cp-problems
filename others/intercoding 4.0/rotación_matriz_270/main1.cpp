#include <iostream>

using namespace std;

int main() {
	int n, m;
	cout << "Numero de filas = ";
	cin >> m;
	cout << "Numero de columnas = ";
	cin >> n;

	int matriz[m][n];
	int dos_setenta[n][m];

	for(int i = 0; i < m; ++i) {
		for(int j = 0; j < n; ++j) {
			cin >> matriz[i][j];
		}
	}

	int f = 0, c;
	for(int j = 0; j < n; ++j) {
		c = 0;
		for(int i = m - 1; i >= 0; --i) {
			dos_setenta[f][c] = matriz[i][j];
			++c;
		}
		++f;
	}

	cout << endl;

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			cout << dos_setenta[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}
