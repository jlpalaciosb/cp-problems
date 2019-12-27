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
typedef vector<int> vi;
typedef long long ll; typedef long double ld;
/**************************************************************/

//ACCEPTED! (con un poco de ayuda del tutorial)

int main() {
	int n, k, m; cin >> n >> k >> m;
	vi arr(n);
	ll sum = 0;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	sort(arr.begin(), arr.end());

	ld maxavr = (ld)sum / (ld)n;
	ll sumd = 0;
	for(int d = 0; d < n && d <= m; d++) {
		if(d > 0) sumd += arr[d - 1];
		ll rsum = sum - sumd;
		int rn = n - d;
		int rm = m - d;
		rsum += min((ll)rm, (ll)rn * k);
		ld avr = (ld)rsum / (ld)rn;
		maxavr = max(maxavr, avr);
	}

	cout.precision(20);
	cout << maxavr << endl;

	return 0;
}
