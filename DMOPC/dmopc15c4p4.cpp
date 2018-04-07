#include<bits/stdc++.h>

using namespace std;

vector<pair<int,int>> wood;
long woodsum[100001];
int N, K, Q;

bool find(int num, int a, int b) {
    int start = 0;
    int end = N;
    int mid = (start+end)/2;

    int lastmid = -1;
    while (lastmid != mid) {
        if (wood[mid].first == num && wood[mid].second >= a && wood[mid].second <= b) {
            return true;
        } else if (wood[mid].first > num) {
            end = mid;
        } else if (wood[mid].first < num) {
            start = mid;
        } else {
            if (wood[mid].second < a) {
                start = mid;
            } else {
                end = mid;
            }
        }
        lastmid = mid;
        mid = (start+end)/2;
    }
    return false;
}

int main() {

    scanf("%d%d%d", &N, &K, &Q);
    woodsum[0] = 0;
    for (int i=1; i<=N; i++) {
        int x;
        scanf("%d", &x);
        pair<int, int> p;
        p.first = x;
        p.second = i;
        wood.push_back(p);
        woodsum[i] = woodsum[i-1]+x;
    }

    sort(wood.begin(), wood.end());

    for (int i=0; i<Q; i++) {
        int a,b,x,y;
        bool found = false;
        scanf("%d%d%d%d", &a, &b, &x, &y);
        if (woodsum[y]-woodsum[x-1] > K) {
            if (find(a, x, y)) {
                if (find(b, x, y)) {
                    found = true;
                }
            }
        }
        if (!found) {
            printf("No\n");
        } else {
            printf("Yes\n");
        }
    }


    return 0;
}