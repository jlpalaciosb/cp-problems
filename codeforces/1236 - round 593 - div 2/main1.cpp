// A. Stones
#include <iostream>
#define UNDEF -1
using namespace std;

int memo[101][101][101];

void reset_memo(int a, int b, int c) {
	for (int i = 0; i <= a; ++i)
		for (int j = 0; j <= b; ++j)
			for (int k = 0; k <= c; ++k)
				memo[i][j][k] = UNDEF;
}

int dp(int a, int b, int c) {
	int &ret = memo[a][b][c];
	if (ret != UNDEF) return ret;

	int m1 = -1;
	if (a >= 1 && b >= 2) m1 = 3 + dp(a - 1, b - 2, c);
	int m2 = -1;
	if (b >= 1 && c >= 2) m2 = 3 + dp(a, b - 1, c - 2);
	ret = max(0, max(m1, m2));
	return ret;
}

int main() {
	int t; cin >> t;
	while (t--) {
		int a, b, c; cin >> a >> b >> c;
		reset_memo(a, b, c);
		cout << dp(a, b, c) << endl;
	}
	return 0;
}
