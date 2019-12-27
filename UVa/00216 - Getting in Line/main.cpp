#include <iostream>
#include <math.h>
#include <cstring>
#define INF 999999999
using namespace std;

int n, x[8], y[8], nn = 0;
double memo[8][256], ans;
int start, sig[8][256];

double distance(int p1, int p2) {
	return sqrt(pow(x[p1] - x[p2], 2) + pow(y[p1] - y[p2], 2));
}

double tsp(int pos, int mask) {
	if (mask == (1 << n) - 1) return 0;
	double &mem = memo[pos][mask];
	if (mem != 0) return mem;
	mem = INF;
	for (int i = 0; i < n; i++) {
		if (i == pos || mask & (1 << i)) continue;
		double _tsp = distance(pos, i) + tsp(i, mask | (1 << i));
		if (_tsp < mem) {
			sig[pos][mask] = i;
			mem = _tsp;
		}
	}
	return mem;
}

void show_answer() {
	printf("**********************************************************\n");
	printf("Network #%d\n", nn);
	int mask = 1 << start;
	for (int i = 0; i < n - 1; i++) {
		int _sig = sig[start][mask];
		printf(
			"Cable requirement to connect (%d,%d) to (%d,%d) is %.2f feet.\n",
			x[start], y[start], x[_sig], y[_sig], distance(start, _sig) + 16
		);
		start = _sig;
		mask |= 1 << _sig;
	}
	printf("Number of feet of cable required is %.2f.\n", ans + 16 * (n - 1));
}

int main() {
	while (cin >> n, n != 0) {
		nn++;
		for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
		ans = INF;
		memset(memo, 0, sizeof memo);
		for (int i = 0; i < n; i++) {
			double _tsp = tsp(i, 1 << i);
			if (_tsp < ans) {
				start = i;
				ans = _tsp;
			}
		}
		show_answer();
	}
	return 0;
}
