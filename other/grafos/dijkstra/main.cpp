#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#define UNDEF -1
#define INF 1000000000

using namespace std;

typedef vector<list<pair<int,int> > > graph;

int dijkstra(graph & a_graph, int s, int d);

int main() {
	int V, E;
	cin >> V;
	cin >> E;
	
	graph a_graph(V);

	int ver, nei, wei;
	for(int i = 0; i < E; ++i) {
		cin >> ver;
		cin >> nei;
		cin >> wei;
		a_graph[ver].push_back(pair<int,int>(nei, wei));
	}

	cout << dijkstra(a_graph, 0, V-1) << endl;

	return 0;
}

//se puede optimizar, pero ya usa una priority_queue
int dijkstra(graph & a_graph, int s, int d) {
	priority_queue<pair<int,int> > pq;

	vector<int> dist(a_graph.size(), INF);
	vector<bool> visited(a_graph.size(), false);

	dist[s] = 0;
	pq.push(make_pair(-dist[s], s)); //menor distancia -> mayor prioridad, por eso el signo menos

	while(!pq.empty() && !(d == pq.top().second)) {
		int u = pq.top().second;
		pq.pop();

		if(visited[u])
			continue;
		visited[u] = true;

		list<pair<int,int> >::iterator it;
		for(it = a_graph[u].begin(); it != a_graph[u].end(); ++it) {
			int v = (*it).first;
			int weight = (*it).second;

			if(visited[v]) continue;

			if(dist[v] > dist[u] + weight) {
				dist[v] = dist[u] + weight;
				pq.push(make_pair(-dist[v], v));
			}
		}
	}

	return dist[d];
}
