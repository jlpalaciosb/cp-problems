#include <iostream>
#include <algorithm>
#define INF 2000000000
#define UNDEF -1
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;

ii a[200010];
int n, t[200010], p[200010];
ll memo[200010];

ll dp(int i) {
	if (i == 0) return 0;

	ll &r = memo[i];
	if (r != UNDEF) return r;

	ll r1 = INF;
	if (i - 2 >= 1) r1 = (a[i].first - a[i - 2].first) + dp(i - 3);
	ll r2 = INF;
	if (i - 3 >= 1) r2 = (a[i].first - a[i - 3].first) + dp(i - 4);
	ll r3 = INF;
	if (i - 4 >= 1) r3 = (a[i].first - a[i - 4].first) + dp(i - 5);

	if (r1 <= r2 && r1 <= r3) {
		p[i] = i - 3;
		r = r1;
	} else if (r2 <= r1 && r2 <= r3) {
		p[i] = i - 4;
		r = r2;
	} else {
		p[i] = i - 5;
		r = r3;
	}
	return r;
}

int team() {
	int i = n, k = 0;
	while (i != 0) {
		k++;
		for (int j = i; j > p[i]; j--) {
			t[a[j].second] = k;
		}
		i = p[i];
	}
	return k;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &(a[i].first));
		a[i].second = i;
		memo[i] = UNDEF;
	}
	sort(a + 1, a + n + 1);

	ll res = dp(n);
	int k = team();
	cout << res << ' ' << k << endl;
	cout << t[1];
	for (int i = 2; i <= n; i++) {
		printf(" %d", t[i]);
	}
	return 0;
}
