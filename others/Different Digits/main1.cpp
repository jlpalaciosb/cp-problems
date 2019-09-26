#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

bool hasRepeated(const string &str);

int main() {
	int n, m;

	while(scanf("%d%d", &n, &m) != EOF) {
		int count = 0;
		for(int i = n; i <= m; ++i) {
			string number = to_string(i);
			if(!hasRepeated(number)) {
				++count;
			}
		}
		cout << count << endl;
	}

	return 0;
}

bool hasRepeated(const string &str) {
	static vector<int> freq(10);
	freq.assign(10, 0);
	int l = str.length();
	for(int i = 0; i < l; ++i) {
		int index = str[i] - '0';
		freq[index]++;
		if(freq[index] > 1) {
			return true;
		}
	}
	return false;
}
