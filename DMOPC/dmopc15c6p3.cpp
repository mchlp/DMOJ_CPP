#include<bits/stdc++.h>

using namespace std;

long field[200001];

int main() {
    long w, h, k;
    cin >> h >> w >> k;
    for (long i=0; i<h; i++) {
        field[i] = 0;
    }
    field[0] = w;
    for (long i=0; i<w; i++) {
        long s, e;
        cin >> s >> e;
        field[s-1]--;
        field[e]++;
    }
    for (long i=1; i<h; i++) {
        field[i]+=field[i-1];
    }

    long start = 0;
    long end = -1;
    long curSum = 0;
    long m = -1;

    while (end < h-1) {
        end++;
        curSum += field[end];
        if (curSum < k) {
            continue;
        } else {
            while (curSum - field[start] >= k) {
                curSum -= field[start];
                start++;
            }
            if (m == -1) {
                m = (end-start)+1;
            } else {
                m = min(m, (end-start)+1);
            }
        }
    }

    cout << m << endl;

    return 0;
}