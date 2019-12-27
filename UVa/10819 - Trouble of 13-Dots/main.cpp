// WRONG ANSWER (don't know why)

#include <iostream>
#include <cstring>
#define M 1000000000
using namespace std;

int m, n;
int p[110], f[110];
int memo[110][11000];
int lb, ub; // lower bound and upper bound for the last remainder

int max_flavour(int item, int money) {
	if (item == n) {
		if (money >= lb && money <= ub) {
			return 0;
		} else {
			return -M;
		}
	} else if (money == 0) {
		return 0;
	} else {
		if (memo[item][money] != -1) {
			return memo[item][money];
		}
		if (p[item] > money) {
			memo[item][money] = max_flavour(item + 1, money);
		} else {
			memo[item][money] = max(
				max_flavour(item + 1, money),
				f[item] + max_flavour(item + 1, money - p[item])
			);
		}
		return memo[item][money];
	}
}

int main() {
	while (cin >> m >> n) {
		lb = 0; ub = 10000;

		for (int i = 0; i < n; i++) {
			cin >> p[i];
			cin >> f[i];
		}

		int ans, ans1, ans2;
		memset(memo, -1, sizeof memo);

		if (m <= 1800) {
			ans = max_flavour(0, m);
		} else if (m >= 2000) {
			ans = max_flavour(0, m + 200);
		} else { // 1800 < m < 2000
			ans1 = max_flavour(0, m);

			// ahora probamos con descuento
			memset(memo, -1, sizeof memo);
			ub = m - (2000 - 200) - 1;
			ans2 = max_flavour(0, m + 200);

			ans = max(ans1, ans2);
		}

		cout << ans << endl;
	}
	return 0;
}
