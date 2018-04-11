#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

vector<pii> fires;
vector<pii> newfires;
int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

char graph[10][10];

int main() {

    int N = 2;
    while (N--) {

        fires.clear();
        newfires.clear();

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                scanf("%c", &graph[j][i]);
                if (graph[j][i] == 'F') {
                    pii f;
                    f.first = j;
                    f.second = i;
                    fires.push_back(f);
                }
            }
            scanf("\n");
        }
        if (N != 1) {
            scanf("----------\n");
        }

        int days = 0;

        bool treeleft = true;
        while (treeleft) {

            days++;

            treeleft = false;
            newfires.clear();

            for (int i = 0; i < fires.size(); i++) {
                pii cur = fires[i];
                for (int j = 0; j < 4; j++) {
                    pii n = cur;
                    n.first += dir[j][0];
                    n.second += dir[j][1];
                    if (graph[n.first][n.second] == 'T') {
                        graph[n.first][n.second] = 'F';
                        newfires.push_back(n);
                        treeleft = true;
                    }
                }
            }
            fires.clear();
            for (int i=0; i<newfires.size(); i++) {
                fires.push_back(newfires[i]);
            }
        }

        bool burnt = true;

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (graph[j][i] == 'T') {
                    burnt = false;
                    break;
                }
            }
            if (!burnt) {
                break;
            }
        }

        if (!burnt) {
            printf("-1\n");
        } else {
            printf("%d\n", days-1);
        }
    }

    return 0;
}