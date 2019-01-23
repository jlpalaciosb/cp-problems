#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t; cin >> t;
	while(t--) {
		int n; cin >> n; // the length of the bar we want to obtain
		int p; cin >> p; // the number of bars
		vector<int> bars;
		bars.resize(p); for(int i = 0; i < p; i++) cin >> bars[i];
		int sum;
		for(int bm = 0; bm < (1 << p); bm++) {
			sum = 0;
			for(int i = 0; i < p; i++) {
				if(bm & (1 << i)) sum += bars[i];
			}
			if(sum == n) {
				cout << "YES" << endl;
				break;
			}
		}
		if(sum != n) cout << "NO" << endl;
	}
	return 0;
}
