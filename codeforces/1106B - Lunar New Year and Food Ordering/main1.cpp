#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n, m, remain[100010], cost[100010];

typedef struct { int cost, index; } cost_st;

class compare {
	public: bool operator() (const cost_st & c1, const cost_st & c2) {
		return c1.cost > c2.cost || (c1.cost == c2.cost && c1.index > c2.index);
	}
};

priority_queue<cost_st, vector<cost_st>, compare> cheap;

int main() {
	cin >> n >> m;

	for(int i = 1; i <= n; i++) cin >> remain[i];
	
	for(int i = 1; i <= n; i++) {
		cin >> cost[i];
		cost_st cs = {cost[i], i};
		cheap.push(cs);
	}

	for(int i = 1; i <= m; i++) {
		int kind, number; cin >> kind >> number;
		long long total = 0;
		int serve = kind;

		while(number > 0 && !cheap.empty()) {
			if(remain[serve] >= number) {
				remain[serve] -= number;
				total += (long long)number * (long long)cost[serve];
				number = 0;
			} else {
				total += (long long)remain[serve] * (long long)cost[serve];
				number -= remain[serve];
				remain[serve] = 0;
				if(remain[cheap.top().index] == 0) cheap.pop();
				if(!cheap.empty()) serve = cheap.top().index;
			}
		}

		if(number > 0) total = 0;

		cout << total << endl;
	}

	return 0;
}
