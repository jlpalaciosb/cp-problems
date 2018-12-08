#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

typedef struct {
	int dest;
} cargo;

int main() {
	int SET;
	cin >> SET;
	for(int i = 1; i <= SET; ++i) {
		int N, S, Q;
		cin >> N >> S >> Q;
		vector<queue<cargo>> queues = vector<queue<cargo>>(N + 1);
		stack<cargo> carrier = stack<cargo>();
		int time = 0;
		int pending = 0;

		for(int j = 1; j <= N; ++j) {
			int q;
			cin >> q;
			for(int k = 1; k <= q; ++k) {
				int dest;
				cin >> dest;
				cargo carg = {dest};
				queues[j].push(carg);
				pending += 1;
			}
		}

		int current = 1;
		while(pending > 0) {
			// descarga
			while(carrier.size() > 0) {
				if(carrier.top().dest == current) {
					pending -= 1;
					carrier.pop();
					time += 1;
				} else {
					if(queues[current].size() < Q) {
						queues[current].push(carrier.top());
						carrier.pop();
						time += 1;
					} else {
						break;
					}
				}
			}

			// carga
			while(carrier.size() < S && queues[current].size() > 0) {
				carrier.push(queues[current].front());
				queues[current].pop();
				time += 1;
			}

			// pasar a la siguiente estación
			if(pending > 0) {
				current += 1;
				if(current > N) {
					current = 1;
				}
				time += 2;
			}
		}

		cout << time << endl;
	}
	return 0;
}
