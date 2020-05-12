#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

map<char, int> val;

int comp(string &pg) {
	stack<int> sts, stm;
	sts.push(0);
	for (int i = 0; i < pg.length(); i++) {
		char c = pg[i];
		if (c == 'N' || c == 'S' || c == 'E' || c == 'W') {
			sts.top() += val[c];
		} else if (c == ')') {
			int s = stm.top() * sts.top();
			stm.pop(); sts.pop();
			sts.top() += s;
		} else {
			sts.push(0);
			stm.push(c - '0');
			i++;
		}
	}
	return sts.top();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		string pg; cin >> pg;
		val['N'] = 0; val['S'] = 0; val['E'] = 1; val['W'] = -1;
		int w = comp(pg);
		val['N'] = -1; val['S'] = 1; val['E'] = 0; val['W'] = 0;
		int h = comp(pg);
		if (w >= 0) w++;
		else w = 1000000001 + w;
		if (h >= 0) h++;
		else h = 1000000001 + h;
		printf("Case #%d: %d %d\n", t, w, h);
	}

	return 0;
}
