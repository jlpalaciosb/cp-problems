#include <bits/stdc++.h>

using namespace std;

int n, k, pos[100010];

int number1(int p1, int p2) {
	if(pos[k - 1] < p1 || pos[0] > p2) return 0;

	int i = 0, j = k - 1;
	while(j - i > 1) {
		if(i == j - 1) break;
		int mid = (i + j) / 2;
		if(pos[mid] < p1) {
			i = mid;
		} else {
			j = mid;
		}
	}
	int a = pos[i] >= p1 ? i : j;

	i = 0; j = k - 1;
	while(j - i > 1) {
		int mid = (i + j) / 2;
		if(pos[mid] > p2) {
			j = mid;
		} else {
			i = mid;
		}
	}
	int b = pos[j] <= p2 ? j : i;

	return b - a + 1;
}

int number2(int p1, int p2) {
	int c = 0;
	for(int i = 0; i < k; i++) if(p1 <= pos[i] && pos[i] <= p2) c++;
	return c;
}

int main() {
	cin >> n >> k;

	for(int i = 0; i < k; i++) cin >> pos[i];
	sort(pos, pos + k);

	int tc = 1000;
	while(tc--) {
		int p1 = rand() % n;
		int p2 = p1 + rand() % (n - p1);
		if(number1(p1, p2) != number2(p1, p2)) {
			cout << "doesnt work" << endl;
			return 1;
		}
	}
	cout << "apparently it works" << endl;
	return 0;
}
