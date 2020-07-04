#include <iostream>
#include <vector>
#define INF 1000000000
using namespace std;
typedef long long ll;
typedef vector<int> vi;

void init(vector<vi> &a, vi &r, vi &c, int n) {
    a.resize(n);
    for (int i = 0; i < n; i++) {
        a[i].assign(n, 0);
    }
    r.assign(n, 0);
    c.assign(n, 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<vi> a; vi r, c;
        init(a, r, c, n);

        // WA
        int i0 = 0, j0 = 0, i = 0, j = 0;
        while (k > 0) {
            k--;
            a[i][j] = 1;
            r[i]++;
            c[j]++;
            i++;
            j++;
            if (i == n || j == n) {
                if (j0 == 0) {
                    j0 = i0 + 1;
                    i0 = 0;
                } else {
                    i0 = j0;
                    j0 = 0;
                }
                i = i0;
                j = j0;
            }
        }

        int minr = INF, maxr = 0, minc = INF, maxc = 0;
        for (int i = 0; i < n; i++) {
            minr = min(minr, r[i]);
            maxr = max(maxr, r[i]);
            minc = min(minc, c[i]);
            maxc = max(maxc, c[i]);
        }

        // WA
        cout << (maxr - minr) * (maxr - minr) + (maxc - minc) * (maxc - minc) << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << a[i][j];
            }
            cout << endl;
        }
    }
    
    return 0;
}
