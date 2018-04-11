#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

map<string, int> legend;
int dis[21];

int graph[21][21];
int YYZ, SEA;

int main() {

    int N = 2;
    while (N--) {

        legend.clear();
        memset(graph, -1, sizeof graph);
        for (int i=0; i<21; i++) {
            dis[i] = INT_MAX;
        }

        int num;
        scanf("%d\n", &num);

        int air = 0;

        for (int i=0; i<num; i++) {
            string s;
            getline(cin, s);
            stringstream ss(s);

            string a;
            int start;
            ss >> a;
            if (legend.find(a) == legend.end()) {
                legend.insert(pair<string, int>(a, air));
                if (a == "YYZ") {
                    YYZ = air;
                }
                start = air;
                air++;
            } else {
                start = legend.find(a)->second;
            }

            string b;
            int end;
            ss >> b;
            if (legend.find(b) == legend.end()) {
                legend.insert(pair<string, int>(b, air));
                if (b == "SEA") {
                    SEA = air;
                }
                end = air;
                air++;
            } else {
                end = legend.find(b)->second;
            }

            string c;
            ss >> c;
            int w = atoi(c.c_str());

            graph[start][end] = w;
        }

        queue<int> q;
        q.push(YYZ);
        dis[YYZ] = 0;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (int i=0; i<21; i++) {
                if (graph[cur][i] != -1) {
                    if (dis[cur] + graph[cur][i] < dis[i]) {
                        dis[i] = dis[cur] + graph[cur][i];
                        q.push(i);
                    }
                }
            }
        }

        printf("%d\n", dis[SEA]);
    }

    return 0;
}