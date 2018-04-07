#include <bits/stdc++.h>

using namespace std;

vector<int> motels = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};
int ways[50];

int main() {
    memset(ways, 0, sizeof ways);
    int low, high, a;
    scanf("%d", &low);
    scanf("%d", &high);
    scanf("%d", &a);
    while (a--) {
        int r;
        scanf("%d", &r);
        motels.push_back(r);
    }
    int maxH = 14+a;
    sort(motels.begin(), motels.end());

    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int c = q.front();
        q.pop();
        ways[c]++;
        for (int i=c+1; motels[i]-motels[c] <= high; i++) {
            if (motels[i]-motels[c] >= low) {
                q.push(i);
            }
        }
    }

    printf("%d\n", ways[maxH]);

    return 0;
}