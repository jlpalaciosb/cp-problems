#include <iostream>
#include <vector>
#define INF 1000000000
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi mat; int n, m;

vi cnt;
int solve(int j) {
	cnt.assign(n, 0);
	for (int i = 0; i < n; i++) {
		if (mat[i][j] % m == j && mat[i][j] <= (n - 1) * m + j) {
			int ex_i = (mat[i][j] - j) / m;
			if (ex_i <= i) cnt[i - ex_i]++;
			else cnt[n - (ex_i - i)]++;
		}
	}

	int m = INF;
	for (int i = 0; i < n; i++) {
		m = min(m, i + n - cnt[i]);
	}

	return m;
}

int main() {
	cin >> n >> m;
	mat.resize(n); for (int i = 0; i < n; ++i) mat[i].resize(m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int a; scanf("%d", &a); mat[i][j] = a - 1;
		}
	}

	int res = 0;
	for (int j = 0; j < m; ++j) res += solve(j);
	cout << res << endl;

	return 0;
}
