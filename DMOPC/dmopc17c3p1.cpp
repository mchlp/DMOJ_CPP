#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int min = 1000000000;
    scanf("%d", &n);
    while (n--) {
        int c;
        scanf("%d", &c);
        min = min < c ? min : c;
    }
    printf("%d", min);
}