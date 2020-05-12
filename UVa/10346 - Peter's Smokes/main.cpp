#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	while (cin >> n >> k) {
		int ans = 0;
		while (n >= k) {
			ans += n - n % k;
			n = n / k + n % k;
		}
		ans += n;
		cout << ans << endl;
	}

	return 0;
}
