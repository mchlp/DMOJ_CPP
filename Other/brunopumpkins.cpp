#include<bits/stdc++.h>

using namespace std;

vector<int> farm;
int dp[1001][1001];
int N, T, z;

int dodp(int i, int p) {

    if (p == T) {
        return 0;
    }

    if (dp[i][p] == -1) {
        int left = INT_MAX;
        int right = INT_MAX;
        if (i > 0) {
            left = dodp(i-1, p+1) + abs(farm[i]-farm[i-1]);
        }
        else if (i < T-1) {
            right = dodp(i+1, p+1)  + abs(farm[i]-farm[i+1]);
        }
        dp[i][p] = min(left, right);
    }

    return dp[i][p];
}

int main() {
    cin >> N >> T;
    for(int i=0; i<N; i++) {
        int x;
        cin >> x;
        farm.push_back(x);
    }
    farm.push_back(0);
    sort(farm.begin(), farm.end());
    z = find(farm.begin(), farm.end(), 0)-farm.begin();
    remove(farm.begin(), farm.end(), 0);

    memset(dp, -1, sizeof dp);

    int m = min(dodp(z-1, 0), dodp(z, 0));

    cout << m << endl;
    return 0;
}