// No ví otras formas de sumar

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> v(5001);
	int n;

	while(cin >> n, n > 0) {
		for(int i = 0; i < n; ++i) {
			cin >> v[i];
		}
		sort(v.begin(), v.begin() + n);
		int cost = 0;
		int sum = v[0];
		for(int i = 1; i < n; ++i) {
			sum += v[i];
			cost += sum;
		}
		cout << cost << endl;
	}

	return 0;
}
