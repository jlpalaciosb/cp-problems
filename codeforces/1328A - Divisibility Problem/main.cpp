#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
	int t; cin >> t;
	while (t--) {
		int a, b; scanf("%d%d", &a, &b);
		if (a % b == 0) printf("0\n");
		else printf("%d\n", b - a % b);
	}
	return 0;
}
