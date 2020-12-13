#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#define UNDEF -1
#define INF 1000000000000

using namespace std;

typedef vector<list<pair<int,int>>> graph;

int dijkstra(graph & a_graph, int s, int d);

int main() {
	int V, E;
	cin >> V;
	cin >> E;
	
	graph a_graph(V+1);

	int a, b, w;
	for(int i = 1; i <= E; ++i) {
		cin >> a;
		cin >> b;
		cin >> w;
		a_graph[a].push_back(pair<int,int>(b, w));
		a_graph[b].push_back(pair<int,int>(a, w));
	}

	dijkstra(a_graph, 1, V);

	return 0;
}

//se puede optimizar, pero ya usa una priority_queue
int dijkstra(graph & a_graph, int s, int d) {
	priority_queue<pair<int,int>> pq;

	vector<unsigned long long> dist(a_graph.size(), INF); /* OJO: los pesos son menores a 10^6, pero pueden haber 10^5 vertices y la suma de los pesos (la distancia) podría ser mucho mayor (10^11), por eso unsigned long long */
	vector<int> through(a_graph.size(), UNDEF);
	vector<bool> visited(a_graph.size(), false);

	dist[s] = 0;
	pq.push(make_pair(-dist[s], s)); //menor distancia -> mayor prioridad, por eso el signo menos

	while(!pq.empty() && !(d == pq.top().second)) {
		int u = pq.top().second;
		pq.pop();

		if(visited[u]) continue;
		visited[u] = true;

		list<pair<int,int> >::iterator it;
		for(it = a_graph[u].begin(); it != a_graph[u].end(); ++it) {
			int v = (*it).first;
			int weight = (*it).second;

			if(visited[v]) continue;

			if(dist[v] > dist[u] + weight) {
				dist[v] = dist[u] + weight;
				through[v] = u;
				pq.push(make_pair(-dist[v], v));
			}
		}
	}

	if(through[d] == UNDEF) {
		cout << -1 << endl;
	} else {
		/* Imprimimos el camino */
		stack<int> path;
		int v = d;
		do {
			path.push(v);
			v = through[v];
		} while(v != UNDEF);
		while(!path.empty()) {
			cout << path.top() << " ";
			path.pop();
		}
	}
}
