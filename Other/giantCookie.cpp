#include<bits/stdc++.h>

using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    if (x % y == 0) {
        cout << "yes " << x/y;
    } else {
        int t = y;
        while (x % t != 0) {
            t++;
        }
        cout << "no " << t-y;
    }
}