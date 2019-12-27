#include <iostream>
using namespace std;

int main() {
	int n; cin >> n;
	
	int m[n][n];
	int c = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			m[i][j] = ++c;

	for (int s = 0; s < n; ++s) {
		int j = s;
		for (int i = 0; i < n; ++i) {
			if (j != s) printf(" ");
			printf("%d", m[i][j]);
			j = (j + 1) % n;
		}
		printf("\n");
	}

	return 0;
}
