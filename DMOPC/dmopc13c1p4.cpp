#include<bits/stdc++.h>

using namespace std;

char graph[51][51];
int vis[51][51];
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        memset(vis, -1, sizeof vis);
        int w, h;
        scanf("%d %d\n", &w, &h);
        pair<int, int> start;
        pair<int, int> end;
        for (int i=0; i<h; i++) {
            for (int j=0; j<w; j++) {
                do {
                    scanf("%c", &graph[j][i]);
                    if (graph[j][i] == 'C') {
                        start.first = j;
                        start.second = i;
                    } else if (graph[j][i] == 'W') {
                        end.first = j;
                        end.second = i;
                    }
                } while (graph[j][i] == '\n');
            }
        }
        vis[start.first][start.second] = 0;
        queue<pair<int, int>> q;
        q.push(start);
        bool found = false;
        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();
            if (vis[cur.first][cur.second] >= 60) {
                break;
            }
            if (cur.first == end.first && cur.second == end.second) {
                if (vis[cur.first][cur.second] < 60) {
                    found = true;
                    printf("%d\n", vis[cur.first][cur.second]);
                }
                break;
            } else {
                for(int i=0; i<4; i++) {
                    pair<int, int> n;
                    n.first = cur.first + dir[i][0];
                    n.second = cur.second + dir[i][1];
                    if (n.first >= 0 && n.first < w && n.second >= 0 && n.second < h && vis[n.first][n.second] == -1 && graph[n.first][n.second] != 'X') {
                        q.push(n);
                        vis[n.first][n.second] = vis[cur.first][cur.second] + 1;
                    }
                }
            }
        }
        if (!found) {
            printf("#notworth\n");
        }
    }
    return 0;
}