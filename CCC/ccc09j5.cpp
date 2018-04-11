#include<bits/stdc++.h>

using namespace std;

bool graph[51][51];
int existing[23][2] = {{2,  6},
                       {1,  6},
                       {3,  6},
                       {7,  6},
                       {4,  6},
                       {5,  6},
                       {3,  4},
                       {4,  5},
                       {3,  5},
                       {3,  15},
                       {7,  8},
                       {8,  9},
                       {10, 9},
                       {12, 9},
                       {11, 10},
                       {12, 11},
                       {13, 15},
                       {12, 13},
                       {9,  12},
                       {13, 14},
                       {16, 18},
                       {16, 17},
                       {17, 18}};

int main() {
    memset(graph, false, sizeof graph);

    for (int i=0; i<23; i++) {
        graph[existing[i][0]][existing[i][1]] = true;
        graph[existing[i][1]][existing[i][0]] = true;
    }

    while (1) {
        char c;
        scanf("%c\n", &c);
        if (c == 'q') {
            return 0;
        } else if (c == 'i') {
            int x, y;
            scanf("%d\n", &x);
            scanf("%d\n", &y);
            graph[x][y] = true;
            graph[y][x] = true;
        } else if (c == 'd') {
            int x, y;
            scanf("%d\n", &x);
            scanf("%d\n", &y);
            graph[x][y] = false;
            graph[y][x] = false;
        } else if (c == 'n') {
            int x;
            scanf("%d\n", &x);
            int f = 0;
            for (int i = 0; i < 51; i++) {
                if (graph[x][i]) {
                    f++;
                }
            }
            printf("%d\n", f);
        } else if (c == 'f') {
            int x;
            scanf("%d\n", &x);
            vector<int> friends;
            for (int i = 0; i < 51; i++) {
                if (graph[x][i]) {
                    friends.push_back(i);
                }
            }
            unordered_set<int> fof;
            for (int i = 0; i < friends.size(); i++) {
                for (int j = 0; j < 51; j++) {
                    if (graph[friends[i]][j] && j != x && fof.find(j) == fof.end() && !graph[x][j]) {
                        fof.insert(j);
                    }
                }
            }
            printf("%d\n", fof.size());
        } else if (c == 's') {
            int x, y;
            scanf("%d\n", &x);
            scanf("%d\n", &y);
            queue<pair<int, int>> q;
            pair<int, int> f;
            f.first = x;
            f.second = 0;
            q.push(f);
            bool vis[51];
            memset(vis, false, sizeof vis);
            vis[x] = true;

            while (!q.empty()) {
                pair<int, int> cur = q.front();
                q.pop();

                if (cur.first == y) {
                    printf("%d\n", cur.second);
                    break;
                }

                for (int i = 0; i < 51; i++) {

                    if (graph[cur.first][i] && !vis[i]) {
                        pair<int, int> s;
                        s.first = i;
                        s.second = cur.second + 1;
                        q.push(s);
                        vis[i] = true;
                    }

                }
            }

            if (!vis[y]) {
                printf("Not connected\n");
            }
        }

    }
}