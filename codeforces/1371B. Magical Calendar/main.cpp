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
        ll n, r; cin >> n >> r;
        if (r < n) {
            cout << (r + 1) * r / 2 << endl;
        } else {
            cout << n * (n - 1) / 2 + 1 << endl;
        }
    }
    
    return 0;
}
