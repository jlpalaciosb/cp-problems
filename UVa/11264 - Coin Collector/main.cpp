// Thanks to Algorithmist

#include <iostream>
#define debug(x) cerr << #x << " = " << x << endl
using namespace std;

int T, n, coin[1010], c;
long long s;

int main() {
	cin >> T;
	while(T--) {
		cin >> n;
		for(int i = 1; i <= n; i++) {
			cin >> coin[i];
		}

		s = 0; c = 0;
		for(int i = 1; i < n; i++) {
			if(coin[i + 1] > s + coin[i]) {
				c++;
				s += coin[i];
			}
		}
		c++; // el último siempre entra

		cout << c << endl;
	}
	return 0;
}
