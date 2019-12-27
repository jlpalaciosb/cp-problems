#include <iostream>
#include <string>
#include <vector>
#define debug(x) cerr << #x << " = " << x << endl
using namespace std;

struct stone {
	char type;
	int distance;
};

stone read_stone() {
	static string desc;
	cin >> desc;
	stone st;
	st.type = desc[0];
	st.distance = stoi(desc.substr(2));
	return st;
}

int cal_maxl(const vector<int> & smalls) {
	int maxl = 0, last = 0;
	for(int i = 0; i < smalls.size(); i += 2) {
		maxl = max(maxl, smalls[i] - last);
		last = smalls[i];
	}
	last = 0;
	for(int i = 1; i < smalls.size(); i += 2) {
		maxl = max(maxl, smalls[i] - last);
		last = smalls[i];
	}
	return maxl;
}

int main() {
	int T; cin >> T;
	for(int t = 1; t <= T; t++) {
		int n, d; cin >> n >> d;

		int last = 0, maxl = 0;
		vector<int> smalls; smalls.clear();

		for(int i = 1; i <= n; i++) {
			stone st = read_stone();
			if(st.type == 'B') {
				smalls.push_back(st.distance - last);
				maxl = max(maxl, cal_maxl(smalls));
				last = st.distance;
				smalls.clear();
			} else {
				smalls.push_back(st.distance - last);
			}
		}
		smalls.push_back(d - last);
		maxl = max(maxl, cal_maxl(smalls));

		cout << "Case " << t << ": " << maxl << endl;
	}
	return 0;
}
