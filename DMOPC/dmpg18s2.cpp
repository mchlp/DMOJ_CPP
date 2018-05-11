#include<bits/stdc++.h>

using namespace std;

long long arr[200001];

int main() {
    int N;
    cin >> N;
    cin >> arr[0];
    for (int i=1; i<N; i++) {
        int x;
        cin >> x;
        arr[i] = arr[i-1] + x;
    }
    long long s = arr[N-1];
    for (int i=1; i<N; i++) {
        cout << s << "\n";
        s += arr[N-i-1] - arr[i-1];
    }
    cout << arr[N-1] << "\n";
}