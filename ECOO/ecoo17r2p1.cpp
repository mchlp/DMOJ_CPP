#include <bits/stdc++.h>

using namespace std;

int main () {
    //freopen("DATA12.txt", "r", stdin);
    int N = 10;
    while (N--) {
        int rules[2][2];
        int w, h;
        cin >> w >> h;
        for (int y=0; y<4; y++) {
            char bc[2];
            char ac;
            cin >> bc >> ac;
            int b[2];
            int a;
            if (bc[0] == 'W') {
                b[0] = 1;
            } else {
                b[0] = 0;
            }
            if (bc[1] == 'W') {
                b[1] = 1;
            } else {
                b[1] = 0;
            }
            if (ac == 'W') {
                a = 1;
            } else {
                a = 0;
            }
            rules[b[0]][b[1]] = a;
        }
        char lastc[w];
        int last[w];
        cin >> lastc;
        for (int i=0; i<w; i++) {
            if (lastc[i] == 'W') {
                last[i] = 1;
            } else {
                last[i] = 0;
            }
        }

        for (int i=0; i<h-1; i++) {
            int above[w];
            for (int j=0; j<w; j++) {
                above[j] = rules[last[(j+w-1)%w]][last[(j+1)%w]];
            }
            for (int j=0; j<w; j++) {
                last[j] = above[j];
            }
        }
        for (int i=0; i<w; i++) {
            if (last[i]) {
                cout << 'W';
            } else {
                cout << 'G';
            }
        }
        cout << "\n";
        string x;
        cin >> x;
    }
    return 0;
}