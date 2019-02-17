#include <iostream>
#include <cstring>

using namespace std;

int n, m, sn, en, x[15], y[15], used[15];

bool backtrack(int r, int l) {
	if(l == n) return r == en;

	for(int i = 0; i < m; i++) {
		if(used[i]) continue;

		if(x[i] == r) {
			used[i] = true;
			if(backtrack(y[i], l + 1)) return true;
			used[i] = false;
		}

		if(y[i] == r) {
			used[i] = true;
			if(backtrack(x[i], l + 1)) return true;
			used[i] = false;
		}
	}

	return false;
}

int main() {
	while(true) {
		memset(used, 0, sizeof(int) * 15);

		cin >> n; if(n == 0) break;
		cin >> m;

		int nu;
		cin >> nu >> sn;
		cin >> en >> nu;

		for(int i = 0; i < m; i++) cin >> x[i] >> y[i];

		cout << (backtrack(sn, 0) ? "YES" : "NO") << endl;
	}
	return 0;
}
