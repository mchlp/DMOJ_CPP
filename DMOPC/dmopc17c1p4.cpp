#include<bits/stdc++.h>

using namespace std;

int g[5000];
int h[5000];
int q[5000];
int t[5000];

int dp[5000];

int main() {

    int N, H;
    scanf("%d %d", &N, &H);

    for (int i=0; i<N; i++) {
        int cg, ch, cq, ct;
        scanf("%d %d %d %d", &cg, &ch, &cq, &ct);
        g[i] = cg;
        h[i] = ch;
        q[i] = cq;
        t[i] = ct;
    }

    for (int i=0; i<N; i++) {
        dp[i] = 0;
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<=H; j++) {
            for (int k=1; h[i]+(k*t[i])<=j; k++) {
                if (k > 0 || j == h[i]) {
                    int prev = dp[j - h[i] - (k * t[i])] + g[i];
                    dp[j] = max(dp[j], prev + (k * q[i]));
                }
            }
        }
    }

    printf("%d", dp[H]);

    return 0;
}