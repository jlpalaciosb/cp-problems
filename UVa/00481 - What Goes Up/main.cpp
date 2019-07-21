#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

int A[110000], len = 0; // el array y su longitud
int L[110000], lis_len = 0; // el vector siempre ordenado y su longitud (= len(LIS))
int Lind[110000]; // Lind[i] = indice en A de L[i]
int pred[110000]; // pred[i] = indice en A del predecesor de A[i] en la LIS

int main() {
	memset(pred, -1, sizeof pred);

	while (cin >> A[len]) len++;

	for (int i = 0; i < len; i++) {
		int lbi = lower_bound(L, L + lis_len, A[i]) - L;
		L[lbi] = A[i];
		Lind[lbi] = i;
		if (lbi > 0) pred[i] = Lind[lbi - 1];
		if (lbi == lis_len) lis_len++;
	}

	stack<int> stk;
	int ind = Lind[lis_len - 1];
	while (ind != -1) {
		stk.push(A[ind]);
		ind = pred[ind];
	}

	cout << lis_len << endl << '-' << endl;
	while (!stk.empty()) {
		cout << stk.top() << endl;
		stk.pop();
	}

	return 0;
}
