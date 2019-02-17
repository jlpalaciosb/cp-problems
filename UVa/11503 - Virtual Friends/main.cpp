#include <iostream>
#include <unordered_map>

using namespace std;

typedef unordered_map<string, string> mss;
typedef unordered_map<string, int> msi;

class UnionFind {
	private:
		mss rep;
		msi rank;
		msi size;
	public:
		UnionFind() {
			;
		}
		string findSet(string s) {
			if(rep.find(s) == rep.end()) {
				return "";
			} else {
				if(rep[s] == s) {
					return s;
				} else {
					rep[s] = findSet(rep[s]);
					return rep[s];
				}
			}
		}
		void unionSet(string s1, string s2) {
			string set1 = findSet(s1);
			string set2 = findSet(s2);

			if(set1 == "" && set2 == "") { // nuevo set
				rep[s1] = s1;
				rep[s2] = s1;
				rank[s1] = 1;
				size[s1] = 2;
			} else if(set1 == "" && set2 != "") { // s1 nuevo
				rep[s1] = set2;
				size[set2] += 1;
				rank[set2] += 1;
			} else if(set1 != "" && set2 == "") { // s2 nuevo
				rep[s2] = set1;
				size[set1] += 1;
			} else if(set1 != set2) { // s1 y s2 ya estan, unimos si pertenecen a conjuntos distintos
				if(rank[set1] > rank[set2]) {   // rank keeps the tree short
					rep[set2] = set1;
					size[set1] += size[set2];
				} else {
					rep[set1] = set2;
					size[set2] += size[set1];
					if(rank[set1] == rank[set2]) {
						rank[set2] += 1;
					}
				}
			}
		}
		int sizeOfSet(string s) {
			return size[findSet(s)];
		}
		void clear() {
			rep.clear();
			rank.clear();
			size.clear();
		}
};

int main() {
	int ntc;
	cin >> ntc;
	for(int i = 1; i <= ntc; ++i) {
		int F;
		UnionFind sn; // social network

		cin >> F;
		sn.clear();

		for(int j = 1; j <= F; ++j) {
			string f1, f2;
			cin >> f1 >> f2;
			sn.unionSet(f1, f2);
			cout << sn.sizeOfSet(f1) << endl;
		}
	}
	return 0;
}
