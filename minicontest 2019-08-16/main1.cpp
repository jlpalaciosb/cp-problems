// UVa 10131 - Is Bigger Smarter?
#include <iostream>
#include <cstring>
#define UNDEF -1
#define INF 1000000000
using namespace std;

int n, w[1010], s[1010];
int dp[1010], nxt[1010];

int lids(int i) {
	int &len = dp[i];
	if (len != UNDEF) return len;
	len = 0;
	for (int j = 1; j <= n; j++) {
		if (w[j] > w[i] && s[j] < s[i]) {
			int lj = 1 + lids(j);
			if (lj > len) {
				len = lj;
				nxt[i] = j;
			}
		}
	}
	return len;
}

int main() {
	n = 0;
	while ((cin >> w[n + 1]) && (cin >> s[n + 1])) n++;

	w[0] = 0; s[0] = INF;
	for (int i = 0; i <= n; i++) dp[i] = nxt[i] = UNDEF;

	cout << lids(0) << endl;
	int i = nxt[0];
	while (i != UNDEF) {
		cout << i << endl;
		i = nxt[i];
	}

	return 0;
}
