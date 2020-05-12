#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int n, h[100]; cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> h[i];
		}
		int c = 0;
		for (int i = 1; i < n - 1; i++) {
			if (h[i] > h[i - 1] && h[i] > h[i + 1]) {
				c++;
			}
		}
		printf("Case #%d: %d\n", t, c);
	}

	return 0;
}
