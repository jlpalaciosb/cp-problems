#include <iostream>
#include <unordered_map>
#include <cstring>
#include <list>
#include <queue>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef list<string> ls;
typedef ls::iterator lsIt;
typedef vi::iterator viIt;

int n, req[100];
string name[100];
unordered_map<string, int> number;
vvi graph;

void read() {
	graph.clear(); graph.resize(n);
	number.clear();
	memset(req, 0, sizeof req);
	for (int v = 0; v < n; v++) {
		cin >> name[v];
		number[name[v]] = v;
	}
	int m; cin >> m;
	for (int e = 0; e < m; e++) {
		string n1, n2; cin >> n1 >> n2;
		graph[number[n1]].push_back(number[n2]);
		req[number[n2]]++;
	}
}

ls lis;
priority_queue<int, vector<int>, greater<int>> pq;

void solve() {
	lis.clear();
	for (int v = 0; v < n; v++) if (req[v] == 0) pq.push(v);
	while (!pq.empty()) {
		int u = pq.top(); pq.pop();
		lis.push_back(name[u]);
		for (viIt it = graph[u].begin(); it != graph[u].end(); it++) {
			int v = *it;
			req[v]--;
			if (req[v] == 0) pq.push(v);
		}
	}
}

int main() {
	int tc = 0;
	while ((cin >> n) && ++tc) {
		read();
		solve();
		printf("Case #%d: Dilbert should drink beverages in this order:", tc);
		for (lsIt it = lis.begin(); it != lis.end(); it++) cout << ' ' << *it;
		cout << '.' << endl << endl;
	}
	return 0;
}
