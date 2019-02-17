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

double p, q, r, s, t, u;

double f(double x) {
	return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

int main() {
	cout.precision(4);
	while(cin >> p >> q >> r >> s >> t >> u) {
		if(f(0) * f(1) > 0) cout << "No solution" << endl;
		else { // asumimos que hay una única solución
			double a, b, x;
			if(f(0) < 0) {
				a = 0; b = 1;
			} else {
				b = 0; a = 1;
			}
			for(int i = 0; i < 25; i++) {
				x = (a + b) / 2;
				if(f(x) > 0) b = x;
				else a = x;
			}
			cout << fixed << x << endl;
		}
	}
	return 0;
}
