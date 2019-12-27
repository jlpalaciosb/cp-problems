// UVa 624 - CD
#include <iostream>
using namespace std;

int main() {
	int n, m, v[20];
	while (scanf("%d", &n) == 1) {
		cin >> m;
		for (int i = 0; i < m; ++i) cin >> v[i];

		int op = 1, ops = v[0], opc = 1, last = (1 << m);
		for (int mask = 2; mask < last; mask++) {
			int sum = 0, c = 0;
			for (int i = 0; i < m; ++i) {
				if (mask & (1 << i)) {
					sum += v[i];
					c++;
				}
			}
			if (sum <= n && (sum > ops || (sum == ops && c > opc))) {
				ops = sum;
				opc = c;
				op = mask;
			}
		}

		for (int i = 0; i < m; ++i) {
			if (op & (1 << i)) printf("%d ", v[i]);
		}
		printf("sum:%d\n", ops);
	}
	return 0;
}
