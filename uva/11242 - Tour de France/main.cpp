#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	float fc[10], rc[10], dr[100];
	while(true) {
		int f, r;
		cin >> f; if(f == 0) break;
		cin >> r;

		for(int i = 0; i < f; i++)
			cin >> fc[i];
		for(int i = 0; i < r; i++)
			cin >> rc[i];

		int c = 0;
		for(int i = 0; i < f; i++)
			for(int j = 0; j < r; j++)
				dr[c++] = rc[j] / fc[i];

		sort(dr, dr + f * r);

		float max = 0.0;
		for(int i = 1; i < f * r; i++)
			if(dr[i] / dr[i - 1] > max)
				max = dr[i] / dr[i - 1];

		printf("%.2f\n", max);
	}
	return 0;
}
