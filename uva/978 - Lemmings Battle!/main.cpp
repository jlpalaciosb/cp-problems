#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

typedef multiset<int> MSI;
typedef MSI::iterator MSIit;

void show_army(const MSI &army);

int gf[100001], bf[100001]; /* green an blue fighters */

int main() {
	int N;
	cin >> N;
	for(int i = 1; i <= N; ++i) {
		int B, SG, SB;
		MSI gs;
		MSI bs;

		cin >> B >> SG >> SB;

		gs.clear();
		for(int j = 1; j <= SG; ++j) {
			int ags;
			cin >> ags;
			gs.insert(-ags);
		}

		bs.clear();
		for(int j = 1; j <= SB; ++j) {
			int abs;
			cin >> abs;
			bs.insert(-abs);
		}

		while(!gs.empty() && !bs.empty()) {
			int nf = min(min(B, (int)gs.size()), (int)bs.size());

			MSIit itg = gs.begin(), itb = bs.begin();
			for(int j = 0; j < nf; ++j) {
				gf[j] = -(*itg);
				bf[j] = -(*itb);
				gs.erase(itg++);
				bs.erase(itb++);
			}
			
			for(int j = 0; j < nf; ++j) {
				if(gf[j] > bf[j]) {
					gs.insert(-(gf[j] - bf[j]));
				} else if(bf[j] > gf[j]) {
					bs.insert(-(bf[j] - gf[j]));
				}
			}
		}

		if(!bs.empty()) {
			cout << "blue wins" << endl;
			show_army(bs);
		} else if(!gs.empty()) {
			cout << "green wins" << endl;
			show_army(gs);
		} else {
			cout << "green and blue died" << endl;
		}
		
		if(i != N) {
			cout << endl;
		}
	}
	return 0;
}

void show_army(const MSI &army) {
	for(MSIit it = army.begin(); it != army.end(); ++it) {
		cout << -(*it) << endl;
	}
}
