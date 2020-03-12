#include <iostream>
#include <cmath>
using namespace std;

int f[35], nf;
void ff(int n) {
	nf = 0;
	while (n % 2 == 0) {
		f[++nf] = 2;
		n /= 2;
	}
	int sq = (int)sqrt(n);
	for (int i = 3; i <= sq; i += 2) {
		while (n % i == 0) {
			n /= i;
			f[++nf] = i;
		}
	}
	if (n != 1) f[++nf] = n;
}

int main() {
	int t; cin >> t;
	while (t--) {
		int n; scanf("%d", &n);
		ff(n);
		if (nf <= 2) {
			printf("NO\n");
		} else if (nf == 3) {
			if (f[1] != f[2] && f[2] != f[3]) {
				printf("YES\n%d %d %d\n", f[1], f[2], f[3]);
			} else {
				printf("NO\n");
			}
		} else if (nf == 4) {
			if (f[1] != f[4]) {
				printf("YES\n%d %d %d\n", f[1], f[2] * f[3], f[4]);
			} else {
				printf("NO\n");
			}
		} else if (nf == 5) {
			if (f[1] != f[5]) {
				printf("YES\n%d %d %d\n", f[1], f[2] * f[3] * f[4], f[5]);
			} else {
				printf("NO\n");
			}
		} else {
			printf("YES\n%d %d ", f[1], f[2] * f[3]);
			int m = 1;
			for (int i = 4; i <= nf; ++i) {
				m *= f[i];
			}
			printf("%d\n", m);
		}
	}

	return 0;
}
