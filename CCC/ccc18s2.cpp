#include <bits/stdc++.h>

using namespace std;

int grid[101][101];
int oldGrid[101][101];

int main() {
    int N;
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            int x;
            scanf("%d", &x);
            grid[j][i] = x;
        }
    }

    for (int i=0; i<4; i++) {

        int s = grid[0][0];
        bool good = true;
        for (int i=1; i<N; i++) {
            if (grid[i][0] <= s) {
                good = false;
                break;
            }
            if (grid[0][i] <= s) {
                good = false;
                break;
            }
        }
        if (good) {
            for (int i=0; i<N; i++) {
                for (int j=0; j<N; j++) {
                    printf("%d ", grid[j][i]);
                }
                printf("\n");
            }
            return 0;
        } else {
            for (int i=0; i<N; i++) {
                for (int j=0; j<N; j++) {
                    oldGrid[j][i] = grid[j][i];
                }
            }
            printf("\n");
            for (int i=0; i<N; i++) {
                for (int j=0; j<N; j++) {
                    grid[j][i] = oldGrid[N-i-1][j];
                }
            }
        }
    }
}