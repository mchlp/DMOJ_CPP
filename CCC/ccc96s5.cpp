#include<bits/stdc++.h>

using namespace std;

int arr[2][100001];

int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        int num;
        scanf("%d", &num);
        for (int i = 0; i < num; i++) {
            scanf("%d", &arr[0][i]);
        }
        for (int i = 0; i < num; i++) {
            scanf("%d", &arr[1][i]);
        }
        int md = 0;
        for (int i = 0; i < num; i++) {
            int back = -1;
            for (int j = i+1; j < num; j++) {
                if (arr[1][j] >= arr[0][i]) {
                    back = j;
                } else {
                    break;
                }
            }
            if (back != -1) {
                md = max(abs(back - i), md);
            }
        }
        printf("The maximum distance is %d\n", md);
    }
    return 0;
}