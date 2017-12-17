#include <bits/stdc++.h>

using namespace std;

int main() {
    int s, e;
    int a = 0;
    scanf("%d\n%d", &s, &e);
    for (int i=s; i<=e; i++) {
        int count = 2;
        for (int j=2; j<i; j++) {
            if (i%j == 0) {
                count--;
            }
        }
        if (count == 0) {
            a++;
        }
    }
    printf("The number of RSA numbers between %d and %d is %d", s, e, a);
    return 0;
}