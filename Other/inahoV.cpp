#include<bits/stdc++.h>

using namespace std;

int main() {
    int num;
    cin >> num;
    unsigned long long s = 0;
    for (int i = 0; i < num; i++) {
        long long x;
        scanf("%lld", &x);
        s -= x;
    }
    if (s != 0) {
        printf("-");
    }
    cout << s << "\n";
    return 0;
}