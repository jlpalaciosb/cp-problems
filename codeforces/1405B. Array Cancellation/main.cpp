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
        int n; cin >> n;
        vi a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        ll c = 0;
        for (int i = n - 1; i >= 0; i--) {
            c -= a[i];
            c = max(c, 0LL);
        }
        cout << c << endl;
    }
    
    return 0;
}
