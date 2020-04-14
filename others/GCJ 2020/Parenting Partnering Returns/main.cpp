#include <iostream>
#include <vector>
#include <algorithm>
#define start first.first
#define finish first.second
#define index second
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int n; cin >> n;
		vector<iii> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i].start >> a[i].finish;
			a[i].index = i;
		}

		sort(a.begin(), a.end());

		vi p(n, 0);
		int cnt = 0;

		int e = 0;
		for (int i = 0; i < n; i++) {
			if (a[i].start >= e && !p[a[i].index]) {
				p[a[i].index] = 1;
				e = a[i].finish;
				cnt++;
			}
		}

		e = 0;
		for (int i = 0; i < n; i++) {
			if (a[i].start >= e && !p[a[i].index]) {
				p[a[i].index] = 2;
				e = a[i].finish;
				cnt++;
			}
		}

		printf("Case #%d: ", t);
		if (cnt == n) {
			for (int i = 0; i < n; i++)
				printf("%c", p[i] == 1 ? 'C' : 'J');
			printf("\n");
		} else {
			printf("IMPOSSIBLE\n");
		}
	}

	return 0;
}
