#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int n, m; cin >> n >> m;

	vector<vector<int>> graph(n + 10);
	while(m--) {
		int u, v; cin >> u >> v;
		if(u == v) continue;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	priority_queue<int, vector<int>, greater<int>> pq;
	vector<bool> enqueued(n + 10, false);

	pq.push(1);
	enqueued[1] = true;

	while(!pq.empty()) {
		int u = pq.top(); pq.pop();
		cout << u << " ";
		for(vector<int>::iterator it = graph[u].begin(); it != graph[u].end(); ++it) {
			int v = *it;
			if(!enqueued[v]) {
				pq.push(v);
				enqueued[v] = true;
			}
		}
	}

	return 0;
}
