#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

class SegmentTree {
private:
	vi sum, A;
	int n;

	int left(int p) {
		return p << 1;
	}

	int right(int p) {
		return (p << 1) + 1;
	}

	void build(int p, int L, int R) {
		if(L == R) {
			sum[p] = A[L];
		} else {
			build(left(p), L, (L + R) / 2);
			build(right(p), (L + R) / 2 + 1, R);
			sum[p] = sum[left(p)] + sum[right(p)];
		}
	}

	int rsq(int p, int L, int R, int i, int j) {
		if(i > R || j < L) {
			return -1;  // segmento actual fuera del rango solicitado
		}

		if(L >= i && R <= j) {
			return sum[p];  // segmento actual dentro del rango solicitado
		}
		
		// compute the sum in the left and right part of the interval
		int s1 = rsq(left(p), L, (L + R) / 2, i, j);
		int s2 = rsq(right(p), (L + R) / 2 + 1, R, i, j);

		if(s1 == -1) {
			return s2;
		} else if(s2 == -1) {
			return s1;
		} else {
			return s1 + s2;
		}
	}
public:
	SegmentTree(const vi &_A) {
		A = _A;
		n = (int)A.size();
		sum.resize(4 * n);
		build(1, 0, n - 1);
	}

	int rsq(int i, int j) {
		return rsq(1, 0, n - 1, i, j);
	}
};

int main() {
	SegmentTree st({23, 45, 51, 89, 0, 1});
	cout << st.rsq(2, 4) << endl;
	return 0;
}
