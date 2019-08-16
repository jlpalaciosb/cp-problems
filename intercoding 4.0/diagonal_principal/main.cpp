#include <iostream>
#define N 4

using namespace std;

int main() {
	int matriz[N][N];

	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			cout << "Ingrese componente: ";
			cin >> matriz[i][j];
		}
	}

	for(int i = 0; i < N; ++i) {
		cout << matriz[i][i] << " ";
	}
	cout << endl;
	
	return 0;
}
