// Buena implementacion pero WA

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define debug(x) cerr << #x << " = " << x << endl
using namespace std;

/* Estructura */
vector<vector<int>> vs;
class Compare {
	public: bool operator() (int v1, int v2) {
		return
			(vs[v1].back() > vs[v2].back()) ||
			(vs[v1].back() == vs[v2].back() && vs[v1].size() > vs[v2].size())
		;
	}
};
priority_queue<int, vector<int>, Compare> pq; // store the index of the vector in the pq

int main() {
	while(true) {
		int n; cin >> n; if(n == 0) break;
		vector<int> v;

		v.clear();
		for(int i = 0; i < n; i++) {
			int a; cin >> a;
			v.push_back(a);
		}
		sort(v.begin(), v.end());

		vs.clear();
		while(!pq.empty()) pq.pop();

		vs.push_back({v[0]});
		pq.push(vs.size() - 1);
		for(int i = 1; i < n; i++) {
			int min = pq.top();
			if(vs[min].back() < v[i]) {
				pq.pop();
				vs[min].push_back(v[i]);
				pq.push(min);
			} else {
				vs.push_back({v[i]});
				pq.push(vs.size() - 1);
			}
		}

		cout << vs.size() << endl;
		while(!pq.empty()) {
			int min = pq.top();
			for(int i = 0; i < vs[min].size(); i++) {
				cout << vs[min][i] << " ";
			}
			cout << endl;
			pq.pop();
		}
		cout << endl;
	}
	return 0;
}
