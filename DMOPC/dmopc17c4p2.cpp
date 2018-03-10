#include <bits/stdc++.h>

using namespace std;

int wood[1001];
bool path[1001][1001];

int main() {
    memset(path, false, sizeof(path));
    int N, Q;
    scanf("%d %d", &N, &Q);
    for (int i=0; i<N; i++) {
        int x;
        scanf("%d", &x);
        wood[i] = x;
    }
    for (int i=0; i<N-1; i++) {
        int s, e;
        scanf("%d %d", &s, &e);
        path[s][e] = true;
        path[e][s] = true;
    }
    for (int i=0; i<Q; i++) {
        int q, s, e;
        scanf("%d %d", &q, &s, &e);
        deque<int> queue;
        queue.push_front(s);
        while (!queue.empty()) {
            int cur = queue.front();
            if (cur != e) {
                if (find(queue.begin(), queue.end()))
            } else {
                if (q == 1) {
                    int sum;
                    int size = queue.size();
                    while (!queue.empty()) {
                        sum += queue.front();
                        queue.pop_front();
                    }
                    sum /= size;
                    printf("%d", sum);
                } else if (q == 2) {
                    sort(queue.begin(), queue.end());
                    printf("%d", queue[queue.size()/2]);
                } else {
                    int freq[100001];
                    memset(freq, 0, sizeof(freq));
                    while (!queue.empty()) {
                        freq[queue.front()]++;
                        queue.pop_front();
                    }
                    int mode = 0;
                    int mfreq = 0;
                    for (int j=0; i<100001; i++) {
                        if (freq[j] > mfreq) {
                            mode = j;
                            mfreq = freq[j];
                        }
                    }
                }
            }
        }
    }
}