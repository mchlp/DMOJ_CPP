#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 0;
    scanf("%d", &n);
    int a[n];
    int b[n];
    memset(a, 0, n);
    memset(b, 0, n);
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i=0; i<n; i++) {
        scanf("%d", &b[i]);
    }
    int as = 0;
    int bs = 0;
    int l = 0;
    for (int i=0; i<n; i++) {
        as += a[i];
        bs += b[i];
        if (as == bs) {
            l = i+1;
        }
    }
    printf("%d", l);
}