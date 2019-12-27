#include <iostream>
using namespace std;

int main() {
	int q; cin >> q;
	while (q--) {
		int n; cin >> n;
		int p[201];
		for (int i = 1; i <= n; ++i) scanf("%d", p + i);

		for (int i = 1; i <= n; ++i) {
			if (i > 1) printf(" ");
			int c = 1, j = p[i];
			while (j != i) {
				c++;
				j = p[j];
			}
			printf("%d", c);
		}
		printf("\n");
	}
	return 0;
}
