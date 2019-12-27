#include <iostream>
#include <cmath>
using namespace std;

int mat[10][300], good[10000];

void construct() {
	good[0] = good[1] = 1;
	int gi = 2;

	mat[0][0] = 1;
	for (int i = 1; i <= 8; i++) {
		int b = pow(3, i);
		while (gi <= b) good[gi++] = b;
		
		mat[i][0] = b;
		int c = 1;
		for (int j = 0; j < i; ++j) {
			int len = pow(2, j);
			for (int k = 0; k < len; ++k) {
				int g = b + mat[j][k];
				mat[i][c++] = g;
				while (gi <= g) good[gi++] = g;
			}
		}
	}
}

int main() {
	construct();
	int q; cin >> q;
	while (q--) {
		int n; cin >> n;
		if (n > 9841) {
			cout << 19683 << endl;
		} else {
			cout << good[n] << endl;
		}
	}
	return 0;
}
