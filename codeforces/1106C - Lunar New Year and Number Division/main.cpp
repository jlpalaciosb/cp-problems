#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n; cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end());
	long long min = 0;
	for(int i = 0; i < n / 2; i++) {
		int a = v[i];
		int b = v[n - i - 1];
		min += (a + b) * (a + b);
	}
	cout << min << endl;
	return 0;
}
