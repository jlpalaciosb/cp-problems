#include <iostream>
#include <queue>

using namespace std;

int main() {
	priority_queue<string> pq;
	string s;
	bool terminado = false;

	while(not terminado) {
		getline(cin, s);
		if(s == "")
			terminado = true;
		else
			pq.push(s);
	}

	while(not pq.empty()) {
		cout << pq.top() << endl;
		pq.pop();
	}
	
	return 0;
}