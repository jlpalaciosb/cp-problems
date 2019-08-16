#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

class UnionFind {
	private:
		vi p, rank, s;
		int n;
	public:
		UnionFind(int N) {
			rank.assign(N, 0);
			p.assign(N, 0);
			for (int i = 0; i < N; i++)
				p[i] = i;
			s.assign(N, 1);
			n = N;
		}
		int findSet(int i) {
			return (p[i] == i) ? i : (p[i] = findSet(p[i]));
		}
		bool isSameSet(int i, int j) {
			return findSet(i) == findSet(j);
		}
		void unionSet(int i, int j) {
			if (!isSameSet(i, j)) {   // from different set
				int x = findSet(i), y = findSet(j);
				if (rank[x] > rank[y]) {   // rank keeps the tree short
					p[y] = x;
					s[x] += s[y];
				} else {
					p[x] = y;
					s[y] += s[x];
					if (rank[x] == rank[y])
						rank[y]++;
				}
				n -= 1;
			}
		}
		int sizeOfSet(int i) {
			return s[findSet(i)];
		}
		int numDisjointSets() {
			return n;
		}
};

int main() {
	UnionFind ufds(8);
	ufds.unionSet(2, 6);
	ufds.unionSet(3, 6);
	cout << ufds.sizeOfSet(2) << endl;
	cout << ufds.numDisjointSets() << endl;
	return 0;
}
