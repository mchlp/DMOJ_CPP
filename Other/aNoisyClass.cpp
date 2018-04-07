#include<bits/stdc++.h>

using namespace std;

int graph[10001][3];
unordered_set<int> rightside;

int main() {

    int N, M;
    scanf("%d%d", &N, &M);

    for (int i=0; i<M; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        graph[i][0] = a;
        graph[i][1] = b;
        graph[i][2] = 0;
    }

    bool rm = true;
    while (rm) {
        rightside.clear();
        rm = false;
        for (int i=0; i<M; i++) {
            if (graph[i][2] == 0) {
                rightside.insert(graph[i][1]);
            }
        }
        for (int i=0; i<M; i++) {
            if (graph[i][2] == 0) {
                if (rightside.count(graph[i][0]) == 0) {
                    rm = true;
                    graph[i][2] = 1;
                }
            }
        }
    }

    if (rightside.empty()) {
        printf("Y");
    } else {
        printf("N");
    }

    return 0;
}