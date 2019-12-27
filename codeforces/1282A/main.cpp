#include <iostream>
using namespace std;

int it(int a1, int b1, int a2, int b2) {
    int r = min(b1, b2) - max(a1, a2);
    if (r < 0) r = 0;
    return r;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int a, b, c, r; scanf("%d%d%d%d", &a, &b, &c, &r);
        if (b < a) { int aux = a; a = b; b = aux; }
        int dt = b - a;
        int it_ = it(a, b, c - r, c + r);
        dt -= it_;
        printf("%d\n", dt);
    }
    return 0;
}
