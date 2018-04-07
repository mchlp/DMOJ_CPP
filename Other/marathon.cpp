#include<bits/stdc++.h>

using namespace std;

long hen[500001];

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    long r = 0;
    for (int i=0; i<n; i++) {
        int x;
        scanf("%d", &x);
        r += x;
        hen[i] = r;
    }
    while (q--) {
        int x, y;
        scanf("%d %d", &x, &y);
        x--;
        y--;
        int sum = 0;
        if (x != 0) {
            sum += hen[x-1];
        }
        if (y != n) {
            sum += hen[n-1]-hen[y];
        }
        printf("%d\n", sum);
    }
    return 0;
}