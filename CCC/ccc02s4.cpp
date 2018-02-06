#include <bits/stdc++.h>

using namespace std;

pair<int, int> dp[101];
bool init[101];
int times[101];
int lasts[101];
char names[50][101];
int grps[101];
int M = 0;
int Q = 0;

pair<int, int> doDp(int pos) {
    if (!init[pos]) {
        int minTime = INT_MAX;
        int nt;
        int time;
        for (int i=0; i<=min(pos, M-1); i++) {
            int t = 0;
            for (int j=0; j<=i; j++) {
                t = max(t, times[pos-j]);
                nt = t;
            }

            if (pos - i - 1 >= 0) {
                nt += doDp(pos - i - 1).first;
            }
            if (minTime > nt) {
                minTime = nt;
                time = t;
            }
        }

        dp[pos] = make_pair(minTime, time);
        init[pos] = true;
    }
    return dp[pos];
}

int main() {
    memset(init, false, sizeof(init));
    memset(times, 0, sizeof(times));
    memset(lasts, -1, sizeof(lasts));
    scanf("%d", &M);
    scanf("%d", &Q);


    for (int i=0; i<Q; i++) {
        scanf("%50s", names[i]);
        scanf("%d", &times[i]);
    }

    dp[0] = make_pair(times[0], 0);

    pair<int, int> res = doDp(Q-1);

    printf("Total Time: %d\n", res.first);

    bool div[Q];
    memset(div, false, sizeof(div));

    int nxt = res.first;
    for (int i=Q-1; i>=0; i--) {
        if (dp[i].first == nxt) {
            div[i] = true;
            nxt -= dp[i].second;
        }
    }

    for (int i=0; i<Q; i++) {
        printf("%s ",&names[i]);
        if (div[i]) {
            printf("\n");
        }
    }
}