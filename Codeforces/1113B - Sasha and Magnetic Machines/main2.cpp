#include <iostream>
#define debug(x) cerr << #x << " = " << x << endl

using namespace std;

bool e[110];
int n, sum, minp;
int nr, v[110];

void init() {
	for(int i = 1; i <= 100; ++i) {
		e[i] = false;
	}

	cin >> n;
	sum = 0;
	for(int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		sum += a;
		e[a] = true;
	}
	minp = sum;

	nr = 0;
	for(int i = 1; i <= 100; ++i) {
		if(e[i]) {
			v[nr] = i;
			nr++;
		}
	}
}

void solve() {
	for(int i = 0; i < nr - 1; ++i) {
		for(int j = i + 1; j < nr; ++j) {
			int a = v[i];
			int b = v[j];
			for(int d = 1; d <= b; d++) {
				if(b % d == 0) {
					int nsum = sum - a - b + a * d + b / d;
					minp = min(minp, nsum);
				}
			}
		}
	}
}

int main() {
	init();
	solve();
	cout << minp << endl;
	return 0;
}
