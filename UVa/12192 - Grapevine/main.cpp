/**************************************************************/
#include <unordered_map>
#include     <algorithm>
#include      <iostream>
#include       <cstring>
#include       <cstdlib>
#include        <bitset>
#include        <string>
#include        <vector>
#include         <stack>
#include         <cmath>
#include         <queue>
#include          <list>
#include           <map>
#include           <set>
#define INTBM 2147483647
#define debug(x) cerr << #x << " = " << x << "\n"
using namespace std;
typedef vector<int> vi; typedef vi::iterator viIt; typedef vector<vi> vvi;
typedef long long ll; typedef long double ld;
/**************************************************************/

int n, m, h[500][500];

int solve(int l, int u) {
	int ans = 0; // largest side
	for(int r = 0; r < n; r++) {
		if(u < h[r][0] || h[r][m - 1] < l) continue;
		if(n - r <= ans) break;

		int lb = lower_bound(h[r], h[r] + m, l) - h[r];
		int i = r;
		int j = lb;
		int s = 0;
		while(i < n && j < m && h[i][j] <= u) {
			i++;
			j++;
			s++;
		}
		ans = max(ans, s);
	}
	return ans;
}

int main() {
	while(true) {
		cin >> n >> m; if(n == 0) break;
		for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> h[i][j];
		int q; cin >> q;
		while(q--) {
			int l, u; cin >> l >> u;
			cout << solve(l, u) << endl;
		}
		cout << '-' << endl;
	}
	return 0;
}
