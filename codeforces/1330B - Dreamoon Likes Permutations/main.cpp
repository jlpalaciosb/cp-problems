#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int n; vi a;

vi flag1, count1, isp1(200001);
void process1() {
	flag1.assign(n + 1, 0); count1.assign(n + 1, 0); isp1.assign(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		count1[i] = count1[i - 1];
		if (a[i] < i && flag1[a[i]] == 0) count1[i]++;
		flag1[a[i]] = 1;
		if (flag1[i] == 1) count1[i]++;
	}
	for (int i = 1; i <= n; i++) {
		if (count1[i] == i) isp1[i] = 1;
	}
}

vi flag2, count2, isp2(200001);
void process2() {
	flag2.assign(n + 1, 0); count2.assign(n + 1, 0); isp2.assign(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		count2[i] = count2[i - 1];
		if (a[i] < i && flag2[a[i]] == 0) count2[i]++;
		flag2[a[i]] = 1;
		if (flag2[i] == 1) count2[i]++;
	}
	for (int i = 1; i <= n; i++) {
		if (count2[i] == i) isp2[n - i + 1] = 1;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		cin >> n; a.resize(n + 2);
		for (int i = 1; i <= n; i++) cin >> a[i];

		process1();
		reverse(a.begin(), a.end());
		process2();

		int k = 0;
		for (int i = 1; i <= n - 1; i++) if (isp1[i] && isp2[i + 1]) k++;
		cout << k << endl;

		for (int i = 1; i <= n - 1; i++) {
			if (isp1[i] && isp2[i + 1]) {
				cout << i << ' ' << (n - i) << endl;
			}
		}
	}

	return 0;
}
