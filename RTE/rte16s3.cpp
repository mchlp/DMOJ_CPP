#include<bits/stdc++.h>

using namespace std;

int graph[6001][6001];
int dis[6001][6001];
int N;

void flood() {
    memset(dis, INT_MAX, sizeof dis);
    dis[0][0] = 0;
    queue<int> q;
    q.push(0);
    int curDis = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i=0; i<N; i++) {
            if (dis[0][i] > curDis - dis[0][cur]) {
                dis[0][i] = curDis - dis[0][cur];
                dis[i][0] = curDis - dis[0][cur];
                q.push(i);
            }
        }
    }
}

int main() {

    cin >> N;

    for (int i=0; i<N-1; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a][b] = w;
        graph[w][a] = w;
    }

    flood();

    int Q;
    cin >> Q;
    while (Q--) {

    }

    return 0;
}