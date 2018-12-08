#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef vector<int> vi;
typedef map<vi, int> mvii;
typedef mvii::iterator mvii_it;

int main() {
	int n;
	while(cin >> n, n != 0) {
		mvii freq;
		freq.clear();
		for(int i = 0; i < n; ++i) {
			vi comb(5);
			cin >> comb[0] >> comb[1] >> comb[2] >> comb[3] >> comb[4];
			sort(comb.begin(), comb.end());
			mvii_it it = freq.find(comb);
			if(it != freq.end()) {
				it->second += 1;
			} else {
				freq[comb] = 1;
			}
		}

		int max = 0, res;
		for(mvii_it it = freq.begin(); it != freq.end(); ++it) {
			if(it->second > max) {
				max = it->second;
				res = it->second;
			} else if(it->second == max) {
				res += it->second;
			}
		}
		cout << res << endl;
	}

	return 0;
}
