#include <bits/stdc++.h>

using namespace std;

int main() {
    char w[1000000];
    scanf("%1s", w);

    int t = 0;
    for (int i=0; i<strlen(w); i++) {
        char c = w[i];
        switch (c) {
            case '(':
                t++;
                break;
            case ')':
                t--;
                break;
        }
    }
    if (abs(t) <= 1) {
        printf("YES");
    } else {
        printf("NO");
    }
}