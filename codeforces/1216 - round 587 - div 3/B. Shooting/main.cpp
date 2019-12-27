#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> ii;

int main() {
	int n; cin >> n;
	vector<ii> v; v.reserve(n);
	for (int i = 1; i <= n; ++i) {
		int a; cin >> a;
		v.push_back(ii(a, i));
	}
	sort(v.begin(), v.end(), greater<ii>());
	int sum = 0;
	for (int i = 0; i < n; ++i) sum += v[i].first * i + 1;
	cout << sum << endl;
	cout << v[0].second;
	for (int i = 1; i < n; ++i) cout << ' ' << v[i].second;
	return 0;
}
