#include <bits/stdc++.h>

using namespace std;

int main() {

    freopen("DATA21.txt", "r", stdin);

    int dirs[4][2]{{1,  0},
                   {0,  1},
                   {-1, 0},
                   {0,  -1}};
    int keys[1000][1000];
    char map[1000][1000];
    pair<pair<int, int>, int> start;
    deque<pair<pair<int, int>, int> > queue;

    int N = 10;
    while (N--) {
        queue.clear();
        for (int i=0; i<1000; i++) {
            for (int j=0; j<1000; j++) {
                keys[i][j] = -1;
            }
        }
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> map[j][i];
                if (map[j][i] == 'S') {
                    start.first.first = j;
                    start.first.second = i;
                    start.second = 0;
                    keys[j][i] = -2;
                }
            }
        }

        queue.push_back(start);
        while (!queue.empty()) {
            pair<pair<int, int>, int> cur = queue.front();
            queue.pop_front();
            int keysNeeded = cur.second;
            if (map[cur.first.first][cur.first.second] >= '1' && map[cur.first.first][cur.first.second] <= '9') {
                keysNeeded = max(map[cur.first.first][cur.first.second] - '0', keys[cur.first.first][cur.first.second]);
            }
            for (int i = 0; i < 4; i++) {
                pair<int, int> newCord = cur.first;
                newCord.first += dirs[i][0];
                newCord.second += dirs[i][1];
                if (newCord.first >= 0 && newCord.second >= 0 && newCord.first < n && newCord.second < n) {
                    if (keys[newCord.first][newCord.second] > keysNeeded || keys[newCord.first][newCord.second] == -1) {
                        if (map[newCord.first][newCord.second] != '#') {
                            pair<pair<int, int>, int> p;
                            p.first = newCord;
                            p.second = keysNeeded;
                            keys[newCord.first][newCord.second] = keysNeeded;
                            queue.push_back(p);
                        }
                    }
                }
            }
        }

        int kc = 0;
        bool change = true;
        while (change) {
            change = false;
            for (int i=0; i<n; i++) {
                for (int j=0; j<n; j++) {
                    if (map[j][i] == 'K') {
                        if (keys[j][i] <= kc && keys[j][i] != -1) {
                            map[j][i] = 'X';
                            change = true;
                            kc++;
                        }
                    }
                }
            }
        }
        int tc = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (map[j][i] == 'T') {
                    if (keys[j][i] <= kc && keys[j][i] != -1) {
                        tc++;
                    }
                }
            }
        }
        cout << tc << "\n";
    }
    return 0;
}
