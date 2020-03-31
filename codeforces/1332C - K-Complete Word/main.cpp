#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		string s; cin >> s;
		int nb = n / k;

		int ans = 0;

		int l = k / 2; if (k % 2 == 1) l++;
		for (int i = 0; i < l; i++) {
			vi freq; freq.assign(26, 0);
			for (int b = 0; b < nb; b++) {
				freq[s[b * k + i] - 'a']++;
				freq[s[(b + 1) * k - i - 1] - 'a']++;
			}
			
			int mf = 0;
			for (int j = 0; j < 26; j++) mf = max(mf, freq[j]);

			if (i == l - 1 && k % 2 == 1) ans += nb - mf / 2;
			else ans += 2 * nb - mf;
		}

		cout << ans << endl;
	}

	return 0;
}
