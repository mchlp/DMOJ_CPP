
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    long c = 0;
    int cc, v;
    scanf("%d", &n);
    for (int i=0; i<n; ++i) {
        scanf("%d %d", &cc, &v);
        if (v > 0) {
            c+=cc;
        }
    }
    printf("%ld", c);
    return 0;
}