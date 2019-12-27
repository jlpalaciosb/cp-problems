#include <iostream>

using namespace std;

int main() {
	int n, m;
	cin >> m;
	cin >> n;

	int matriz[m][n];
	int dos_setenta[n][m];

	cout << "Matriz original" << endl;
	for(int i = 0; i < m; ++i) {
		for(int j = 0; j < n; ++j) {
			cin >> matriz[i][j];
			cout << matriz[i][j] << " ";
			dos_setenta[j][m - i - 1] = matriz[i][j];
		}
		cout << endl;
	}

	cout << endl << "Matriz rotada" << endl;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			cout << dos_setenta[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}
