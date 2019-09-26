#include <iostream>

using namespace std;

int main() {
	int n;
	cout << "Tamanho de la matriz : ";
	cin >> n;

	int matriz[n][n];

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			cin >> matriz[i][j];
		}
	}

	int col = -1;
	int max = 0;
	for(int j = 0; j < n; ++j) {
		int sum = 0;
		for(int i = 0; i < n; ++i) {
			sum += matriz[i][j];
		}
		cout << sum << "\t";
		if(sum > max) {
			max = sum;
			col = j + 1;
		}
	}
	cout << endl;
	
	cout << "Numero mayor es " << max << " y esta en columna " << col << endl;
	
	return 0;
}
