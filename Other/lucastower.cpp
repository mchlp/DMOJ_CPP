#include<bits/stdc++.h>

using namespace std;


int main() {
    int N = 10;
    while (N--) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", (int) pow((a-1),2)-(a-1)+1);
    }
    return 0;
}