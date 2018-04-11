#include<bits/stdc++.h>

using namespace std;

unordered_set<int> fib = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377};

int main() {
    int N;
    scanf("%d\n", &N);
    int fib1 = 1;
    int fib2 = 2;
    for (int i = 0; i < N; i++) {
        char c;
        scanf("%c", &c);
        if (fib.find(i + 1) != fib.end()) {
            if (c != 'A') {
                printf("Bruno, GO TO SLEEP\n");
                return 0;
            }
            int nfib = fib1 + fib2;
            fib1 = fib2;
            fib2 = nfib;
        } else if (c == 'A') {
            printf("Bruno, GO TO SLEEP\n");
            return 0;
        }
    }
    printf("That's quite the observation!\n");
    return 0;
}