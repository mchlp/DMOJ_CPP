#include<bits/stdc++.h>

using namespace std;

int main() {
    long long r, g;
    scanf("%lld\n%lld", &r, &g);
    if (r < g) {
        cout << g-r;
    } else {
        cout << min(r - ((r / g) * g), (((r / g) + 1) * g) - r);
    }

    return 0;
}