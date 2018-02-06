#include <bits/stdc++.h>

using namespace std;

int a, b;
bool grid[27][27];

bool checkPath() {
    deque<int> queue;
    bool vis[27];
    memset(vis, false, sizeof(vis));
    queue.push_front(0);

    while (!queue.empty()) {
        int cur = queue.back();
        queue.pop_back();
        if (grid[cur][1]) {
            return true;
        } else {
            for (int i = 0; i < 27; i++) {
                if (grid[cur][i]) {
                    if (!vis[i]) {
                        queue.push_front(i);
                        vis[i] = true;
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    int vis[27];
    vector<int> child[27];
    bool paths[27][27];
    memset(grid, false, sizeof(grid));
    memset(vis, -1, sizeof(vis));
    memset(paths, false, sizeof(paths));
    while (1) {
        char a, b;
        scanf("%c%c", &a, &b);
        if (a == '*') {
            break;
        }
        int x = (int) a - 65;
        int y = (int) b - 65;
        grid[x][y] = true;
        grid[y][x] = true;
        paths[x][y] = true;
        scanf("\n");
    }

    int count = 0;
    for (int i=0; i<27; i++) {
        for (int j = 0; j < 27; j++) {
            if (grid[i][j] && i>j) {
                a = i;
                b = j;
                grid[a][b] = false;
                grid[b][a] = false;
                if (!checkPath()) {
                    if (paths[a][b]) {
                        printf("%c%c\n", a + 65, b + 65);
                    } else if(paths[b][a]) {
                        printf("%c%c\n", b + 65, a + 65);
                    }
                    count++;
                }
                grid[a][b] = true;
                grid[b][a] = true;
            }
        }
    }

    printf("There are %d disconnecting roads.", count);
}