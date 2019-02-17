#include <iostream>
#include <algorithm>
#define MAX_PASS 8000 // realmente es 7776

using namespace std;

char g1[5][6], g2[5][6];

string p1[MAX_PASS], p2[MAX_PASS];
int p1t, p2t;

char tmp[10];

void backtrack1(int level) {
	if(level == 5) {
		p1[p1t++] = string(tmp, 5);
	} else {
		for(int i = 0; i < 6; i++) {
			if(i > 0 && g1[level][i] == g1[level][i - 1]) continue;

			tmp[level] = g1[level][i];
			backtrack1(level + 1);
		}
	}
}

void backtrack2(int level) {
	if(level == 5) {
		p2[p2t++] = string(tmp, 5);
	} else {
		for(int i = 0; i < 6; i++) {
			if(i > 0 && g2[level][i] == g2[level][i - 1]) continue;

			tmp[level] = g2[level][i];
			backtrack2(level + 1);
		}
	}
}

int main() {
	int T; scanf("%d\n", &T);
	while(T--) {
		int k; scanf("%d\n", &k);
		
		for(int i = 0; i < 6; i++) {
			for(int j = 0; j < 5; j++) g1[j][i] = getchar();
			getchar();
		}
		for(int i = 0; i < 6; i++) {
			for(int j = 0; j < 5; j++) g2[j][i] = getchar();
			getchar();
		}

		for(int i = 0; i < 5; i++) {
			sort(g1[i], g1[i] + 6);
			sort(g2[i], g2[i] + 6);
		}

		p1t = 0; backtrack1(0);
		p2t = 0; backtrack2(0);

		int c = 0; bool success = false;
		int j = 0;
		for(int i = 0; i < p1t; i++) {
			while(j < p2t && p1[i] > p2[j]) j++;
			if(j == p2t) break;

			if(p1[i] == p2[j]) {
				j++; c++;
				if(c == k) {
					cout << p1[i] << endl;
					success = true;
					break;
				}
			}
		}
		if(!success) cout << "NO" << endl;
	}
	return 0;
}
