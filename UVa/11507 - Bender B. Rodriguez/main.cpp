#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	map<vector<int>, string> direccion;
	direccion[{1, 0, 0}] = "+x";
	direccion[{-1, 0, 0}] = "-x";
	direccion[{1, 1, 0}] = "+y";
	direccion[{1, -1, 0}] = "-y";
	direccion[{1, 0, 1}] = "+z";
	direccion[{1, 0, -1}] = "-z";

	while(true) {
		int l;
		cin >> l;
		if(l == 0) break;

		vector<int> punta = {1, 0, 0}; //vector que representa la punta

		for(int i = 1; i < l; ++i) {
			string inst;
			cin >> inst;

			if(inst == "No") continue;

			int index = inst[1] == 'y' ? 1 : 2;
			int index_c = inst[1] == 'y' ? 2 : 1;
			int signo = inst[0] == '+' ? 1 : -1;

			if(punta[index_c] != 0) continue;

			punta[index] += signo * punta[0];
			punta[0] = 1;
			if(abs(punta[index]) == 2) {
				punta[index] = 0;
				punta[0] = -1;
			}
		}
		cout << direccion[punta] << endl;
	}

	return 0;
}
