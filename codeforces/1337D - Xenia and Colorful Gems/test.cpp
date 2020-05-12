#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t; cin >> t;
	while (t--) {
		vi a = {1, 3};
		cout << *lower_bound(a.begin(), a.end(), 2) << endl;
		cout << *upper_bound(a.begin(), a.end(), 2) << endl;
	}

	return 0;
}
