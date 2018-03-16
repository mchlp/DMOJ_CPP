#include<bits/stdc++.h>

using namespace std;

int zero[400000];
int one[400000];
pair<int, int> pairs[400000];
string s;

int main() {
    memset(zero, -1, sizeof(zero));
    memset(one, -1, sizeof(one));
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    int z = 0;
    int o = 0;
    for (int i=0; i<s.length(); i++) {
        short c = s[i]-'0';
        pair<int, int> p;
        p.first = z;
        p.second = o;
        pairs[i] = p;
        if (c == 0) {
            z++;
            zero[z] = i;
        } else {
            o++;
            one[o] = i;
        }
    }

    int n;
    cin >> n;
    while (n--) {
        int x, y, z;
        cin >> x >> y >> z;
        x--;
        if (z == 0) {
            int num = pairs[x].first;
            int sec = zero[num+y];
            cout << (sec == -1 ? sec : sec +1);
        } else {
            int num = pairs[x].second;
            int sec = one[num+y];
            cout << (sec == -1 ? sec : sec +1);
        }
        cout << "\n";
    }
    return 0;
}