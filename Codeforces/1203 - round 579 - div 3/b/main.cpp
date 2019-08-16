#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;
typedef unordered_multiset<int> conjunto;
typedef conjunto::iterator conj_it;

int q, n, s[400];
conjunto lados;

int main() {
	lados.reserve(500);

	cin >> q;
	while (q--) {
		cin >> n;
		for (int i = 0; i < 4 * n; i++) cin >> s[i];
		
		sort(s, s + 4 * n);
		int c = 0;
		for (int i = 0; i < 4 * n; i += 2) {
			if (s[i] != s[i + 1]) {
				cout << "NO" << endl;
				break;
			}
			s[c++] = s[i];
		}
		if (c != 2 * n) continue;

		bool pos = false;
		for (int i = 1; i < 2 * n; i++) {
			int area = s[0] * s[i];

			lados.clear();
			for (int j = 1; j < 2 * n; j++) {
				if (j == i) continue;
				lados.insert(s[j]);
			}
			
			for (int r = 1; r <= n - 1; r++) {
				conj_it l1_it = lados.begin();
				int l1 = *l1_it;
				lados.erase(l1_it);

				if (area % l1 != 0) break;
				int l2 = area / l1;

				conj_it l2_it = lados.find(l2);
				if (l2_it == lados.end()) {
					break;
				} else {
					lados.erase(l2_it);
				}
			}

			if (lados.empty()) {
				pos = true;
				cout << "YES" << endl;
				break;
			}
		}

		if (!pos) cout << "NO" << endl;
	}
	return 0;
}
