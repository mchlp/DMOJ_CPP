#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    n = n > 5 ? 10-n : n;
    cout << n/2 + 1;
}