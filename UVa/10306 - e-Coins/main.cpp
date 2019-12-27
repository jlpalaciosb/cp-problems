#include <iostream>
#include <cstring>
#include <math.h>
#define INF 1000000000
using namespace std;

int n, m, S;
int x[50], y[50];
int cx, cy; // candidate <x, y> target
int ANS;
int memo[310][310];

bool is_perfect_square(int n) {
	int root = (int)(sqrt((double)n) + 0.5);
	return root * root == n;
}

int square_root(int n) {
	return (int)(sqrt((double)n) + 0.5);
}

int change(int cx, int cy) {
	if (cx == 0 && cy == 0) {
		return 0;
	} else if (cx < 0 || cy < 0) {
		return INF;
	} else {
		int &ans = memo[cx][cy];
		if (ans != -1) return ans;
		ans = INF;
		for (int i = 0; i < m; i++) {
			if (x[i] == 0 && y[i] == 0) continue;
			ans = min(ans, change(cx - x[i], cy - y[i]));
		}
		return ++ans;
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m >> S;
		ANS = INF;
		memset(memo, -1, sizeof memo);

		for (int j = 0; j < m; j++) cin >> x[j] >> y[j];

		for (cx = 0; cx <= S; cx++) {
			if (is_perfect_square(S * S - cx * cx)) {
				cy = square_root(S * S - cx * cx);
				ANS = min(ANS, change(cx, cy));
			}
		}

		if (ANS == INF) cout << "not possible" << endl;
		else cout << ANS << endl;
	}
	return 0;
}
