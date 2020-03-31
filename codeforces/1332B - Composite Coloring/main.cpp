#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int primes[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t; cin >> t;
	vi a(1000), c(1000);
	while (t--) {
		int n; cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		c.assign(n, 0);

		int m = 1;
		for (int i = 0; i < 11; i++) {
			int pi = primes[i];
			bool used = false;
			for (int i = 0; i < n; i++) {
				if (c[i] == 0 && a[i] % pi == 0) {
					c[i] = m;
					used = true;
				}
			}
			if (used) m++;
		}

		cout << m - 1 << endl;
		for (int i = 0; i < n; i++) cout << c[i] << ' ';
		cout << endl;
	}

	return 0;
}
