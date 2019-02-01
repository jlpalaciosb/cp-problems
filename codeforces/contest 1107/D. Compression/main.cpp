// TLE

#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

unordered_map<long long, bool> dp; int dpcount = 0;
bool matrix[5200][5200];

void readMatrix(int n);
void printMatrix(int n);
vector<int> getDivisors(int n);
short value(int i, int j, int k, int l);
long long id(int i, int j, int k, int l);

int main() {
	int n;
	scanf("%d\n", &n);

	readMatrix(n);
	
	vector<int> divs = getDivisors(n);
	int max = 1;
	for(int k = divs.size() - 1; k > 0; k--) {
		int div = divs[k];
		bool success = true;
		for(int i = 0; i < n / div; i++) {
			for(int j = 0; j < n / div; j++) {
				int a = i * div;
				int b = j * div;
				int c = a + div - 1;
				int d = b + div - 1;
				if(value(a, b, c, d) == -1) {
					success = false;
					break;
				}
			}
			if(!success) break;
		}
		if(success) {
			max = div;
			break;
		}
	}

	//cout << "dp size = " << dp.size() << endl;
	//cout << "dp count = " << dpcount << endl;
	cout << max << endl;

	return 0;
}

void readMatrix(int n) {
	static bool values[16][4] = {{0,0,0,0},{0,0,0,1},{0,0,1,0},{0,0,1,1},{0,1,0,0},{0,1,0,1},{0,1,1,0},{0,1,1,1},{1,0,0,0},{1,0,0,1},{1,0,1,0},{1,0,1,1},{1,1,0,0},{1,1,0,1},{1,1,1,0},{1,1,1,1}};
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n / 4; j++) {
			char c = getchar();
			if(isdigit(c)) {
				memcpy(matrix[i] + j * 4, values[c - '0'], 4);
			} else {
				memcpy(matrix[i] + j * 4, values[c - 'A' + 10], 4);
			}
		}
		getchar();
	}
}

void printMatrix(int n) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cout << matrix[i][j];
		}
		cout << endl;
	}
}

vector<int> getDivisors(int n) {
	vector<int> divs;
	int root = sqrt(n);
	for(int i = 1; i <= root; i++) {
		if(n % i == 0) divs.push_back(i);
	}
	int s = divs.size();
	for(int i = s - 1; i >= 0; i--) {
		if(divs[i] * divs[i] == n) continue;
		divs.push_back(n / divs[i]);
	}
	return divs;
}

short value(int i, int j, int k, int l) {
	int tl =  matrix[i][j]; // top-left
	if(i == k && j == l) return tl;

	long long regId = id(i, j, k, l);

	unordered_map<long long, bool>::iterator it = dp.find(regId);
	if(it != dp.end()){
		dpcount++;
		if(it->second) return tl;
		else return -1;
	}

	int width = l - j + 1;
	int height = k - i + 1;

	if(width == 1) {
		short v1, v2;

		v1 = value(i, j, i + height / 2 - 1, l);
		if(v1 == -1) {
			dp[regId] = false;
			return -1;
		}

		v2 = value(i + height / 2, j, k, l);
		if(v2 != v1) {
			dp[regId] = false;
			return -1;
		}

		dp[regId] = true;
		return tl;
	} else if(height == 1) {
		short v1, v2;

		v1 = value(i, j, k, j + width / 2 - 1);
		if(v1 == -1) {
			dp[regId] = false;
			return -1;
		}

		v2 = value(i, j + width / 2, k, l);
		if(v2 != v1) {
			dp[regId] = false;
			return -1;
		}

		dp[regId] = true;
		return tl;
	} else {
		short v1, v2, v3, v4;

		v1 = value(i, j, i + height / 2 - 1, j + width / 2 - 1);
		if(v1 == -1) {
			dp[regId] = false;
			return -1;
		}

		v2 = value(i, j + width / 2, i + height / 2 - 1, l);
		if(v2 != v1) {
			dp[regId] = false;
			return -1;
		}

		v3 = value(i + height / 2, j, k, j + width / 2 - 1);
		if(v3 != v2) {
			dp[regId] = false;
			return -1;
		}

		v4 = value(i + height / 2, j + width / 2, k, l);
		if(v4 != v3) {
			dp[regId] = false;
			return -1;
		}

		dp[regId] = true;
		return tl;
	}
}

long long id(int i, int j, int k, int l) {
	return (long long)i + 5200LL * (long long)j + 5200LL * 5200LL * (long long)k + 5200LL * 5200LL * 5200LL * (long long)l;
}
