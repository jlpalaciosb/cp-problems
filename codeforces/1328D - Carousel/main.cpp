#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

void show_sol(int &n, int &k, vi &color) {
	cout << k << endl;
	for (int i = 1; i <= n; i++) cout << color[i] << ' ';
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vi type(200010), color(200010);
	
	int q; cin >> q;
	while (q--) {
		int n, k; cin >> n;
		for (int i = 1; i <= n; i++) cin >> type[i];

		bool alle = true;
		for (int i = 2; i <= n; i++) if (type[i] != type[i - 1]) { alle = false; break; }
		if (alle) {
			k = 1;
			for (int i = 1; i <= n; i++) color[i] = 1;
			show_sol(n, k, color); continue;
		}

		if (n % 2 == 0) {
			k = 2;
			for (int i = 1; i <= n; i++) color[i] = i % 2 + 1;
			show_sol(n, k, color); continue;
		}

		int adje = 0;
		for (int i = 2; i <= n; i++) if (type[i] == type[i - 1]) { adje = i; break; }
		if (adje == 0) {
			for (int i = 1; i <= n - 1; i++) color[i] = i % 2 + 1;
			if (type[n] == type[n - 1]) {
				k = 2;
				color[n] = color[n - 1];
			} else if (type[n] == type[1]) {
				k = 2;
				color[n] = color[1];
			} else {
				k = 3;
				color[n] = 3;
			}
			show_sol(n, k, color); continue;
		} else {
			k = 2;
			for (int i = 1; i < adje; i++) color[i] = i % 2 + 1;
			color[adje] = color[adje - 1];
			int c = color[adje];
			for (int i = adje + 1; i <= n; i++) {
				if (c == 1) c = 2;
				else c = 1;
				color[i] = c;
			}
			show_sol(n, k, color); continue;
		}
	}

	return 0;
}
