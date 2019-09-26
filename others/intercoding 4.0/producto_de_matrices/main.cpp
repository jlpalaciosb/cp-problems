#include <iostream>

using namespace std;

int main() {

	int m1, n1, m2, n2;

	cout << "Primera matriz" << endl;
	cout << "Número de filas : ";
	cin >> m1;
	cout << "Num columnas    : ";
	cin >> n1;
	cout << "Segunda matriz" << endl;
	cout << "Número de filas : ";
	cin >> m2;
	cout << "Num columnas    : ";
	cin >> n2;
	

	if(n1 != m2) {
		cout << "No se puede multiplicar" << endl;
		exit(0);
	}

	int mat1[m1][n1];
	int mat2[m2][n2];
	int pro[m1][n2];

	cout << "Primera matriz" << endl;
	for(int i = 0; i < m1; ++i) {
		for(int j = 0; j < n1; ++j) {
			cin >> mat1[i][j];
		}
	}

	cout << "Segunda matriz" << endl;
	for(int i = 0; i < m2; ++i) {
		for(int j = 0; j < n2; ++j) {
			cin >> mat2[i][j];
		}
	}

	for(int i = 0; i < m1; ++i) {
		for(int j = 0; j < n2; ++j) {
			int sum = 0;
			for(int k = 0; k < m2; k++) {
				sum += mat1[i][k] * mat2[k][j];
			}
			pro[i][j] = sum;
		}
	}

	cout << "Producto" << endl;
	for(int i = 0; i < m1; ++i) {
		for(int j = 0; j < n2; ++j) {
			cout << pro[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}
