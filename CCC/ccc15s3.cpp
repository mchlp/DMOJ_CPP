#include <bits/stdc++.h>

using namespace std;

bool gates[1000000];

int main() {

    memset(gates, false, sizeof(gates));
    int G, P;
    int L = 0;
    int m = INT_MAX;
    scanf("%d", &G);
    scanf("%d", &P);

    for(int i=0; i<P; i++) {
        int gate;
        scanf("%d", &gate);
        bool last = gate >= m;
        gate = min(gate, m);
        while (1) {
            if (!gates[gate]) {
                gates[gate] = true;
                if (last) {
                    m = gate - 1;
                }
                L++;
                break;
            }
            gate--;
            if (gate <= 0) {
                printf("%d", L);
                return 0;
            }
        }
    }
    printf("%d", P);
}