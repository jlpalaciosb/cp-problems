// A simple interval covering problem

#include <iostream>
#include <bitset>
#define debug(x) cerr << #x << " = " << x << endl
using namespace std;

int T, t, n, c;
char f;
bitset<110> fertile;

int main() {
	cin >> T;
	for(int t = 1; t <= T; t++) {
	 	cin >> n;
	 	fertile.reset();
		for(int i = 1; i <= n; i++) {
			cin >> f;
			if(f == '.') {
				fertile.set(i);
			}
		}

		c = 0;
		for(int i = 1; i <= n; i++) {
			if(fertile.test(i)) {
				c++;
				i += 2; // ojo que antes de terminar el ciclo i se incrementa en 1 automaticamente, o sea que realmente el siguiente i es i + 3
			}
		}

		cout << "Case " << t << ": " << c << endl;
	}
	return 0;
}
