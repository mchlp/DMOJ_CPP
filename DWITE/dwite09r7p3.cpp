#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

char graph[10][10];
int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

int main() {

    pii start;

    int N = 2;
    while (N--) {

        queue<pii> q;

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                scanf("%c", &graph[j][i]);
                if (graph[j][i] == 'A') {
                    start.first = j;
                    start.second = i;
                    q.push(start);
                }
            }
            scanf("\n");
        }
        if (N != 1) {
            scanf("==========\n");
        }

        int area = q.size();

        while (!q.empty()) {
            pii cur = q.front();
            q.pop();

            for (int i=0; i<4; i++) {
                pii n = cur;
                n.first += dir[i][0];
                n.second += dir[i][1];

                if (graph[n.first][n.second] == '#') {
                    area++;
                    q.push(n);
                    graph[n.first][n.second] = '.';
                }
            }
        }

        printf("%d\n", area);
    }

    return 0;
}