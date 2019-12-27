#include <iostream>
#include <cstring>
#define MIN -1270000 // -127 * 100 * 100
using namespace std;

int n, m[100][100], tmp[100];

int solve(); // solve our problem
int kadane(); // apply kadane on tmp

int solve() {
	int ans = MIN;
	for (int c1 = 0; c1 < n; c1++) {
		memset(tmp, 0, sizeof tmp);
		for (int c2 = c1; c2 < n; c2++) {
			for (int i = 0; i < n; i++) tmp[i] += m[i][c2];
			ans = max(ans, kadane());
		}
	}
	return ans;
}

int kadane() {
	int ans = MIN, sum = 0;
	for (int i = 0; i < n; i++) {
		sum += tmp[i];
		ans = max(ans, sum);
		if (sum < 0) sum = 0;
	}
	return ans;
}

int main() {
	while (cin >> n) {
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> m[i][j];
		cout << solve() << endl;
	}
	return 0;
}
