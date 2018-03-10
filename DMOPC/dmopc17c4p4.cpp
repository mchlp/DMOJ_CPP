#include <bits/stdc++.h>

using namespace std;

int days[1001];
bool wood[1001][1001];
int rob[1001];
bool d[1001];

int main() {
    memset(rob, 0, sizeof(rob));
    memset(wood, true, sizeof(wood));
    int N;
    scanf("%d", &N);

    for (int i=0; i<N; i++) {
        int b;
        scanf("%d", &b);
        days[i] = b;
        wood[b][i] = false;
    }

    bool done = false;
    bool change = true;
    bool first = true;
    while (!done) {
        if (!first) {
            change = false;
        }
        //printf("\n");
        done = true;
        int zeroCount = 0;
        for(int i=1; i<N+1; i++) {
            if (!d[i]) {
                //printf("%d\n", i);
                int rd = 0;
                int rday = 0;
                for (int j = 0; j < N+1; j++) {
                    done = false;
                    if (wood[i][j]) {
                        if (!change) {
                            wood[i][j] = false;
                            rob[j] = i;
                            d[i] = true;
                            change = true;
                            for (int k = 1; k < N + 1; k++) {
                                wood[k][j] = false;
                            }
                            continue;
                        }
                        rd++;
                        rday = j;
                    }
                }
                if (rd == 0) {
                    zeroCount++;
                }
            }
        }
/*
        for (int i=1; i<N+1; i++) {
            for (int j=0; j<N; j++) {
                printf("%2d", wood[i][j]);
            }
            printf("\n");
        }*/

        //printf("ZERO COUNT %d", zeroCount);
        if (zeroCount == 1) {
            break;
        } else if (zeroCount != 0) {
            printf("-1");
            return 0;
        }
        first = false;
    }


    for (int i=0; i<N; i++) {
        printf("%d ", rob[i]);
    }
}