#include <iostream>
#include <vector>
#include <list>

using namespace std;

typedef vector<list<int>> graph;

int size(int u, graph & a_graph, vector<bool> & visitas);

int C = 0;

int main() {
	int n;
	cin >> n;

	graph the_graph(n + 1);
	vector<bool> visitas(n + 1, false);

	int u, v;
	for(int i = 1; i < n; i++) {
		cin >> u;
		cin >> v;
		the_graph[u].push_back(v);
		the_graph[v].push_back(u);
	}

	int s = size(1, the_graph, visitas);

	if(s == 0)
		cout << --C << endl;
	else
		cout << -1 << endl;

	return 0;
}

int size(int u, graph & a_graph, vector<bool> & visitas) {
	int s = 1;
	visitas[u] = true;

	for(list<int>::iterator it = a_graph[u].begin(); it != a_graph[u].end(); ++it) {
		int v = *it;
		if(visitas[v] == false) {
			s += size(v, a_graph, visitas);
		}
	}

	if(s % 2 == 0) {
		C++;
		return 0;
	} else {
		return s;
	}
}
