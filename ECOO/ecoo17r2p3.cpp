#include <bits/stdc++.h>

using namespace std;

vector<pair<int, long long>> res;

int main() {

    int N = 10;
    while (N--) {
        res.clear();
        int drop;
        long long n, days;
        int m = INT_MAX;
        scanf("%lld %d %lld", &n, &drop, &days);
        for (long i=0; i<n; i++) {
            pair<int, long long> c;
            scanf("%d", &c.first);
            c.second = i+1;
            res.push_back(c);
            if (c.first < m) {
                m = c.first;
            }
        }
        for (long i=0; i<n; i++) {
            res[i].first -= m;
        }
        for (int i=0; i<n; i++) {
            printf("%d ", res[i].first);
        }
        printf("\n");
        //days--;
        //days %= n;
        //for (long i=0; i<days; i++) {
        //    (*max_element(res.begin(), res.end())).first -= drop;
        //}
        for (int i=0; i<n; i++) {
            while (res[i].first > 0) {
                res[i].first -= drop;
            }
        }
        for (int i=0; i<n; i++) {
            printf("%d ", res[i].first);
        }
        printf("\n");
        printf("\n");
        sort(res.begin(), res.end());
        //reverse(res.begin(), res.end());
        int i = 0;
        long long l = res[0].second;
        m = res[0].first;
        while (m == res[i].first) {
            if (res[i].second < l) {
                l = res[i].second;
            }
            i++;
        }
        printf("%lld\n", l);
    }

    return 0;
}