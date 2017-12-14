#include <bits/stdc++.h>

using namespace std;

int arr[100000];
int order[1000000];
int ordC = 0;
bool done;

bool flip(int n, int max);

bool check(int max) {
    bool fin = true;
    for (int i = 0; i < max; i++) {
        if (arr[i] == 1) {
            fin = false;
        }
    }
    return fin;
}

bool flip(int n, int max) {
    if (n > 0) {
        arr[n - 1] = arr[n - 1] == 0 ? 1 : 0;
    }
    if (n < max - 1) {
        arr[n + 1] = arr[n + 1] == 0 ? 1 : 0;
    }
    arr[n] = arr[n] == 0 ? 1 : 0;
    order[ordC] = n + 1;
    ordC++;

    bool c = check(max);
    /*
    for (int i = 0; i < max; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n %d \n", c);
     */

    return c;

}

bool findThree(int max) {
    bool fin = true;
    for (int i = 0; i < max; i++) {
        if (arr[i] == 1) {
            if (arr[i] == 1 && arr[i + 1] == 1 && arr[i + 2] == 1) {
                flip(i + 1, max);
            }
        }
    }
    return check(max);
}

void x(int n) {
    done = false;

    while (!done) {

        for (int i = 0; i < n; i++) {
            if (arr[i] == 1) {
                int j = i;
                while (j < n) {
                    if (flip(j, n)) {
                        return;
                    }
                    if (findThree(n)) {
                        return;
                    }
                    j++;
                }
            }
        }

        if (ordC >= 1000000) {
            return;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int c;
        scanf("%d", &c);
        arr[i] = c;
    }

    x(n);

    printf("%d\n", ordC);

    for (int i = 0; i < ordC; i++) {
        printf("%d\n", order[i]);
    }
}