#include <iostream>
using namespace std;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	int n; cin >> n;
	int a[n], d[n];
	int m = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		m = max(m, a[i]);
	}
	int z = 0;
	for (int i = 0; i < n; ++i) {
		d[i] = m - a[i];
		z = gcd(z, d[i]);
	}
	long long y = 0;
	for (int i = 0; i < n; ++i) y += d[i] / z;
	cout << y << ' ' << z << endl;
	return 0;
}
