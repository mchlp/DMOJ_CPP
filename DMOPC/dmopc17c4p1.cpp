#include <bits/stdc++.h>

using namespace std;

int wood[100001];

int main() {
    memset(wood, 0, sizeof(wood));
    int N, Q;
    scanf("%d %d", &N, &Q);

    while(Q--) {
        int start, end;
        scanf("%d %d", &start, &end);
        wood[start]++;
        wood[end]--;
    }

    int p = 0;
    int b = 0;
    int c = 0;
    for (int i=0; i<N; i++) {
        c += wood[i];
        if (c > 0) {
            b++;
        } else {
            p++;
        }

    }
    printf("%d %d", p, b);

}