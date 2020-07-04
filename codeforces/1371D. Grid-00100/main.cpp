#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t; cin >> t;
    while (t--) {
        int n, k, mat[300][300];
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] = 0;
            }
        }

        cout << (k % n == 0 ? 0 : 2) << endl;

        for (int i = 0; i < n && k > 0; i++) {
            mat[i][i] = 1;
            k--;
        }

        for (int c = 1; c <= n / 2 && k > 0; c++) {
            for (int d = 0; d < 4 && k > 0; d++) {
                int i, j;
                if (d == 0) {
                    i = c;
                    j = 0;
                } else if (d == 1) {
                    i = 0;
                    j = n - c;
                } else if (d == 2) {
                    i = 0;
                    j = c;
                } else {
                    i = n - c;
                    j = 0;
                }
                while (i < n && j < n && k > 0) {
                    mat[i++][j++] = 1;
                    k--;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << mat[i][j];
            }
            cout << endl;
        }
    }
    
    return 0;
}
