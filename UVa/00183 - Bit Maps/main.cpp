// Funciona con todos los tests de uDebug, pero en uva me da Runtime Error no sé por qué

#include <iostream>

using namespace std;

int m, n;
char b[210][210];
int dp;

void readB() {
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			cin >> b[i][j];
		}
	}
}

void printB() {
	int c = 0;
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			cout << b[i][j];
			c++;
			if(c % 50 == 0) {
				cout << endl;
			}
		}
	}
	if(c % 50 != 0) {
		cout << endl;
	}
}

void printD(char c) {
	cout << c;
	dp++;
	if(dp % 50 == 0) {
		cout << endl;
	}
}

int sum(int i1, int j1, int i2, int j2) { // Si preprocesamos la matriz, hay una forma de obtener la suma en O(1)
	int s = 0;
	for(int i = i1; i <= i2; i++) {
		for(int j = j1; j <= j2; j++) {
			s += b[i][j] - '0';
		}
	}
	return s;
}

int fill(int i1, int j1, int i2, int j2, char c) {
	for(int i = i1; i <= i2; i++) {
		for(int j = j1; j <= j2; j++) {
			b[i][j] = c;
		}
	}
}

void toB(int i1, int j1, int i2, int j2) {
	char p;
	cin >> p;

	if(p != 'D') {
		fill(i1, j1, i2, j2, p);
	} else {
		int im = (i1 + i2) / 2;
		int jm = (j1 + j2) / 2;
		if(i1 == i2) {
			toB(i1, j1    , i1, jm);
			toB(i1, jm + 1, i1, j2);
		} else if(j1 == j2) {
			toB(i1    , j1, im, j1);
			toB(im + 1, j1, i2, j1);
		} else {
			toB(i1    , j1    , im, jm);
			toB(i1    , jm + 1, im, j2);
			toB(im + 1, j1    , i2, jm);
			toB(im + 1, jm + 1, i2, j2);
		}
	}
}

void toD(int i1, int j1, int i2, int j2) {
	if(i1 == i2 && j1 == j2) {
		printD(b[i1][j1]);
	} else {
		int s = sum(i1, j1, i2, j2);
		int w = j2 - j1 + 1;
		int h = i2 - i1 + 1;
		if(s == 0) {
			printD('0');
		} else if(s == w * h) {
			printD('1');
		} else {
			printD('D');
			int im = (i1 + i2) / 2;
			int jm = (j1 + j2) / 2;
			if(i1 == i2) {
				toD(i1, j1    , i1, jm);
				toD(i1, jm + 1, i1, j2);
			} else if(j1 == j2) {
				toD(i1    , j1, im, j1);
				toD(im + 1, j1, i2, j1);
			} else {
				toD(i1    , j1    , im, jm);
				toD(i1    , jm + 1, im, j2);
				toD(im + 1, j1    , i2, jm);
				toD(im + 1, jm + 1, i2, j2);
			}
		}
	}
}

int main() {
	char format;
	while(cin >> format, format != '#') {
		cin >> m >> n;
		printf("%c%4d%4d\n", (format == 'B' ? 'D' : 'B'), m, n);
		if(format == 'B') {
			readB();
			dp = 0;
			toD(0, 0, m - 1, n - 1);
			if(dp % 50 != 0) {
				cout << endl;
			}
		} else {
			toB(0, 0, m - 1, n - 1);
			printB();
		}
	}
	return 0;
}
