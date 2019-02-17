#include <iostream>

using namespace std;

int main() {
	int n; cin >> n;
	while(n--) {
		long long k; int x;
		cin >> k >> x;
		cout << ((long long)x + 9LL * (k - 1LL)) << endl;
	}
	return 0;
}
