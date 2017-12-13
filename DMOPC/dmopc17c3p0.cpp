#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    printf("$%d.%s ", n/2, n%2 != 0? "50" : "00");
    printf("$%d.%s\n", n/2, n%2 != 0? "50" : "00");
}