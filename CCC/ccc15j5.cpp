#include<bits/stdc++.h>

using namespace std;

int pie, ppl;
int dp[251][251][251];

int rec(int npie, int nper, int prevmin) {
    if (dp[npie][nper][prevmin] == -1) {
        if (nper == ppl) {
            if (npie == pie) {
                dp[npie][nper][prevmin] = 1;
            } else {
                dp[npie][nper][prevmin] = 0;
            }
        } else if (npie >= pie) {
            dp[npie][nper][prevmin] = 0;
        } else {
            int sum = 0;
            for (int i = npie + prevmin; i <= pie; i++) {
                sum += rec(i, nper + 1, i - npie);
            }
            dp[npie][nper][prevmin] = sum;
        }
    }
    return dp[npie][nper][prevmin];
}

int main() {
    memset(dp, -1, sizeof dp);
    cin >> pie >> ppl;

    cout << rec(0, 0, 1) << endl;

    return 0;
}