#include <iostream>
using namespace std;

int main() {
	int n, m, d; cin >> n >> m >> d;

	int c[1010], l[1010], r[1010];
	for (int i = 1; i <= m; ++i) scanf("%d", c + i);
	int i = n;
	for (int j = m; j >= 1; --j) {
		r[j] = i;
		l[j] = i - c[j] + 1;
		i = i - c[j];
	}

	i = 0;
	for (int j = 1; j <= m; ++j) {
		if (i + d < l[j]) {
			l[j] = i + d;
			r[j] = l[j] + c[j] - 1;
		}
		i = r[j];
	}

	if (i + d > n) {
		cout << "YES" << endl;
		i = 1;
		for (int j = 1; j <= m; ++j) {
			while (i < l[j]) {
				printf("0 ");
				i++;
			}
			while (i <= r[j]) {
				printf("%d ", j);
				i++;
			}
		}
		while (i <= n) {
			printf("0 ");
			i++;
		}
		cout << endl;
	} else {
		cout << "NO" << endl;
	}

	return 0;
}
