#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int n; vi a(2000);

int freq[26][2000];
void compute_freq() {
	for (int i = 0; i < 26; i++) {
		freq[i][0] = a[0] == i ? 1 : 0;
		for (int j = 1; j < n; j++) {
			freq[i][j] = a[j] == i ? freq[i][j - 1] + 1 : freq[i][j - 1];
		}
	}
}
int max_freq(int l, int r) { // l <= r
	if (l > r) return 0;
	int res = 0;
	for (int i = 0; i < 26; i++) {
		int f = freq[i][r];
		if (l > 0) f -= freq[i][l - 1];
		if (f > res) res = f;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			int ai; cin >> ai; ai--; // de 0 a 25
			a[i] = ai;
		}
		compute_freq();
		int ans = 0;
		for (int i = 0; i < 26; i++) {
			int l = 0, r = n - 1;
			int c = 0;
			while (true) {
				while (a[l] != i && l < n) {
					l++;
				}
				while (a[r] != i && r > -1) {
					r--;
				}
				if (l > r) {
					break;
				}
				c += l == r ? 1 : 2;
				ans = max(ans, c + max_freq(l + 1, r - 1));
				l++;
				r--;
			}
		}
		cout << ans << endl;
	}

	return 0;
}
