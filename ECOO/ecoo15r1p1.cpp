#include<bits/stdc++.h>

using namespace std;

int main() {
    freopen("DATA12.txt", "r", stdin);
    int N = 10;
    while (N--) {
        int wood[8];
        memset(wood, 0, sizeof(wood));
        string c;
        while (true) {
            cin >> c;
            if (c == "red") {
                wood[7]++;
            } else if (c == "brown") {
                wood[1]++;
            } else if (c == "violet") {
                wood[2]++;
            } else if (c == "blue") {
                wood[3]++;
            } else if (c == "orange") {
                wood[4]++;
            } else if (c == "pink") {
                wood[5]++;
            } else if (c == "yellow") {
                wood[6]++;
            } else if (c == "green") {
                wood[0]++;
            } else {
                getline(cin, c);
                int time = 0;
                for (int i = 0; i < 7; i++) {
                    time += ceil(wood[i] / 7.0)*13;
                }
                time += wood[7] * 16;
                cout << time << endl;
                break;
            }
        }
    }
}