#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define INF 1000000000
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vvi::iterator vvi_it;

int t, n, m, p;
float edge[51][51];
vector<double> dist(51);
vvi graph;

int main() {
	dist.assign(dist.size(), (double)INF);
	cout << dist.size() << endl;
	cout << dist[20] << endl;
	vi v = {1, 2};
	cout << v[1] << endl;
	v.resize(0);
	v.resize(2);
	cout << v[1] << endl;
	return 0;
}
