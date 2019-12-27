//WA

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
	cout.precision(20);

	int n, k, m;
	ll sum = 0;
	ld avr;

	cin >> n >> k >> m;

	vector<int> arr(n);
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	sort(arr.begin(), arr.end());

	avr = (ld)sum / (ld)n;
	int opr = 0, ops = 0;
	int nn = n;
	int rem = 0;

	while(opr + ops < m && rem < n - 1) {
		if((ld)arr[rem] < avr) {
			//cout << "eliminar" << endl;
			sum -= arr[rem];
			nn--;
			rem++;
			avr = (ld)sum / (ld)nn;
			opr++;
		} else if(ops < k * nn) {
			//cout << "sumar" << endl;
			sum++;
			avr = (ld)sum / (ld)nn;
			ops++;
		} else {
			break;
		}
	}

	//cout << avr << endl;

	while(opr + ops < m && ops < k * nn) {
		sum++;
		ops++;
	}

	avr = (ld)sum / (ld)nn;

	cout << avr << endl;

	return 0;
}
