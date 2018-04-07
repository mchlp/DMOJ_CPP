#include<bits/stdc++.h>

using namespace std;

set<string> words;
int dp[2001];
string word;

int dodp(int in) {
    if (in == word.length()) {
        return 0;
    }
    if (dp[in] == -1) {
        int m = INT_MAX-1;
        string check = "";
        for (int i=in; i<word.length(); i++) {
            check += word[i];
            if (words.count(check)) {
                m = min(m, 1+dodp(i+1));
            }
        }
        dp[in] = m;
    }
    return dp[in];
}


int main() {

    int nw;
    scanf("%d", &nw);

    for (int i = 0; i < nw; i++) {
        char w[2001];
        scanf("%2000s", &w[0]);
        words.insert(w);
    }

    int N = 10;
    while (N--) {
        memset(dp, -1, sizeof dp);
        char cw[2001];
        scanf("%2000s", &cw[0]);
        word = cw;
        printf("%d\n", dodp(0)-1);
    }
    return 0;
}