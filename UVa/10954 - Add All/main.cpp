#include <iostream>
#include <queue>

using namespace std;

int tmp;

int main() {
	int n;
	while(cin >> n, n > 0) {
		priority_queue<int, vector<int>, greater<int>> mh; /* min heap */

		for(int i = 0; i < n; ++i) {
			cin >> tmp;
			mh.push(tmp);
		}

		int cost = 0;
		while(mh.size() > 1) {
			int s1 = mh.top();
			mh.pop();
			int s2 = mh.top();
			mh.pop();
			int sum = s1 + s2;
			cost += sum;
			mh.push(sum);
		}

		cout << cost << endl;

		mh.pop(); /* clear */
	}

	return 0;
}
