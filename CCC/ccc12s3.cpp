#include<bits/stdc++.h>

using namespace std;

int wood[2000001];
vector<int> wood2[2000001];

int main() {
    memset(wood, 0, 2000001);
    int n;
    scanf("%d", &n);

    for (int i=0; i<n; i++) {
        int k;
        scanf("%d", &k);
        wood[k]++;
    }

    for (int i=0; i<2000001; i++) {
        wood2[wood[i]].push_back(i);
    }

    int big = -1;
    int small = -1;
    for (int i=n; i>0; i--) {
        if (!wood2[i].empty()) {
            sort(wood2[i].begin(), wood2[i].end());
            if (big == -1) {
                big = wood2[i][wood2[i].size()-1];
                if (wood2[i][0] != big) {
                    small = wood2[i][0];
                    break;
                }
            } else {
                int maxS = 0;
                for (int k=0; k<wood2[i].size(); k++) {
                    if (abs(big - wood2[i][k]) > maxS) {
                        maxS = abs(big - wood2[i][k]);
                        small = wood2[i][k];
                    }
                }
                break;
            }
        }
    }
    printf("%d", abs(big-small));
}