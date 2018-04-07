
#include<bits/stdc++.h>

using namespace std;

vector<pair<int, int>> items;
int dp[1001][1001];

int main() {

    pair<int, int> z;
    z.first = 0;
    z.second = 0;
    items.push_back(z);

    int numItems, cap;
    scanf("%d %d", &numItems, &cap);
    for (int i=0; i<numItems; i++) {
        pair<int, int> it;
        scanf("%d %d", &it.second, &it.first);
        items.push_back(it);
    }

    sort(items.begin(), items.end());

    for (int i=0; i<= cap; i++) {
        dp[0][i] = 0;
    }

    for (int i=1; i<=numItems; i++) {
        for (int j=0; j<=cap; j++) {
            if (j >= items[i].first) {
                dp[i][j] = max(dp[i - 1][j], items[i].second + dp[i - 1][j - items[i].first]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    printf("%d\n", dp[numItems][cap]);

    return 0;
}