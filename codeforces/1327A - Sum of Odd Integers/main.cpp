#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
	ios::sync_with_stdio(false);
  	cin.tie(0);

	int t; cin >> t;
	while (t--) {
		ll n, k; cin >> n >> k;
		if (n % 2 != k % 2) {
			printf("NO\n");
		} else {
			if (k * k <= n) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
		}
	}
	return 0;
}
