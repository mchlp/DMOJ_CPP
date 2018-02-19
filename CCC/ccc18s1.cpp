#include <bits/stdc++.h>

using namespace std;

vector<int> wood;

int main() {
    int N;
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        int x;
        scanf("%d", &x);
        wood.push_back(x);
    }
    sort(wood.begin(), wood.end());
    double small = 1000000000000.0;
    for (int i=1; i<N-1; i++) {
        int last = wood[i-1];
        int next = wood[i+1];
        double t = (wood[i]-last)/2.0 + (next-wood[i])/2.0;
        if (t < small) {
            small = t;
        }
    }
    printf("%.1f", small);
}