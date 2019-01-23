#include <iostream>
#include <cmath>

using namespace std;

/* The polinomial */
int c[21]; // coefficients
int i; // degree

long long p(int n);

int main() {
	int tc; cin >> tc;
	while(tc--) {
		cin >> i;
		for(int j = 0; j <= i; j++)
			cin >> c[j];

		double d, k;
		cin >> d >> k;

		int n = (int)ceil((-1.0 + sqrt(1.0 + 8.0 * k / d)) / 2.0);
		cout << p(n) << endl;
	}
	return 0;
}

long long p(int n)  {
	long long result = 0;
	for(int j = 0; j <= i; j++)
		result += (long long)c[j] * (long long)powl((long double)n, (long double)j);
	return result;
}
