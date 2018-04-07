
#include<bits/stdc++.h>

using namespace std;

bool dog[2001][2001];
bool vis[2001];

int main() {

    memset(vis, false, sizeof vis);
    int N, M, A, B;
    scanf("%d%d%d%d", &N, &M, &A, &B);

    for (int i=0; i<M; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        dog[x][y] = true;
        dog[y][x] = true;
    }

    queue<int> q;
    q.push(A);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur == B) {
            printf("GO SHAHIR!");
            return 0;
        } else {
            for (int i=1; i<=N; i++) {
                if (dog[cur][i]) {
                    if (!vis[i]) {
                        vis[i] = true;
                        q.push(i);
                    }
                }
            }
        }
    }

    printf("NO SHAHIR!");

    return 0;
}