#include<bits/stdc++.h>

using namespace std;

vector<int> arr;
unordered_map<int, long> checked;

int main() {

    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);

        pair<int, long> p1;
        p1.first = 0;
        p1.second = 1;
        checked.insert(p1);

        int count = 0;
        int s = 0;
        for (int i=0; i<N; i++) {
            int c;
            scanf("%d", &c);
            s += c;
            count += checked.count(s-47);
            pair<int, long> p;
            p.first = s;
            p.second = checked.count(c) + 1;
            checked.insert(p);
        }

        printf("%d\n", count);
    }

    return 0;
}