#include <iostream>
#define IN 0
#define OUT 1
using namespace std;

struct edge {
	int type, capacity, monkey;
	edge *prev, *next;
	edge(t, m) {
		type = t;
		capacity = 1;
		monkey = m;
		prev = next = NULL;
	}
}

int n, m;
vector<edge*> seconds_in[50001];
vector<edge*> seconds_out[50001];
bool free[50001];

void construct() {
	for (int i = 0; i <= 50000; ++i) {
		seconds_in[i].clear();
		seconds_out[i].clear();
		free[i] = true;
	}

	for (int i = 1; i <= n; ++i) {
		int v, a, b; cin >> v >> a >> b;
		free[a] = free[b] = false;
		for (int j = a; j <= b; ++j) {
			edge *e1 = NULL; if (j < b) e1 = new edge(IN, i);
			edge *e2 = NULL; if (j > a) e2 = new edge(OUT, i);
			if (j > a) {
				e1->prev = seconds_in[j - 1].back();
				e1->prev = seconds_in[j - 1].back();
			}
			if (j < b) {
				e2->next = seconds_out[j - 1].back();
				e2->next = seconds_out[j - 1].back();
			}
			if (e1 != NULL) seconds_in[j].push_back(e1);
			if (e2 != NULL) seconds_out[j].push_back(e2);
		}
	}
	compress();
}

void compress() {
	for (int i = 0; i <= 50000; ++i) {
		if (free[i]) {
			for (int j = 0; j < seconds_in[i].size(); ++j) {
				if (seconds_in[i][j]->prev != NULL) {
					seconds_in[i][j]->prev->capacity += seconds_in[i][j]->capacity;

				}
			}
		}
	}
}

// primero computar free
int main() {
	while (true) {
		cin >> n; if (n == 0) break; cin >> m;
		construct();
	}
	return 0;
}
