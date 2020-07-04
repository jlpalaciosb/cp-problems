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
        ll a, b, n, m; cin >> a >> b >> n >> m;
        if (a + b < n + m || min(a, b) < m) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
    
    return 0;
}
