#include <iostream>
#include <queue>
#include <vector>
#define INF 1000000
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vi::iterator vi_it;
typedef vvi::iterator vvi_it;
typedef pair<double,int> pdi; // first: distancia al origen, second: vértice

class cmp {
	public: int operator() (const pdi &p1, const pdi &p2) {
		return p1.first < p2.first;
	}
};

int t, n, m, p; // variables del problema
double edge[51][51]; // distancia entre cada par de vértice
vector<double> dist(51); // distancia de cada vértice al origen (0)
vector<double> treasure(51); // valor del tesoro en el vértice v
vvi graph(51); // grafo como lista de adyacencia
priority_queue<pdi, vector<pdi>, cmp> pq;

// procesar la distancia de todos los vértices al origen
void dijkstra() {
	dist.assign(n + 1, (double)INF);
	dist[0] = 0;
	pq.push(make_pair(0, 0));
	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		for (vi_it it = graph[u].begin(); it != graph[u].end(); it++) {
			int v = *it;
			double d = dist[u] + edge[u][v];
			if (d < dist[v]) {
				dist[v] = d;
				pq.push(make_pair(d, v));
			}
		}
	}
}

// inicializar los datos
void init() {
	cin >> n >> m;
	graph.assign(n + 1, {});
	for (int i = 0; i < m; i++) {
		int u, v; double d;
		cin >> u >> v >> d;
		graph[u].push_back(v);
		graph[v].push_back(u);
		edge[u][v] = edge[v][u] = d;
	}

	treasure.assign(n + 1, 0);
	cin >> p;
	for (int i = 0; i < p; i++) {
		int v; cin >> v;
		cin >> treasure[v];
	}

	dijkstra();
}

// v: vértice
// mask: me dice que tesoros ya fueron recogidos
int val(int v, int mask) {

}

int main() {
	cin >> t;
	while (t--) {
		init();
		cout << val(0, 0) << endl;
	}
	return 0;
}
