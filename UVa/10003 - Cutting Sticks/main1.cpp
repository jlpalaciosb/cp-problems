#include <iostream>
#include <vector>
#include <map>
#define INF 1000000000
#define UNDEF -1

using namespace std;

typedef vector<int> VI;
typedef map<vector<int>,int> MVII;
typedef MVII::iterator MVIIit;

VI cuts;
MVII costs;

int cost(int i, int f, int cl, int cr);

int main() {
	cuts.resize(1000);

	while(true) {
		int l; cin >> l;
		int n; cin >> n;
		
		if(l == 0) {
			break;
		}

		for(int i = 0; i < n; ++i) {
			cin >> cuts[i];
		}
		costs.clear();

		cout << "The minimum cutting is " << cost(0, l, 0, n-1) << "." << endl;
	}

	return 0;
}

int cost(int xi, int xf, int cl, int cr) {
	MVIIit solution = costs.find({xi,xf});
	if(solution != costs.end()) {
		return solution->second;
	} else {
		if(cl > cr) { //no hay cortes
			costs[{xi,xf}] = 0;
			return 0;
		}else if(cl == cr) { //uno solo corte
			costs[{xi,xf}] = xf - xi;
			return xf - xi;
		} else { //hay más de un corte posible
			int min = INF;
			for(int i = cl; i <= cr; ++i) {
				int costi = cost(xi, cuts[i], cl, i - 1) + cost(cuts[i], xf, i + 1, cr);
				if(costi < min) {
					min = costi;
				}
			}
			costs[{xi,xf}] = (xf - xi) + min;
			return (xf - xi) + min;
		}
	}
}
