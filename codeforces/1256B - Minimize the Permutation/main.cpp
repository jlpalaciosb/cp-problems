#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int q; cin >> q;
	int v[110], p[110], op[110];

	while (q--) {
		int n; cin >> n;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", v + i);
			p[v[i]] = i;
		}
		memset(op, 0, sizeof op);

		int m = 1;
		while (m <= n) {
			while (p[m] > 1 && !op[p[m] - 1] && v[p[m] - 1] > m) {
				int a = v[p[m] - 1];
				v[p[m] - 1] = m;
				v[p[m]] = a;
				op[p[m] - 1] = 1;
				p[a] += 1;
				p[m] -= 1;
			}
			m += 1;
		}

		printf("%d", v[1]);
		for (int i = 2; i <= n; ++i) printf(" %d", v[i]);
		cout << endl;
	}

	return 0;
}
