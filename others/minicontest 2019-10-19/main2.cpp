// UVa 11057 - Exact Sum
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000000000
using namespace std;

int main() {
	int n;
	while ((int)scanf("%d", &n) == 1) {
		vector<int> v; v.resize(n);
		for (int i = 0; i < n; ++i) scanf("%d", &v[i]);
		sort(v.begin(), v.end());
		int m; cin >> m;
		
		int a = -1, b = -1, diff = INF;
		for (int i = 0; i < n; ++i) {
			int ai = v[i], bi = m - ai;
			int ind = lower_bound(v.begin() + i + 1, v.end(), bi) - v.begin();
			if (ind < n && v[ind] == bi && abs(ai - bi) < diff) {
				diff = abs(ai - bi);
				a = ai;
				b = bi;
			}
		}

		printf("Peter should buy books whose prices are %d and %d.\n\n", min(a, b), max(a, b));
	}
	return 0;
}
