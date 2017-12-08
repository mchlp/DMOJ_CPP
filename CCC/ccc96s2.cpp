#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; ++i) {
        unsigned long int num;
        unsigned long int oNum;
        scanf("%ld", &num);
        oNum = num;
        while (num >= 11) {
            printf("%ld\n", num);
            num = num/10 - num%10;
        }
        if (num == 11) {
            printf("The number %ld is divisible by 11.\n", oNum);
        } else {
            printf("The number %ld is not divisible by 11.\n", oNum);
        }
    }
    return 0;
}