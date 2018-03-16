#include<bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int b, p;
    char vc;
    bool v;
    cin >> b;
    cin >> p;
    cin >> vc;
    v = vc == 'Y';
    if (b/p >= 5) {
        if (v) {
            cout << "B" << endl;
        } else {
            cout << "A" << endl;
        }
    } else if (b/p >= 2) {
        if (v) {
            cout << "D" << endl;
        } else {
            cout << "C" << endl;
        }
    } else {
        cout << "NO PIZZA" << endl;
    }
    return 0;
}