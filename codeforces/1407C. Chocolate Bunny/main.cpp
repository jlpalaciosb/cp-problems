#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main() {
    int n; scanf("%d", &n);
    vi v(n + 1);

    int j = 1;
    for (int i = 2; i <= n; i++) {
        printf("? %d %d\n", j, i); fflush(stdout);
        int a; scanf("%d", &a);
        printf("? %d %d\n", i, j); fflush(stdout);
        int b; scanf("%d", &b);

        if (a > b) {
            v[j] = a;
            j = i;
        } else {
            v[i] = b;
        }
    }
    v[j] = n;

    printf("!");
    for (int i = 1; i <= n; i++) {
        printf(" %d", v[i]);
    }
    printf("\n"); fflush(stdout);

    return 0;
}
