// UVa 562 - Dividing coins
#include <iostream>
#include <vector>
#define UNDEF -1
using namespace std;

int m, v[100], memo[110][30000];
int knapsack(int i, int s) {
	int &ret = memo[i][s];
	if (ret != UNDEF) return ret;

	if (i == m || s == 0) {
		ret = 0;
	} else if (v[i] > s) {
		ret = knapsack(i + 1, s);
	} else {
		ret = max(
			knapsack(i + 1, s),
			v[i] + knapsack(i + 1, s - v[i])
		);
	}
	return ret;
}

void reset_memo(int a, int b) {
	for (int i = 0; i < a + 5; ++i)
		for (int j = 0; j < b + 5; ++j)
			memo[i][j] = UNDEF;
}

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> m;
		int sum = 0;
		for (int j = 0; j < m; ++j) {
			cin >> v[j];
			sum += v[j];
		}

		reset_memo(m, sum / 2);
		int a = knapsack(0, sum / 2);
		int b = sum - a;
		cout << abs(a - b) << endl;
	}
	return 0;
}
