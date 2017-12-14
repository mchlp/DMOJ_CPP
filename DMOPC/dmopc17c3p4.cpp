#include <bits/stdc++.h>

using namespace std;

int main() {

    int N, Q;
    scanf("%d %d", &N, &Q);

    bool arr[N*2][N*2];
    memset (arr, true, N*2*N*2);

    while (Q--) {
        int type;
        scanf("%d ", &type);
        if (type == 1) {
            int col, row, v;
            scanf("%d %d %d", &row, &col, &v);
            int pos = ((row-1)*N) + (col-1);

            if (col == N && v != 2*N) {
                for (int i=0; i<2*N; i++) {
                    arr[2*N - 1][i] = false;
                }
                if (row == 1) {
                    arr[2*N - 1][2*N - 1] = true;
                } else {
                    arr[2*N - 1][N-1] = true;
                }
            }

            for (int i=1; i<(v-1); i++) {
                for (int j=pos; j<row*N; j++) {
                    arr[i][j] = false;
                }
            }
            for (int i=v; i<N*2; i++) {
                for (int j=(row-1)*N; j<pos; j++) {
                    arr[i][j] = false;
                }
            }
            for (int i=0; i<N*2; i++) {
                arr[v-1][i] = false;
                arr[i][pos] = false;
            }
            arr[v-1][pos] = true;
        } else {
            int v;
            scanf("%d", &v);
            int c = 0;
            for (int i=0; i<N*2; i++) {
                if (arr[v-1][i]) {
                    c++;
                }
            }
            printf("ARRAY\n");
            for (int i=0; i<N*2; i++) {
                for (int j=0; j<N*2; j++) {
                    printf("%d ", arr[i][j]);
                }
                printf("\n");
            }
            printf("%d\n", c);
        }
    }

    return 0;
}