#include<bits/stdc++.h>

using namespace std;

char ds[100001];

int main() {
    int N;
    scanf("%d\n", &N);
    while (N--) {
        string l;
        getline(cin, l);
        strcpy(ds, l.c_str());
        int s = 0;
        for(int i=0; i<strlen(ds); i++) {
            s += ds[i] - '0';
            while (s >= 10) {
                s = s % 10 + s / 10;
            }
        }
        printf("%d\n", s);
    }
    return 0;
}