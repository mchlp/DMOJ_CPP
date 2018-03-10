#include <bits/stdc++.h>

using namespace std;

char n[10000][20];
int v[10000];
vector<int> l;

int main() {
    int N;
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        int cv;
        string cn;
        scanf("%20s %d", n[i], &cv);
        v[i] = cv;
        l.push_back(cv);
    }
    sort(l.begin(), l.end());
    int m = l[l.size()/2];
    for (int i=0; i<N; i++) {
        if (v[i] > m) {
            printf("%s is cute! <3\n", &n[i]);
        } else {
            printf("%s is not cute. </3\n", &n[i]);
        }
    }
}