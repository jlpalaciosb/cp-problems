#include <iostream>
#include <algorithm>
using namespace std;

int n, p[200010], s[200010];

int recur(int i, int t, int c) {
	if (i == t) {
		s[i] = c;
	} else {
		s[i] = recur(p[i], t, c + 1);
	}
	return s[i];
}

int main() {
	int q; cin >> q;
	while (q--) {
		cin >> n;
		for (int i = 1; i <= n; ++i) scanf("%d", p + i);
		for (int i = 1; i <= n; ++i) s[i] = 0;

		for (int i = 1; i <= n; ++i) {
			if (s[i] == 0) {
				s[i] = recur(p[i], i, 1);
			}
		}

		for (int i = 1; i <= n; ++i) {
			if (i > 1) printf(" ");
			printf("%d", s[i]);
		}
		printf("\n");
	}
	return 0;
}
