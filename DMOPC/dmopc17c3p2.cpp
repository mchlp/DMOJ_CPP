#include <bits/stdc++.h>

using namespace std;

int order[1000000];
int ordC = 0;
int arr[100000];

void flip(int num, int max) {
    if (num > 0) {
        arr[num - 1] = arr[num - 1] == 0 ? 1 : 0;
    }
    if (num < max-1) {
        arr[num + 1] = arr[num + 1] == 0 ? 1 : 0;
    }
    arr[num] = arr[num] == 0 ? 1 : 0;
    order[ordC] = num+1;
    ordC++;

/*
    printf("%d - ", num);
    for (int i=0; i<max; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");*/
}

int main() {
    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        int c;
        scanf("%d", &c);
        arr[i] = c;
    }
    do {

        for (int i=0; i<n-1; i++) {
            if (arr[i] == 1) {
                flip(i + 1, n);
            }
        }

        if (arr[n-1] == 1) {
            flip(0, n);
        }

    } while (arr[n-1] == 1);

    printf("%d\n", ordC);

    for (int i=0; i<ordC; i++) {
        printf("%d\n", order[i]);
    }
}