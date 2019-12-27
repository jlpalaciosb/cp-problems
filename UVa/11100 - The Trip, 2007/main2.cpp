#include <iostream>
#include <vector>
#include <algorithm>
#define debug(x) cerr << #x << " = " << x << endl
using namespace std;

int main() {
	while(true) {
		int n; cin >> n; if(n == 0) break;

		vector<int> v; v.clear();
		for(int i = 0; i < n; i++) {
			int a; cin >> a;
			v.push_back(a);
		}
		sort(v.begin(), v.end());

		int max_freq = 0, cur_freq = 1;
		for(int i = 1; i < n; i++) {
			if(v[i] == v[i - 1]) {
				cur_freq++;
			} else {
				max_freq = max(max_freq, cur_freq);
				cur_freq = 1;
			}
		}
		max_freq = max(max_freq, cur_freq);

		cout << max_freq << endl;
		for(int i = 0; i < max_freq; i++) {
			for(int j = i; j < n; j += max_freq) {
				cout << v[j];
				if(j + max_freq < n) cout << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
