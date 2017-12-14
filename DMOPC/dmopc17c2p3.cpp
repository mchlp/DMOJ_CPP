#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, r;
    scanf("%d %d", &n, &r);
    vector<int> graph[n + 1];
    bool rabbit[n + 1];
    int visited[n + 1];
    int dis[n + 1];

    for (int i = 0; i < n + 1; i++) {
        rabbit[i] = false;
        visited[i] = -1;
        dis[i] = INT_MAX - 1;
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 0; i < r; i++) {
        int x;
        scanf("%d", &x);
        rabbit[x] = true;
    }

    int s, e;
    scanf("%d %d", &s, &e);

    bool done = false;
    while (!done) {

        done = true;

        for (int i = 1; i < n + 1; i++) {

            if (rabbit[i]) {
                dis[i] = 0;
                continue;
            }

            if (graph[i].size() > 0) {
                for (int j : graph[i]) {
                    dis[i] = dis[i] < dis[j] + 1 ? dis[i] : dis[j] + 1;
                }
            }

            if (dis[i] == INT_MAX - 1) {
                done = false;
            }
        }

    }

    queue<int> q;
    q.push(s);
    visited[s] = -2;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        if (v == e) {
            break;
        }

        if (graph[v].size() > 0) {
            for (int i : graph[v]) {
                if (visited[i] == -1) {
                    visited[i] = v;
                    q.push(i);
                }
            }
        }
    }

    int min = INT_MAX;

    int cur = e;

    do {
        min = dis[cur] > min ? min : dis[cur];
        cur = visited[cur];
    } while (cur != -2);

    printf("%d ", min);

    return 0;
}