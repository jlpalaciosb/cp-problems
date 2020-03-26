#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
	ios::sync_with_stdio(false);
  	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	int x, y;
	for (int i = 0; i < k; i++) scanf("%d%d%d%d", &x, &y, &x, &y);

	printf("%d\n", (n - 1) + (m - 1) + n * m);
	for (int i = 0; i < n - 1; i++) printf("U");
	for (int i = 0; i < m - 1; i++) printf("L");
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			for (int i = 0; i < m - 1; i++) printf("R");
		} else {
			for (int i = 0; i < m - 1; i++) printf("L");
		}
		printf("D");
	}

	return 0;
}
