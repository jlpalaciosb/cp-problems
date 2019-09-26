#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, bl, k, A, B;
int pos[100010];

int number(int p1, int p2) {
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

ll destroy(int p1, int p2) {
	int l = p2 - p1 + 1;
	int mid = p1 + l / 2 - 1;
	int num = number(p1, p2);

	if(num == 0) return A;
	
	if(l == 1) return B * num; // num can be greater than 1

	return min((ll)B * num * l, destroy(p1, mid) + destroy(mid + 1, p2));
}

int main() {
	cin >> n >> k >> A >> B;
	bl = 1 << n;

	for(int i = 0; i < k; i++) cin >> pos[i];
	sort(pos, pos + k);

	cout << destroy(1, bl) << endl;

	return 0;
}
