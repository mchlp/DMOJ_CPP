#include <bits/stdc++.h>

using namespace std;

vector<string> names;
vector<pair<string, int>> test;

int getSwaps(int ignore) {
    test.clear();
    int k = 0;
    for (int i=0; i<names.size(); i++) {
        if (i != ignore) {
            pair<string, int> c;
            c.first = names[i];
            c.second = k;
            test.push_back(c);
            k++;
        }
    }
    sort(test.begin(), test.end());
    //for (int i=0; i<test.size(); i++) {
     //   cout << test[i].first << " - " << test[i].second << "\n";
    //}
    vector<bool> vis(test.size(), false);
    int s = 0;
    for (int k=0; k<test.size(); k++) {
        if (vis[k] || test[k].second == k) {
            continue;
        } else {
            int cycSize = 0;
            int l = k;
            while(!vis[l]) {
                vis[l] = true;
                l = test[l].second;
                cycSize++;
            }
            s+=cycSize-1;
        }
    }
    //cout << ignore << ": " << s << "\n";
    return s;
};

int main() {

    freopen("DATA41.txt", "r", stdin);

    cin.sync_with_stdio(0);
    cin.tie(0);

    int N = 10;
    while (N--) {
        int n;
        cin >> n;
        names.clear();
        for (int i=0; i<n; i++) {
            string name;
            cin >> name;
            names.push_back(name);
        }
        int swaps = INT_MAX;
        for (int i=0; i<n; i++) {
            swaps = min(swaps, getSwaps(i));
        }
        cout << swaps << "\n";
    }
    return 0;
}