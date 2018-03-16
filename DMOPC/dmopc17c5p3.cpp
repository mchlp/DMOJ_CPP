#include<bits/stdc++.h>

using namespace std;

long long maxPrime = -1;

long long gcf(long long x, long long y) {
    long long b = max(x, y);
    long long s = min(x, y);
    while (s != 0) {
        long long ns = b % s;
        b = s;
        s = ns;
    }
    return b;
}

int main() {

    long long n;
    scanf("%lld", &n);

    long long m = 0;

    for (long long i = 0; i < n; i++) {
        long long x;
        scanf("%lld", &x);
        if (i == 0) {
            m = x;
        } else {
            m = gcf(m, x);
        }
        if (m == 1) {
            printf("DNE");
            return 0;
        }
    }

    long long p = 2;
    while (p * p <= m) {
        while (m % p == 0) {
            m /= p;
            maxPrime = p;
        }
        p++;
    }

    m = max(maxPrime, m);

    if (m == -1 || m == 1) {
        printf("DNE");
    } else {
        printf("%lld", m);
    }

    return 0;
}