#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
	int n; cin >> n;
	int m = 0, ai, bi;
	for (int i = 0; i < n; i++) {
		scanf("%d", &bi);
		ai = bi + m;
		printf("%d ", ai);
		m = max(m, ai);
	}

	return 0;
}
