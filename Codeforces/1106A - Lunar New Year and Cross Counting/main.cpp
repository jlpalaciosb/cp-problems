#include <iostream>
#define MAX_N 500

using namespace std;

int cm[MAX_N][MAX_N], n;

void inc(int i, int j) {
	if(0 <= i && i < n && 0 <= j && j < n) cm[i][j] += 1;
}

int main() {
	scanf("%d\n", &n);

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			char c = getchar();
			if(c == 'X') {
				inc(i, j);
				inc(i - 1, j - 1);
				inc(i - 1, j + 1);
				inc(i + 1, j - 1);
				inc(i + 1, j + 1);
			}
		}
		getchar();
	}

	int xs = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(cm[i][j] >= 5) xs++;
		}
	}
	cout << xs << endl;

	return 0;
}
