#include <iostream>
#define debug(x) cerr << #x << " = " << x << endl

using namespace std;

// Sumatoria de la prog arit desde a hasta b con paso c
int summ(int a, int b, int c = 1) {
	return (a + b) * (b - a + c) / (2 * c);
}

int main() {
	int n, v;
	cin >> n >> v;

	int r = (n - 1) - min(n - 1, v);
	int cost = (n - 1) - r;
	if(r > 0) {
		cost += summ(2, r + 1);
	}

	cout << cost << endl;

	return 0;
}
