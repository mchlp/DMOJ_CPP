#include<bits/stdc++.h>

using namespace std;

int dp[1002][1002];

vector<int> seq1;
vector<int> seq2;

int main() {
    int l1, l2;
    cin >> l1 >> l2;

    for (int i=0; i<l1; i++) {
        int a;
        cin >> a;
        seq1.push_back(a);
    }

    for (int i=0; i<l2; i++) {
        int a;
        cin >> a;
        seq2.push_back(a);
    }

    for (int i=0; i<=l1; i++) {
        dp[i][0] = 0;
    }

    for (int i=0; i<=l2; i++) {
        dp[0][i] = 0;
    }

    for (int i=0; i<l1; i++) {
        for (int j=0; j<l2; j++) {
            int cur = max(dp[i][j+1], dp[i+1][j]);
            if (seq1[i] == seq2[j]) {
                cur = max(dp[i][j+1]+1;
            }
            dp[i+1][j+1] = cur;
        }
    }

    cout << dp[l1][l2];

    return 0;
}