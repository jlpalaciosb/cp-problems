#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

typedef vector<int> vi;

class FenwickTree {
private:
	vi ft; // ft[i] stores the cumulative frequency of elements {i-LSOne(i)+1, i-LSOne(i)+2, i-LSOne(i)+3, .., i}
	int n;

	int LSOne(int i) {
		return (i & (-i));
	}
public:
	FenwickTree(int _n) {
		n = _n;
		ft.assign(n + 1, 0); // init n + 1 zeroes
	}

	FenwickTree(vi v, int _n) {
		n = _n;
		ft.assign(n + 1, 0); // init n + 1 zeroes
		for (int i = 0; i < v.size(); i++) // this is O(m log n)
			adjust(v[i], 1);
	}

	int rsq(int b) { // returns RSQ(1, b)
		int sum = 0;
		while(b != 0) {
			sum += ft[b];
			b -= LSOne(b);
		}
		return sum;
	}

	int rsq(int a, int b) { // returns RSQ(a, b)
		if(a == 1)
			return rsq(b);
		else
			return rsq(b) - rsq(a - 1);
	}

	// adjusts value of the k-th element by v (v can be +ve/inc or -ve/dec) // incrementa la frecuencia de k
	void adjust(int k, int v) {
		while(k <= n) {
			ft[k] += v;
			k += LSOne(k);
		}
	}

	// Find the smallest index with a given cumulative frequency, return -1 if is not found
	int min(int cf) {
		if(rsq(n) < cf)
			return -1;

		if(n == 1)
			return n;

		int a = 1, b = n;
		int mid, cfm;

		while(true) {
			mid = (a + b) / 2;
			cfm = rsq(mid);
			if(cfm < cf)
				a = mid;
			else
				b = mid;
			if(a == b - 1)
				break;
		}

		if(rsq(a) < cf)
			return a + 1;
		else
			return a;
	}

	void showTable() {
		cout << "Index   CF" << endl;
		cout << "----------" << endl;
		for(int i = 1; i <= n; ++i)
			printf("%-8d%d\n", i, rsq(i));
		cout << "----------" << endl;
	}
};

int main() {
	vi v = {2, 4, 5, 5, 6, 6, 6, 9, 9, 9, 10};
	FenwickTree ft(v, 10);

	while(true) {
		system("clear");
		int cf;
		ft.showTable();
		cout << "CF = ";
		cin >> cf; getchar();
		cout << "min = " << ft.min(cf) << endl;
		getchar();
	}
	return 0;
}
