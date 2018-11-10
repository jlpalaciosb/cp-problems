#include <iostream>
#include <vector>
#include <map>
#define INF 1000000000
#define UNDEF -1

using namespace std;

typedef vector<int> VI;
typedef map<vector<int>,int> MVII;

MVII costs;

int main() {
	int i = 0;
	int j = 0;
	costs[{i, j}] = 33;
	costs.clear();
	cout << costs[{i, j}] << endl;
	return 0;
}