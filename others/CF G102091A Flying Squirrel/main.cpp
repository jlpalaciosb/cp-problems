// WA

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

int n, m;
vi h;
struct jump_st { int l1, l2, r1, r2; };
vector<jump_st> jump;

vi dp1;

void construct_jumps();
int max_jumps(int x);
int max_jumps(int x, int y);

int main() {
	cin >> n >> m;

	h = vi(n + 1);
	for(int i = 1; i <= n; i++) cin >> h[i];
	construct_jumps();

	dp1 = vi(n + 1, -1);

	while(m--) {
		int x, y; cin >> x >> y;
		if(y == 0) {
			cout << max_jumps(x) << endl;
		} else {
			int mj = max_jumps(x, y);
			if(mj == -1) mj = max_jumps(y, x);
			cout << (mj != -1 ? mj : 0) << endl;
		}
	}

	return 0;
}

void construct_jumps() {
	jump = vector<jump_st>(n + 1);

	stack<int> st1;
	jump[1].l1 = jump[1].l2 = -1;
	st1.push(1);
	for(int i = 2; i <= n; i++) {
		int l1 = -1, l2 = -1;
		while(!st1.empty() && h[st1.top()] < h[i]) {
			if(l1 == -1 || h[l1] < h[st1.top()]) {
				l1 = st1.top();
				l2 = -1;
			} else if(h[l1] == h[st1.top()]) {
				l2 = st1.top();
			}
			st1.pop();
		}
		jump[i].l1 = l1; jump[i].l2 = l2;
		st1.push(i);
	}
	
	stack<int> st2;
	jump[n].r1 = jump[n].r2 = -1;
	st2.push(n);
	for(int i = n - 1; i >= 1; i--) {
		int r1 = -1, r2 = -1;
		while(!st2.empty() && h[i] > h[st2.top()]) {
			if(r1 == -1 || h[r1] < h[st2.top()]) {
				r1 = st2.top();
				r2 = -1;
			} else if(h[r1] == h[st2.top()]) {
				r2 = st2.top();
			}
			st2.pop();
		}
		jump[i].r1 = r1; jump[i].r2 = r2;
		st2.push(i);
	}
	/*for(int i = 1; i <= n; i++) {
		printf("%5d:%5d%5d,%5d%5d\n", i, jump[i].l1, jump[i].l2, jump[i].r1, jump[i].r2);
	}*/
}

int max_jumps(int x) {
	if(x == -1) return -1;

	if(dp1[x] != -1) return dp1[x];
	
	bool jumped = false;

	int max_ch = -1;
	max_ch = max(max_ch, max_jumps(jump[x].l1));
	max_ch = max(max_ch, max_jumps(jump[x].l2));
	max_ch = max(max_ch, max_jumps(jump[x].r1));
	max_ch = max(max_ch, max_jumps(jump[x].r2));

	dp1[x] = max_ch + 1;
	return dp1[x];
}

int max_jumps(int x, int y) {
	if(x == y) return 0;

	if(x < y) {
		if(jump[x].r1 == -1) return -1;
		if(jump[x].r2 == -1) {
			int mj = max_jumps(jump[x].r1, y);
			return mj == -1 ? -1 : mj + 1;
		} else {
			if(jump[x].r1 <= y && y <= jump[x].r2) return 1;
			if(jump[x].r1 >= y) {
				int mj = max_jumps(jump[x].r1, y);
				return mj == -1 ? -1 : mj + 1;
			} else {
				int mj = max_jumps(jump[x].r2, y);
				return mj == -1 ? -1 : mj + 1;
			}
		}
	} else {
		if(jump[x].l1 == -1) return -1;
		if(jump[x].l2 == -1) {
			int mj = max_jumps(jump[x].l1, y);
			return mj == -1 ? -1 : mj + 1;
		} else {
			if(jump[x].l2 <= y && y <= jump[x].l1) return 1;
			if(jump[x].l1 <= y) {
				int mj = max_jumps(jump[x].l1, y);
				return mj == -1 ? -1 : mj + 1;
			} else {
				int mj = max_jumps(jump[x].l2, y);
				return mj == -1 ? -1 : mj + 1;
			}
		}
	}
}
