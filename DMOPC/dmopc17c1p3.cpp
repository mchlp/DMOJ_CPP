#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

vector<pii> graph[100001];
long long dis[100001];

int main() {

    for (int i=0; i<100001; i++) {
        dis[i] = LONG_LONG_MAX;
    }

    int N, M;
    scanf("%d%d", &N, &M);

    for (int i=0; i<M; i++) {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        pii ap, bp;
        ap.first = a;
        bp.first = b;
        w = w == 0 ? 1 : 1000000;
        ap.second = w;
        bp.second = w;
        graph[a].push_back(bp);
        graph[b].push_back(ap);
    }

    queue<int> q;
    q.push(1);
    dis[1] = 0;
    while (!q.empty()) {
        int cur = q.front();
        long curDis = dis[cur];
        q.pop();

        for (int i=0; i<graph[cur].size(); i++) {
            if (graph[cur][i].second + curDis < dis[graph[cur][i].first]) {
                dis[graph[cur][i].first] = graph[cur][i].second + curDis;
                q.push(graph[cur][i].first);
            }
        }
    }

    if (dis[N] == LONG_LONG_MAX) {
        printf("-1");
    } else {
        printf("%lld %lld", dis[N] / 1000000, dis[N] % 1000000 + dis[N] / 1000000);
    }

    return 0;
}