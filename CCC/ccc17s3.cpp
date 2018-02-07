#include <bits/stdc++.h>

using namespace std;

int boards[2001];
int fences[4001];

int main() {
    memset(boards, 0, sizeof(boards));
    int N;
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        int len;
        scanf("%d", &len);
        boards[len]++;
    }
    for (int i=1; i<=2000; i++) {
        for (int j=i; j<=2000; j++) {
            if (i == j) {
                fences[i+j] += boards[i]/2;
            } else {
                fences[i + j] += min(boards[i], boards[j]);
            }
        }
    }

    int max = 0;
    int count = 0;
    for (int i=0; i<4001; i++) {
        if (fences[i] > max) {
            max = fences[i];
            count = 1;
        } else if (fences[i] == max) {
            count++;
        }
    }
    printf("%d %d", max, count);
}