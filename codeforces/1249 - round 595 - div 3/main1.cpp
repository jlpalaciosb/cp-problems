#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int q; cin >> q;
	while (q--) {
		int n; cin >> n;
		int v[100];
		for (int i = 0; i < n; ++i) {
			scanf("%d", v + i);
		}
		sort(v, v + n);
		int c = 1;
		for (int i = 1; i < n; ++i) {
			if (v[i] == v[i - 1] + 1) {
				c = 2;
				break;
			}
		}
		cout << c << endl;
	}
	return 0;
}
