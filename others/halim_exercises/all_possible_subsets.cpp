#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n = 5, r, i; // n = 20 in the exercise, just set it 20
	vector<bool> sa(n); // "selection array" // se puede usar un bitmask para representar cada uno de los subsets posibles (ver uva 12455)
	for(r = 1; r <= n; r++) { // r: subset size
		fill(sa.begin(), sa.end() - r, false); fill(sa.end() - r, sa.end(), true);
		do {
			for(i = 0; i < n; i++) {
				if(sa[i]) cout << i << " ";
			}
			cout << endl;
		} while(next_permutation(sa.begin(), sa.end()));
	}
	return 0;
}
