#include <iostream>

using namespace std;

short g[3][3];

bool g_is_cero();
void f();
short get(int r, int c);

int main() {
	int n;
	cin >> n;
	for(int k = 1; k <= n; ++k) {
		for(int i = 0; i < 3; ++i) {
			string row;
			cin >> row;
			for(int j = 0; j < 3; ++j) {
				g[i][j] = row[j] - '0';
			}
		}
		int c = -1;
		while(!g_is_cero()) {
			f();
			c += 1;
		}
		cout << c << endl;
	}
	return 0;
}


bool g_is_cero() {
	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < 3; ++j) {
			if(g[i][j] != 0) {
				return false;
			}
		}
	}
	return true;
}

void f() {
	static short aux[3][3];
	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < 3; ++j) {
			aux[i][j] = (get(i + 1, j) + get(i - 1, j) + get(i, j + 1) + get(i, j - 1)) % 2;
		}
	}
	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < 3; ++j) {
			g[i][j] = aux[i][j];
		}
	}
}

short get(int r, int c) {
	if(r < 3 && r > -1 && c < 3 && c > -1) {
		return g[r][c];
	} else {
		return 0;
	}
}
