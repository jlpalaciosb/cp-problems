#include <iostream>
#define N 7

using namespace std;

int main() {
	int matriz[N][N];

	for(int i = 0; i <N; ++i) {
		for(int j = 0; j <N; ++j) {
			matriz[i][j] = (i == j) ? 1 : 0;
		}
	}

	cout << "Matriz" << endl;
	for(int i = 0; i <N; ++i) {
		for(int j = 0; j <N; ++j) {
			cout << matriz[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}
