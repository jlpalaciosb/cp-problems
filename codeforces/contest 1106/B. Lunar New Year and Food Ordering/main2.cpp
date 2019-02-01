/* Apparently this should be faster, but it had the same execution time as `main1.cpp` */

#include <iostream>
#include <algorithm>

using namespace std;

typedef struct { int cost, index; } cost_st;
bool compare(const cost_st & c1, const cost_st & c2) {
	return c1.cost < c2.cost || (c1.cost == c2.cost && c1.index < c2.index);
}

int n, m, remain[100010], cost[100010];
cost_st cheap[100010];

int main() {
	cin >> n >> m;

	for(int i = 1; i <= n; i++) cin >> remain[i];
	
	for(int i = 1; i <= n; i++) {
		cin >> cost[i];
		cheap[i] = {cost[i], i};
	}
	sort(cheap + 1, cheap + n + 1, compare);
	int next_cheap = 1;

	for(int i = 1; i <= m; i++) {
		int kind, number; cin >> kind >> number;
		long long total = 0;
		int serve = kind;

		while(number > 0 && next_cheap <= n) {
			if(remain[serve] >= number) {
				total += (long long)number * (long long)cost[serve];
				remain[serve] -= number;
				number = 0;
			} else {
				total += (long long)remain[serve] * (long long)cost[serve];
				number -= remain[serve];
				remain[serve] = 0;
				if(remain[cheap[next_cheap].index] == 0) next_cheap++;
				if(next_cheap <= n) serve = cheap[next_cheap].index;
			}
		}

		if(number > 0) total = 0;

		cout << total << endl;
	}

	return 0;
}
