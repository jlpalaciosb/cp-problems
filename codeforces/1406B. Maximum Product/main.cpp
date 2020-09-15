#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vi a; a.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());

        ll ans = 1;
        if (a[n - 1] < 0) {
            for (int i = n - 1; i >= n - 5; i--) {
                ans *= a[i];
            }
        } else {
            ans *= a[n - 1];
            int i = 0, j = n - 2;
            for (int c = 0; c < 2; c++) {
                if (a[i] * a[i + 1] > a[j] * a[j - 1]) {
                    ans *= a[i] * a[i + 1];
                    i = i + 2;
                } else {
                    ans *= a[j] * a[j - 1];
                    j = j - 2;
                }
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}
