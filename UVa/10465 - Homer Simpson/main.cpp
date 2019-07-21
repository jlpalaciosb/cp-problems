#include <iostream>
#include <vector>
using namespace std;
typedef pair<int,int> res;

int m, n, t;
res undef = make_pair(-1, -1);
vector<res> memo(10001);

res f(int t) {
	res &ans = memo[t];
	if (memo[t] == undef) {
		if (t < m && t < n) {
			ans = make_pair(0, 0);
		} else if (t < m) {
			ans = make_pair(n + f(t - n).first, 1 + f(t - n).second);
		} else if (t < n) {
			ans = make_pair(m + f(t - m).first, 1 + f(t - m).second);
		} else {
			ans = max(
				make_pair(m + f(t - m).first, 1 + f(t - m).second),
				make_pair(n + f(t - n).first, 1 + f(t - n).second)
			);
		}
	}
	return ans;
}

int main() {
	while(cin >> m >> n >> t) {
		memo.assign(t + 1, undef);
		res ans = f(t);
		if (ans.first == t) cout << ans.second << endl;
		else cout << ans.second << " " << t - ans.first << endl;
	}
	return 0;
}
